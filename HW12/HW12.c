#include "customDict.h"

struct CustomDict* create_dict() {
    struct CustomDict* dict = (struct CustomDict*)malloc(sizeof(struct CustomDict));
    dict->capacity = 0;
    dict->size = 0;
    dict->items = NULL;
    return dict;
}



int calculate_new_capacity(int current_capacity) {
    if (current_capacity == 0) return 1;
    return current_capacity * 2;
}



void add_item(struct CustomDict* dict, char* key, union Value* values, int value_count, char* type) {
    if (dict->size == dict->capacity) {
        int new_capacity = calculate_new_capacity(dict->capacity);
        dict->items = (struct Item*)realloc(dict->items, new_capacity * sizeof(struct Item));
        dict->capacity = new_capacity;
    }

    struct Item* newItem = &dict->items[dict->size];
    newItem->key = (char*)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(newItem->key, key);

    newItem->values = (union Value*)malloc(value_count * sizeof(union Value));
    memcpy(newItem->values, values, value_count * sizeof(union Value));
    newItem->value_count = value_count;

    newItem->dtype = (char*)malloc((strlen(type) + 1) * sizeof(char));
    strcpy(newItem->dtype, type);

    dict->size++;
}




void delete_item(struct CustomDict* dict, char* key) {
     char tempKey[256];
     int i,j;
    snprintf(tempKey, sizeof(tempKey), " %s", key);

    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key,tempKey) == 0) {
            free(dict->items[i].key);
            free(dict->items[i].values);
            free(dict->items[i].dtype);
            for(j = i ;j<dict->size - 1;j++){
            dict->items[j] = dict->items[j + 1];
            }
            dict->size--;
            return;
        }
    }
}


void set_value(struct CustomDict* dict, char* key, union Value* values, int value_count, char* type) {
    char tempKey[256];
    int i;
    snprintf(tempKey, sizeof(tempKey), " %s", key); 

    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, tempKey) == 0) {
            free(dict->items[i].values); 
            dict->items[i].values = (union Value*)malloc(value_count * sizeof(union Value));
            memcpy(dict->items[i].values, values, value_count * sizeof(union Value));
            dict->items[i].value_count = value_count;

            free(dict->items[i].dtype);

           
            dict->items[i].dtype = (char*)malloc((strlen(type) + 1) * sizeof(char)); 
            if (dict->items[i].dtype != NULL) {
                strcpy(dict->items[i].dtype, type); 
            }
            return;
        }
    }
    add_item(dict, key, values, value_count, type); 
}

union Value* search_item(struct CustomDict* dict, char* key) {
    char tempKey[256];
     int i,j;
    snprintf(tempKey, sizeof(tempKey), " %s", key);
    for ( i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, tempKey) == 0) {
            return dict->items[i].values;
        }
    }
    return NULL;
}


void sort_dict(struct CustomDict* dict) {
    int i,j;
    for ( i = 0; i < dict->size - 1; i++) {
        for (j = i + 1; j < dict->size; j++) {
            if (strcmp(dict->items[i].key, dict->items[j].key) > 0) {
                struct Item temp = dict->items[i];
                dict->items[i] = dict->items[j];
                dict->items[j] = temp;
            }
        }
    }
}


void print_dict(struct CustomDict *dict) {
    int i,j;
    if (!dict) return;
    for (i = 0; i < dict->size; i++) {
        printf("%s:", dict->items[i].key);
        for ( j = 0; j < dict->items[i].value_count; j++) {
            printf(" ");
            if (strcmp(dict->items[i].dtype, "int") == 0) {
                printf("%d", dict->items[i].values[j].intValue);
            } else if (strcmp(dict->items[i].dtype, "float") == 0) {
                printf("%.2f", dict->items[i].values[j].floatValue);
            } else if (strcmp(dict->items[i].dtype, "double") == 0) {
                printf("%.2lf", dict->items[i].values[j].doubleValue);
            } else if (strcmp(dict->items[i].dtype, "char") == 0) {
                printf("%c", dict->items[i].values[j].charValue);
            } else {
                printf("Unknown");
            }
        }
        printf("\n");
    }
}


void free_dict(struct CustomDict *dict) {
    int i;
    if (!dict) return;
    for ( i = 0; i < dict->size; i++) {
        free(dict->items[i].key);
        free(dict->items[i].values);
        free(dict->items[i].dtype);
    }
    free(dict->items);
    free(dict);
}

int read_csv(struct CustomDict *dict,  char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {

        char *type_str = strtok(line, ",");
        char *key = strtok(NULL, ",");

        union Value values[1024];
        size_t value_count = 0;

        char *token;
        while ((token = strtok(NULL, ",")) != NULL) {
            if (strncmp(type_str, "int", 3) == 0) {
                values[value_count++].intValue = atoi(token);
            } else if (strncmp(type_str, "float", 5) == 0) {
                values[value_count++].floatValue = atof(token);
            } else if (strncmp(type_str, "double", 6) == 0) {
                values[value_count++].doubleValue = atof(token);
            } else if (strncmp(type_str, "char", 4) == 0){
                values[value_count++].charValue = token[1];
            }
        }
        add_item(dict, key, values, value_count, type_str);
    }

    fclose(file);
    return 1;
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Delete Item\n");
    printf("2. Set Value\n");
    printf("3. Search Item\n");
    printf("4. Sort Dictionary\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}





int main() {
    struct CustomDict* dict = create_dict();

    if (read_csv(dict, "data.csv")) {
    } else {
        printf("Failed to read CSV file.\n");
    }

    int choice;
    char key[256];
    char type[10];
    union Value values[1024];
    int value_count;
    char filename[256];
    int i,j;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to delete: ");
            scanf("%s", key);
            delete_item(dict, key);
            printf("Item deleted.\n");
        } else if (choice == 2) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter type (int, float, double, char): ");
            scanf("%s", type); 
            printf("Enter number of values: ");
            scanf("%d", &value_count);
            for ( i = 0; i < value_count; i++) {
                printf("Enter value %d: ", i + 1);
                if (strcmp(type, "int") == 0) {
                    scanf("%d", &values[i].intValue);
                } else if (strcmp(type, "float") == 0) {
                    scanf("%f", &values[i].floatValue);
                } else if (strcmp(type, "double") == 0) {
                    scanf("%lf", &values[i].doubleValue);
                } else if (strcmp(type, "char") == 0) {
                    scanf(" %c", &values[i].charValue);
                } else {
                    printf("Invalid type.\n");
                    i--;
                }
            }
            set_value(dict, key, values, value_count, type);
            printf("Value set.\n");
        } else if (choice == 3) {
            printf("Enter key to search: ");
            scanf("%s", key);
            char tempKey[256];
            int i,j;
            snprintf(tempKey, sizeof(tempKey), " %s", key);
            union Value* found_values = search_item(dict, key);
            if (found_values) {
                printf("Values for key %s: ", key);
    for ( j = 0; j < dict->size; j++) {
        if (strcmp(dict->items[j].key, tempKey) == 0) {

                for ( i = 0; i < dict->items[j].value_count; i++) {
                    if (strcmp(dict->items[j].dtype, "int") == 0) {
                        printf("%d ", found_values[i].intValue);
                    } else if (strcmp(dict->items[j].dtype, "float") == 0) {
                        printf("%.2f ", found_values[i].floatValue);
                    } else if (strcmp(dict->items[j].dtype, "double") == 0) {
                        printf("%.2lf ", found_values[i].doubleValue);
                    } else if (strcmp(dict->items[j].dtype, "char") == 0) {
                        printf("%c ", found_values[i].charValue);
                    } else {
                        printf("Unknown ");
                    }
                }
        }

            }
            printf("\n");
            } else {
                printf("Key not found.\n");
            }
        }
         else if (choice == 4) {
            sort_dict(dict);
            printf("Dictionary sorted.\n");
        }  
            
         else if (choice == 5) {
            free_dict(dict);
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        print_dict(dict);
    }

    free_dict(dict);
    return 0;
}
