#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Species {
    char class1[50];
    char order[50];
    char family[50];
    char genus[50];
    char species[50];
    struct Species *next;
} Species;

void swap(Species *a, Species *b, char *criteria) {
    char temp[50];

    if (strcmp(criteria, "class") == 0) {
        strcpy(temp, a->class1);
        strcpy(a->class1, b->class1);
        strcpy(b->class1, temp);
    } else if (strcmp(criteria, "order") == 0) {
        strcpy(temp, a->order);
        strcpy(a->order, b->order);
        strcpy(b->order, temp);
    } else if (strcmp(criteria, "family") == 0) {
        strcpy(temp, a->family);
        strcpy(a->family, b->family);
        strcpy(b->family, temp);
    } else if (strcmp(criteria, "genus") == 0) {
        strcpy(temp, a->genus);
        strcpy(a->genus, b->genus);
        strcpy(b->genus, temp);
    } else if (strcmp(criteria, "species") == 0) {
        strcpy(temp, a->species);
        strcpy(a->species, b->species);
        strcpy(b->species, temp);
    }
}

int main() {
    Species *l;
    Species *head;
    head = malloc(sizeof(Species));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    l = head;
    char c;
    char criteria[20];
    int flag;

    while (1) {

        printf("Enter species information.\n");
        printf("Class: ");
        fgets(l->class1, sizeof(l->class1), stdin);
        l->class1[strlen(l->class1) - 1] = '\0';

        printf("Order: ");
        fgets(l->order, sizeof(l->order), stdin);
        l->order[strlen(l->order) - 1] = '\0';

        printf("Family: ");
        fgets(l->family, sizeof(l->family), stdin);
        l->family[strlen(l->family) - 1] = '\0';

        printf("Genus: ");
        fgets(l->genus, sizeof(l->genus), stdin);
        l->genus[strlen(l->genus) - 1] = '\0';

        printf("Species: ");
        fgets(l->species, sizeof(l->species), stdin);
        l->species[strlen(l->species) - 1] = '\0';

        printf("Do you want to continue or modify : ");
        scanf(" %c", &c);
        getchar();
        if(c == 'm' || c == 'M'){
            Species *temp;
            temp = head;
            char str[10];
            printf("Enter speicies information to modify:\n");
            printf("Old species\n");
            scanf("%s",str);
            getchar();
            while(temp->next != NULL){
                if(strcmp(str,temp->species) == 0){
                        printf("Enter new information.\n");
                        printf("New Class: ");
                        fgets(temp->class1, sizeof(temp->class1), stdin);
                        temp->class1[strlen(temp->class1) - 1] = '\0';

                        printf("New Order: ");
                        fgets(temp->order, sizeof(temp->order), stdin);
                        temp->order[strlen(temp->order) - 1] = '\0';

                        printf("New Family: ");
                        fgets(temp->family, sizeof(temp->family), stdin);
                        temp->family[strlen(temp->family) - 1] = '\0';

                        printf("New Genus: ");
                        fgets(temp->genus, sizeof(temp->genus), stdin);
                        temp->genus[strlen(temp->genus) - 1] = '\0';

                        printf("New Species: ");
                        fgets(temp->species, sizeof(temp->species), stdin);
                        temp->species[strlen(temp->species) - 1] = '\0';
                        printf("Species modified succesfuly \n");
                        printf("Class: %s\n",l->class1);
                        printf("Class: %s\n",l->order);
                        printf("Class: %s\n",l->family);
                        printf("Class: %s\n",l->genus);
                        printf("Class: %s\n",l->species);
                        break;

                }
                temp = temp->next;
            }

        }

       else  if (c == 'n' || c == 'N') {
            l->next = NULL;
            break;
        }
        l->next = malloc(sizeof(Species));
        if (l->next == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        l = l->next;
    }
    int ch;
    printf("1.Sort list\n");
    printf("2.Delete item from list:\n");
    scanf("%d",&ch);
    if(ch==1){
    printf("Enter list criteria (class, order, family, genus, species): ");
    scanf("%s", criteria);
    Species *lptr = NULL;

    do {
        flag = 0;
        l = head;
        while (l->next != lptr) {
            int cmp = 0;
            if (strcmp(criteria, "class") == 0) {
                cmp = strcmp(l->class1, l->next->class1);
            } else if (strcmp(criteria, "order") == 0) {
                cmp = strcmp(l->order, l->next->order);
            } else if (strcmp(criteria, "family") == 0) {
                cmp = strcmp(l->family, l->next->family);
            } else if (strcmp(criteria, "genus") == 0) {
                cmp = strcmp(l->genus, l->next->genus);
            } else if (strcmp(criteria, "species") == 0) {
                cmp = strcmp(l->species, l->next->species);
            }

            if (cmp > 0) {
                swap(l, l->next, criteria);
                flag = 1;
            }
            l = l->next;
        }
         lptr = l;
    } while (flag == 1);

    Species *current = head;

    printf("Listed species:\n");
    while (current != NULL) {
        printf("Class: %s\nOrder: %s\nFamily: %s\nGenus: %s\nSpecies: %s\n",current->class1, current->order, current->family, current->genus, current->species);
        current = current->next;
    }
}
if(ch==2){
    char str[10];
    Species *temp = head;
    Species *current;
    printf("Enter the species for delete\n");
    scanf("%s",str);
    getchar();

    while(temp != NULL){
        if(strcmp(str,temp->species)==0){
        break;
        }
        current = temp;
        temp = temp->next;

    }
    if(temp == head){
        head = temp->next;
    }
    else{
    current->next = temp->next;
    }
    free(temp);


Species *l1 = head;
while(l1!=NULL){
    printf("Class: %s\n",l1->class1);
    printf("Order: %s\n",l1->order);
    printf("Family: %s\n",l1->family);
    printf("Genus: %s\n",l1->genus);
    printf("Species: %s\n",l1->species);
    l1 = l1->next;
}

    }
      Species *current = head;
    current = head;
    Species *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
 }

    return 0;
}
