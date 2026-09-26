#include "include/header.hpp"

int main(int argv, char **args) {
    string data;
    int query_data[2] {0};
    char *limits = "< =\">";
    vector<parse_tag_t> Data;

    scanf("%d %d", &query_data[0], &query_data[1]);
    cin.ignore();
    stock_data(Data, query_data[0], limits);
    for (int i = 0; i < query_data[1]; i += 1) {
        getline(cin, data);
        search_in_stock(Data, data);
    }
    return 0;
}
