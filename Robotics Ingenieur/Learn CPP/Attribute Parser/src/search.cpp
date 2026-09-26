#include "../include/header.hpp"
#include <cstdio>
#include <cstdlib>

int search_in_stock(vector<parse_tag_t> data, string request) {
    vector<char *> parse = parsing_data(request, ".~");

    if (parse.size() < 2) { // Une requête valide nécessite au moins un tag et un attribut
        printf("Not Found!\n");
        for (char *ptr : parse) free(ptr);
        return 1;
    }

    // Réassembler la hiérarchie demandée par la requête (ex: "tag1.tag2")
    string requested_path = "";
    for (size_t i = 0; i < parse.size() - 1; i += 1) {
        requested_path += parse[i];
        if (i < parse.size() - 2) requested_path += ".";
    }
    
    char *attr_target = parse.back(); // Le dernier élément est l'attribut

    for (int i = 0; i < data.size(); i += 1) {
        // Comparaison avec le chemin absolu reconstruit
        if (strcmp(requested_path.c_str(), data[i].name_tag) == 0) {
            // Recherche de l'attribut dans la table
            for (int j = 1; j < data[i].table.size(); j += 1) {
                if (strcmp(attr_target, data[i].table[j]) == 0) {
                    if (j + 1 < data[i].table.size()) {
                        cout << data[i].table[j + 1] << endl;
                        for (char *ptr : parse) free(ptr);
                        return 0;
                    }
                }
            }
        }
    }

    for (char *ptr : parse) free(ptr);
    printf("Not Found!\n");
    return 1;
}
