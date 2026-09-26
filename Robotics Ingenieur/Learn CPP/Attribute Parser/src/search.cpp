#include "../include/header.hpp"
#include <cstdio>

int search_in_stock(vector<parse_tag_t> data, string request) {
    vector<char *> parse = parsing_data(request, ".~");

    if (parse.empty()) {
        printf("Not Found!\n");
        return 1;
    }
    for (int i = 0; i < data.size(); i += 1) {
        if (strcmp(parse[0], data[i].name_tag) == 0) {
            for (int j = 1; j < data[i].table.size(); j+= 1) {
                if (strcmp(parse.back(),data[i].table[j]) == 0) {
                    if (j + 1 < data[i].table.size()) {
                        cout << data[i].table[j + 1] << endl;
                        for (char *ptr : parse) free(ptr);
                        return 0;
                    }
                }
            }
        }
    }
    for (char *ptr: parse) free(ptr);
    printf("Not Found!\n");
    return 1;
}
