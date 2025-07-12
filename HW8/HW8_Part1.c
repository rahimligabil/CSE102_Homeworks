#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_FIELDS 5
#define MAX_FIELD_LENGTH 50


 int stringtoint(char *str){
      int result = 0;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        }
            str++;
        }


    return result;
}


int main() {
   FILE *file = fopen("test1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

     int choose;
     int i,j,k;
    printf("MENU*\n");
    printf("1.Sort and display all individuals by age\n");
    printf("2.Sort and display all individuals in the branch by age\n");
    printf("3.Show individuals with the branch  'SCIENCE '\n");
    printf("4.Show computer scientist who are not mathameticians\n");
    printf("5.EXIT\n");
    printf("Choice:\n");

    char line[MAX_LINES][MAX_FIELDS][MAX_FIELD_LENGTH];
    int ages[MAX_LINES];
    int row = 0, col = 0;
    char c;

    while (fscanf(file, "%c", &c) == 1 && row < MAX_LINES) {
        if (c == '\n') {
            row++;
            col = 0;
            k = 0;
            continue;
        }
        if (c == ',') {
            col++;
            k = 0;
            continue;
        }

        if (c == ' ') {
            line[row][col][k] = c;
            k++;
            continue;
        }
        line[row][col][k] = c;
        k++;
    }

    fclose(file);
while(1){
   scanf("%d",&choose);
   if(choose == 1){
    for ( i = 0; i < row; i++) {
        ages[i] = stringtoint(line[i][2]);
    }

    for ( i = 0; i < row - 1; i++) {
        for ( j = i + 1; j < row; j++) {
            if (ages[i] > ages[j]) {
                int tempAge = ages[j];
                ages[j] = ages[i];
                ages[i] = tempAge;
                for (k = 0; k < MAX_FIELDS; k++) {
                    char temp[MAX_FIELD_LENGTH];
                    strcpy(temp, line[j][k]);
                    strcpy(line[j][k], line[i][k]);
                    strcpy(line[i][k], temp);
                }
            }
        }
    }
    printf(" Name                   Surname              Age                    Branch1               Branch2\n");
    for (i = 0; i < row; i++) {
    for (j = 0; j < MAX_FIELDS; j++) {
        printf(" %-20s ", line[i][j]);
    }
    printf("\n");
  }
}
  if(choose == 2){
  char temp[MAX_FIELD_LENGTH];
    for( i=0;i<row-1;i++){
        for( j=i+1;j<row;j++){
            if(strcmp(line[i][3],line[j][3])==0){
           if (stringtoint(line[i][2]) > stringtoint(line[j][2])){
            strcpy(temp, line[i][2]);
            strcpy(line[i][2], line[j][2]);
            strcpy(line[j][2], temp);

               for ( k = 0; k < MAX_FIELDS; k++) {
                    if(k==2){
                        continue;
                    }
                    strcpy(temp, line[j][k]);
                    strcpy(line[j][k], line[i][k]);
                    strcpy(line[i][k], temp);
            }
        }
    }
            if(strcmp(line[i][3],line[j][3]) > 0){
                strcpy(temp, line[i][3]);
                strcpy(line[i][3], line[j][3]);
                strcpy(line[j][3], temp);

                for ( k = 0; k < MAX_FIELDS; k++) {
                    if(k==3){
                        continue;
                    }
                    strcpy(temp, line[j][k]);
                    strcpy(line[j][k], line[i][k]);
                    strcpy(line[i][k], temp);
            }
        }
    }
  }
  printf(" Name                   Surname              Age                    Branch1               Branch2\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < MAX_FIELDS; j++) {
        printf(" %-20s ", line[i][j]);
    }
    printf("\n");
  }
}
if(choose == 3){
 for ( i = 0; i < row; i++) {
        for ( j = 0; j < MAX_FIELDS; j++) {
            if (strstr(line[i][j], "SCIENCE") != NULL) {
                for ( j = 0;  j < MAX_FIELDS; j++) {
                printf("%-22s", line[i][j]);
            }
            printf("\n");
            break;
        }
    }
 }
}
 if(choose == 4){
 for ( i = 0; i < row; i++) {
        for (j = 0; j < MAX_FIELDS; j++) {
            if (strstr(line[i][j], "COMPUTER SCIENCE") != NULL) {
                if((strcmp(line[i][4]," MATHEMATICS"))!= 0){
                for ( j = 0; j < MAX_FIELDS; j++) {

                printf("%-20s", line[i][j]);
            }
        }
            printf("\n");
            break;
        }
    }
  }
 }


if(choose == 5){
  printf("Exit the program.\n");
  break;

 }

} 
return 0;
}
