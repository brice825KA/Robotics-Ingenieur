#include "../include/header.hpp"
#include <cstdlib>

void stock_data(vector<parse_tag_t>& data, int query, char *limits) {
    string d;
    vector<char *> parsing;
    vector<string> current_path; // Permet de suivre l'imbrication actuelle

    for (int i = 0; i < query; i += 1) {
        getline(cin, d);
        parsing = parsing_data(d, limits);
        
        if (parsing.empty()) continue;

        // Si c'est une balise fermante (ex: </tag1>)
        if (parsing[0][0] == '/') {
            if (!current_path.empty()) {
                current_path.pop_back(); // On sort du tag actuel
            }
            for (char *ptr : parsing) free(ptr);
            continue;
        }

        // Ajouter le tag actuel à la hiérarchie imbriquée
        current_path.push_back(parsing[0]);

        // Construire le nom complet sous forme de chemin (ex: tag1.tag2)
        string full_path = "";
        for (size_t k = 0; k < current_path.size(); k++) {
            full_path += current_path[k];
            if (k < current_path.size() - 1) full_path += ".";
        }

        parse_tag_t parse;
        parse.name_tag = strdup(full_path.c_str()); // Stockage du chemin absolu du tag
        parse.table = parsing;
        data.emplace_back(parse);
    }   
}
