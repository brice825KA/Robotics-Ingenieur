#include "include/header.hpp"
#include <cstring>

vector<char *> parsing_data(string line, char *limits) {
    vector<char *> parsing;
    char *copy_line = strdup(line.c_str());
    char *buffer = NULL;

    buffer = strtok(copy_line, limits);
    for (int i = 0; buffer; i += 1) {
        printf("%s\n", buffer);
        parsing.emplace_back(buffer);
        buffer = strtok(NULL, limits);
    }
    return parsing;
}

int main(int argv, char **args) {
    string data;

    getline(cin, data);
    parsing_data(data, ";\tESC");
    return 0;
}
