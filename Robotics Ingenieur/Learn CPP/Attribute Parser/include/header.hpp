#ifndef _HEADER_HPP_
    #define _HEADER_HPP_

    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <string>
    #include <iostream>
    #include <cstring>
    using namespace std;

typedef struct parse_tag_s {
    char *name_tag;
    vector<char *>table;
} parse_tag_t;
    
vector<char *> parsing_data(string line, char *limits);
void stock_data(vector<parse_tag_t>&data, int query, char *limits);
int search_in_stock(vector<parse_tag_t> data, string request);

#endif