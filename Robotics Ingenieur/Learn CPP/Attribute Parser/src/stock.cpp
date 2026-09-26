#include "../include/header.hpp"

void stock_data(vector<parse_tag_t>&data, int query, char *limits) {
    string d;
    vector<char *> parsing;
    parse_tag_t parse;

    for (int i = 0; i < query; i += 1) {
        getline(cin, d);
        parsing = parsing_data(d, limits);
        if (parsing[0][0] == '/' || parsing.empty()) {
            for (char *ptr : parsing) free(ptr);
            continue;
        }
        parse.name_tag = (parsing[0]);
        parse.table = parsing;
        data.emplace_back(parse);
    }   
}
