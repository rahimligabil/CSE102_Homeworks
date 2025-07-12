#include <stdio.h>
#include <string.h>

#define TOTAL_HOSPITALS 4
#define NUM_CITIES 4
#define LOCATION 6


typedef struct card{
const char* face;
const char* suits;

}card;

typedef struct {
    char *name;
    char cities[NUM_CITIES];
} Hospital;


int countPaths(int x, int y) {
    if (x == 1 && y == 1) {
        return 1;
    }
    if (x == 1 || y == 1) {
        return 1;
    }
    return countPaths(x - 1, y) + countPaths(x, y - 1);
}

char cities[LOCATION] = {'A', 'B', 'C', 'D', 'E', 'F'};

int citiescovered(char *result) {
int i;
    for (i = 0; i < LOCATION; i++) {
        if (strchr(result, cities[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}


void findcities(int index, char *result, int selectedHospitals[], int num, Hospital hospitals[], int *find, int max) {
    int i,j;
    if (*find == 1) return;

    if (num > max) { /* eger sectigi hastane sayisi maxi gecerse return ediyor */
        return;
    }

    if (index == TOTAL_HOSPITALS) {
        if (citiescovered(result)) {
            printf("Hospitals: ");
            for ( i = 0; i < num; i++) {
                printf("\n%s ", hospitals[selectedHospitals[i]].name);
                for( j=0;j<4;j++){
                    if(strcmp(hospitals[selectedHospitals[i]].name,hospitals[j].name)==0){
                        char k;
                        int n = 0;
                        while( hospitals[i].cities[n]!= '\0'){
                            printf("%c",hospitals[i].cities[n]);
                            n++;
                        }
                    }
                }
            }
            printf("\n");
            *find = 1;
        }
        return;
    }

    findcities(index + 1, result, selectedHospitals, num, hospitals, find, max);

    char temp[100];
    strcpy(temp, result);

    for ( i = 0; i < NUM_CITIES; i++) {
        if (hospitals[index].cities[i] != '\0') {
            strncat(temp, &hospitals[index].cities[i], 1);
        }
    }
    selectedHospitals[num] = index;
    findcities(index + 1, temp, selectedHospitals, num + 1, hospitals, find, max);
}

int main() {


    printf("*****MENU*****\n");
    printf("1.Smart City Navigation\n");
    printf("2.Sustainable Health Services\n");
    printf("3.Virtual Card Game\n");
    printf("4.Exit\n");
    int choose;


    Hospital hospitals[TOTAL_HOSPITALS] = {
        {"hospital1", {'A', 'B', 'C','\0'}},
        {"hospital2", {'A', 'C', 'D','\0'}},
        {"hospital3", {'B', 'F', '\0'}},
        {"hospital4", {'C', 'E', 'F','\0'}}
    };
        int max;
card cards[52];
 const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
 const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
 int i,j;
 int random;
 int num = 0;
 srand(time(NULL));


    while(1){
    printf("\nEnter your choice\n");
    scanf("%d",&choose);
    if(choose==1){
    int x,y;
    printf("Enter the street number\n");
    scanf("%d",&x);
     printf("Street number %d\n",x);
     printf("Enter the avenue number\n");
     scanf("%d",&y);
     printf("Avenue number %d\n",y);
     if(x > 5 || y > 5){
    printf("Please enter the valid numbers!!\n");
    printf("\nEnter the street number\n");
    scanf("%d",&x);
     printf("Street number %d\n",x);
     printf("Enter the avenue number\n");
     scanf("%d",&y);
     printf("Avenue number %d\n",y);
     }

    int numberOfPaths = countPaths(x,y);
    printf("Number of optimal paths to back home: %d\n", numberOfPaths);
        }
        if(choose==2){
            printf("Enter the maximum hospital number yo constructed: ");
    scanf("%d", &max);

    if (max > TOTAL_HOSPITALS) {
        printf("Maksimum hastane sayisi asildi.\n");
    }

    char result[100] = "";
    int selectedHospitals[TOTAL_HOSPITALS] = {0};
    int find = 0;
    findcities(0, result, selectedHospitals, 0, hospitals, &find, max);

    if (find==0) {
        printf("NO Some cities are not covered.\n");
    }
        }
        if(choose==3){
             for(i=0;i<4;i++){
    for(j=0;j<13;j++){
        cards[num].face = faces[j];
        cards[num].suits = suits[i];
        num++;
    }
 }

  for ( i = 0; i < 52; i++) {
        random = rand() % 52;
        card temp = cards[i];
        cards[i] = cards[random];
        cards[random] = temp;
  }

 for(i=0;i<26;i++){
    printf("%s of %-10s   %s of %s\n",cards[i].face,cards[i].suits,cards[i+24].face,cards[i+24].suits);
 }
        }
        if(choose==4){
            printf("Exit\n");
            break;
        }


    }

    return 0;
}
