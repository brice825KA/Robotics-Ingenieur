#include "../include/header.hpp"
#include <cstdlib>
#include <cstring>

vector<char *> parsing_data(string line, char *limits) {
    vector<char *> parsing;
    char *copy_line = strdup(line.c_str());
    char *buffer = NULL;

    buffer = strtok(copy_line, limits);
    for (int i = 0; buffer; i += 1) {
        parsing.emplace_back(strdup(buffer));
        buffer = strtok(NULL, limits);
    }
    free(copy_line);
    return parsing;
}
