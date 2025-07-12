#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tablo[256];
int satir1 = 8;
int sutun1 = 8;
int ects = 0;
int count = 0;

void move_direction(char hareket) {
    while (1) {
        if (hareket >= 65 && hareket <= 90) {
            hareket = hareket + 32;
        }

        if (tablo[sutun1 * 16 + satir1] != 'X') {
            tablo[sutun1 * 16 + satir1] = '.';
        }

        switch (hareket) {
            case 'w':
                if (sutun1 > 0) {
                    sutun1--;
                    if (tablo[sutun1 * 16 + satir1] == '1' || tablo[sutun1 * 16 + satir1] == '2') {
                        ects = ects + 8;
                    }
                    if (tablo[sutun1 * 16 + satir1] == '#') {
                    if (((sutun1 * 16 + satir1) > 67 && (sutun1 * 16 + satir1) < 77) || ((sutun1 * 16 + satir1) > 195 && (sutun1 * 16 + satir1) < 205) || (satir1==4 && sutun1>3 && sutun1<13) || (satir1==12 && sutun1>3 && sutun1<13)){
                            if (ects >= 56) {
                                sutun1--;
                                break;
                            } else {
                                printf("\n Gecemez!");
                                sutun1++;
                                break;
                            }
                        }
                        if (ects >= 32) {
                            sutun1--;
                        } else {
                            printf("\n Gecemez!");
                            sutun1++;
                        }
                    }
                }
                count++;
                break;
            case 's':
                if (sutun1 < 15) {
                    sutun1++;
                    if (tablo[sutun1 * 16 + satir1] == '1' || tablo[sutun1 * 16 + satir1] == '2') {
                        ects = ects + 8;
                    }
                    if (tablo[sutun1 * 16 + satir1] == '#') {
                    if (((sutun1 * 16 + satir1) > 67 && (sutun1 * 16 + satir1) < 77) || ((sutun1 * 16 + satir1) > 195 && (sutun1 * 16 + satir1) < 205) || (satir1==4 && sutun1>3 && sutun1<13) || (satir1==12 && sutun1>3 && sutun1<13)){
                            if (ects >= 56) {
                                sutun1++;
                                break;
                            } else {
                                printf("\n Gecemez!");
                                sutun1--;
                                break;
                            }
                        }
                        if (ects >= 32) {
                            sutun1++;
                        } else {
                            printf("\n Gecemez!");
                            sutun1--;
                        }
                    }
                }
                count++;
                break;
            case 'd':
                if (satir1 < 15) {
                    satir1++;
                    if (tablo[sutun1 * 16 + satir1] == '1' || tablo[sutun1 * 16 + satir1] == '2') {
                        ects = ects + 8;
                    }
                    if (tablo[sutun1 * 16 + satir1] == '#') {
                    if (((sutun1 * 16 + satir1) > 67 && (sutun1 * 16 + satir1) < 77) || ((sutun1 * 16 + satir1) > 195 && (sutun1 * 16 + satir1) < 205) || (satir1==4 && sutun1>3 && sutun1<13) || (satir1==12 && sutun1>3 && sutun1<13)){
                            if (ects >= 56) {
                                satir1++;
                                break;
                            } else {
                                printf("\n Gecemez!");
                                satir1--;
                                break;
                            }
                        }
                        if (ects >= 32) {
                            satir1++;
                        } else {
                            printf("\n Gecemez!");
                            satir1--;
                        }
                    }
                }
                count++;
                break;
            case 'a':
                if (satir1 > 0) {
                    satir1--;
                    if (tablo[sutun1 * 16 + satir1] == '1' || tablo[sutun1 * 16 + satir1] == '2') {
                        ects = ects + 8;
                    }
                    if (tablo[sutun1 * 16 + satir1] == '#') {
                      if (((sutun1 * 16 + satir1) > 67 && (sutun1 * 16 + satir1) < 77) || ((sutun1 * 16 + satir1) > 195 && (sutun1 * 16 + satir1) < 205) || (satir1==4 && sutun1>3 && sutun1<13) || (satir1==12 && sutun1>3 && sutun1<13)) {
                            if (ects >= 56) {
                                satir1--;
                                break;
                            } else {
                                printf("\n Gecemez!");
                                satir1++;
                                break;
                            }
                        }
                        if (ects >= 32 ) {
                            satir1--;
                        } else {
                            printf("\n Gecemez!");
                            satir1++;
                        }
                    }
                }
                count++;
                break;
            default:
                printf("Please enter the valid number\n");
        }
        if (tablo[sutun1 * 16 + satir1] == 'X') {
            tablo[sutun1 * 16 + satir1] = 'P';
            printboard(tablo, 256);
            printf("\nOyun bitti\n");
            printf("Number of movement = %d",count);
            printf("\n Toplam Ects = %d\n", ects);
            break;
        }
        tablo[sutun1 * 16 + satir1] = 'P';
        printboard(tablo, 256);
        printf("\n Toplam Ects = %d\n", ects);
        printf("\n Use WASD for move \n");
        scanf(" %c", &hareket);
    }
}

void printboard(char tablo[256], int size) {
    for (int i = 0; i < 256; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }
        printf("%c ", tablo[i]);
    }
}

void initialize_game() {
    int size = 4;
    int size1 = 3;

    srand((time(NULL)));

    for (int i = 0; i < 256; i++) {
        tablo[i] = '.';
    }

    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 16; i++) {
            if ((j > 3 && j < 13) && (i == 4 || i == 12)) {
                if (j == 4 || j == 12) {
                    while (i != 13) {
                        tablo[j * 16 + i] = '#';
                        i++;
                    }
                } else {
                    tablo[j * 16 + i] = '#';
                }
            } else if ((j > 5 && j < 11) && (i == 6 || i == 10)) {
                if (j == 6 || j == 10) {
                    while (i != 11) {
                        tablo[j * 16 + i] = '#';
                        i++;
                    }
                } else {
                    tablo[j * 16 + i] = '#';
                }
            } else if (i == 15 && j == 15) {
                tablo[255] = 'X';
            }
        }
    }

    while (size > 0) {
        int ran2 = rand() % 3 + 7;
        int ran1 = rand() % 3 + 7;
        if (tablo[ran1 * 16 + ran2] == 136) {
            continue;
        }
        tablo[ran1 * 16 + ran2] = '1';
        size--;
    }

   while(size1>0){
    int ran4 = rand() % 4;
     int ran3;
    if(ran4 == 0){
        ran3 =rand() % 7 + 5 ;
        tablo[ran3 *16 + 5] = '2';
        size1--;
    }
    if(ran4 == 1){
        ran3 =rand() % 7 + 5 ;
        tablo[ran3 *16 + 11] = '2';
         size1--;
    }

    if(ran4 == 2){
        ran3 =rand() % 7 + 5 ;
        tablo[ 5 *16 + ran3] = '2';
         size1--;
    }

    if(ran4 == 3){
        ran3 =rand() % 7 + 5 ;
        tablo[11 *16 + ran3] = '2';
         size1--;
    }

}



    tablo[sutun1 * 16 + satir1] = 'P';
    printboard(tablo, 256);
}

int main() {
    initialize_game();

    char hareket;
    printf("\n Use W(up),A(left),S(down),D(right) for move. \n");
    scanf(" %c", &hareket);
    move_direction(hareket);

    return 0;
}


