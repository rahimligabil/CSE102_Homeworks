#include <stdio.h>
#include <string.h>


void search_p1(char symbol[][35], int num_rows, int matches[][2], int *num_matches) {
    int i, j;

    char str[] = "***++++***++++***";
    int size = strlen(str);
    int k = 0;
    int a;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < 35; j++) {
            if (symbol[i][j] == str[k]) {
                a = j;
                k++;
                while (size != k) {
                    a++;
                    if (symbol[i][a] == str[k]) {
                        k++;
                    }
                    else {
                        k = 0;
                        break;
                    }
                }
                if (size == k) {
                    matches[*num_matches][0] = i + 1;
                    matches[*num_matches][1] = j + 1;
                    (*num_matches)++;
                    k = 0;
                }
            }
            else if (symbol[i][j] != str[k]){
                k = 0;
            }
        }
    }
       printf("Eslesmeler:\n");
    for ( i = 0; i < *num_matches; i++) {
        printf("P1 @(%d, %d)\n", matches[i][0], matches[i][1]);
    }

}


void search_p2(char symbol[][35], int num_rows,
int matches[][2], int * num_matches){
    int i, j;
    char str[] = "+*+*+";
    int size = strlen(str);
    int k = 0;
    int a;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < 35; j++){
                if(symbol[i][j]==str[k]){
                    a = i;
                    k++;
                    while(size != k){
                        a++;
                        if(symbol[a][j]==str[k]){
                            k++;
                        }
                        else {
                        k = 0;
                        break;
                    }

                    }
                    if (size == k) {
                    matches[*num_matches][0] = i + 1;
                    matches[*num_matches][1] = j + 1;
                    (*num_matches)++;
                    k = 0;
                }

                }

                  else if (symbol[i][j] != str[k]){
                k = 0;
            }



        }
    }
    for ( i = 0; i < *num_matches; i++) {
        printf("P2 @(%d, %d)\n", matches[i][0], matches[i][1]);
    }

}

void search_p3(char symbol[][35], int num_rows,
int matches[][2], int * num_matches){
    int i, j;
    char str[] = "+++++";
    int size = strlen(str);
    int k = 0;
    int a,b;

     for (i = 0; i < num_rows; i++) {
        for (j = 0; j < 35; j++){
                if(symbol[i][j]==str[k]){
                    a = i;
                    b = j;
                    k++;
                    while(size != k){
                        a++;
                        b++;
                        if(symbol[a][b]==str[k]){
                            k++;
                        }
                        else {
                        k = 0;
                        break;
                    }

                    }
                    if (size == k) {
                    matches[*num_matches][0] = i + 1;
                    matches[*num_matches][1] = j + 1;
                    (*num_matches)++;
                    k = 0;
                }

                }

                  else if (symbol[i][j] != str[k]){
                k = 0;
            }



        }
    }
    for ( i = 0; i < *num_matches; i++) {
        printf("P3 @(%d, %d)\n", matches[i][0], matches[i][1]);
    }
}


int main() {
   FILE *file = fopen("test2.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

     int choose;
     int i,j,k;
     char symbol[5][35];
     char a;
     int satir = 0;
     int sutun = 0;
     int n = 0;
     int matches[35][2];
while(fscanf(file,"%c",&a)==1){
    if(a == '\n'){
        symbol[satir][sutun] = '\0';
        satir++;
        sutun = 0;
    continue;
    }

    symbol[satir][sutun] = a;
    sutun++;
}

for(i=0;i<5;i++){
    for(j=0;j<34;j++){
        printf("%c",symbol[i][j]);
    }
    printf("\n");
}
search_p1(symbol,5,matches,&n);
n = 0;
search_p2(symbol,5,matches,&n);
n = 0;
search_p3(symbol,5,matches,&n);



return 0;
}
