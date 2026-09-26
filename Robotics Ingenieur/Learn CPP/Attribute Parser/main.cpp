#include "include/header.hpp"
#include <vector>

typedef struct parse_tag_s {
    char *name_tag;
    vector<char **>table;
} parse_tag_t;

vector<char *> parsing_data(string line, char *limits) {
    vector<char *> parsing;
    char *copy_line = strdup(line.c_str());
    char *buffer = NULL;

    buffer = strtok(copy_line, limits);
    for (int i = 0; buffer; i += 1) {
        parsing.emplace_back(buffer);
        buffer = strtok(NULL, limits);
    }
    return parsing;
}

void stock_data(vector<parse_tag_t>&data, int query, char *limits) {
    string d;
    vector<char *> parsing;
    parse_tag_t parse;
    char *stock[2];
    for (int i = 0; i <= query; i += 1) {
        cin.ignore();
        getline(cin, d);
        parsing = parsing_data(d, limits);
        parse.name_tag = strdup(parsing[0]);
        
    }   
}

int main(int argv, char **args) {
    string data;
    int query_data[2] {0};
    char *limits = "< =\"\>";
    vector<parse_tag_t> Data;

    scanf("%d %d", &query_data[0], &query_data[1]);
    stock_data(Data, query_data[0], limits);
    return 0;
}
