#ifndef CUSTOMDICT_H
#define CUSTOMDICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


union Value {
    int intValue;
    float floatValue;
    double doubleValue;
    char charValue;
};

struct Item {
    char* key;
    union Value* values;
    int value_count;
    char* dtype;
};

struct CustomDict {
    struct Item* items;
    int capacity;
    int size;
};

struct CustomDict* create_dict();
void add_item(struct CustomDict* dict, char* key, union Value* values, int value_count, char* dtype);
void delete_item(struct CustomDict* dict, char* key);
void set_value(struct CustomDict* dict, char* key, union Value* values, int value_count, char* dtype);
union Value* search_item(struct CustomDict* dict, char* key);
void sort_dict(struct CustomDict* dict);
void print_dict(struct CustomDict* dict);
void free_dict(struct CustomDict* dict);
int read_csv(struct CustomDict* dict, char* filename);

#endif 
