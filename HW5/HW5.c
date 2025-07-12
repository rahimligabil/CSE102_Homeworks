#include <stdio.h>

void magicnum(int number) {
    char c;
    FILE *dosya;
    int num;
    int count = 0;
    int calc1 = 0;
    int calc2 = 0;

    if (number == 1) {
        dosya = fopen("news1.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            if (c == '#') {
                fscanf(dosya, "%d", &num);
                count++;
                calc1 = (num * num * num) - (num * num) + 2;
                calc2 += (calc1 * calc1);
            }
        }
    } else if (number == 2) {
        dosya = fopen("news2.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            if (c == '#') {
                fscanf(dosya, "%d", &num);
                count++;
                calc1 = (num * num * num) - (num * num) + 2;
                calc2 += (calc1 * calc1);
            }
        }
    } else if (number == 3) {
        dosya = fopen("news3.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi: \n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            if (c == '#') {
                fscanf(dosya, "%d", &num);
                count++;
                calc1 = (num * num * num) - (num * num) + 2;
                calc2 += (calc1 * calc1);
            }
        }
    } else if (number == 4) {
        dosya = fopen("news4.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            if (c == '#') {
                fscanf(dosya, "%d", &num);
                count++;
                calc1 = (num * num * num) - (num * num) + 2;
                calc2 += (calc1 * calc1);
            }
        }
    }

    printf("The experiment key = %d\n", calc2);
    fclose(dosya);
}

int newsfile(int number) {
    char c;
    FILE *dosya;
    int test;
    int t;
    int flag1 = 1;

    if (number == 1) {
        dosya = fopen("news1.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            printf("%c", c);
        }
    } else if (number == 2) {
        dosya = fopen("news2.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            printf("%c", c);
        }
    } else if (number == 3) {
        dosya = fopen("news3.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi: \n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            printf("%c", c);
        }
    } else if (number == 4) {
        dosya = fopen("news4.txt", "r");
        if (dosya == NULL) {
            printf("Dosya acilamadi:\n");
        }
        while (fscanf(dosya, "%c", &c) == 1) {
            printf("%c", c);
        }
    }

    dosya = fopen("newsread.txt", "r");
    while (fscanf(dosya, "%d", &t) != EOF) {
        if (number == t) {
            flag1 = 0;
            break;
        }
    }
    fclose(dosya);

    if (flag1 == 1) {
        dosya = fopen("newsread.txt", "a");
        fprintf(dosya, "%d\n", number);
        fclose(dosya);
    }

}

int read(int secim) {
    int a;
    int test;
    int t;
    int flag = 1;
    int b;
    int news = 1;
    FILE *dosya;


    switch (secim) {
        case 1:
            dosya = fopen("newsread.txt", "r");
            while (fscanf(dosya, "%d", &test) != EOF) {
                if (test == 1) {
                    printf("do you want read?");
                    scanf("%d", &b);
                    if (b == 1) {
                        newsfile(secim);
                        news = 0;
                        break;
                    } else {
                       return 0;
                        break;
                    }
                }
            }
            if (news == 1) {
                newsfile(secim);
            }
            fclose(dosya);
            break;

        case 2:
            dosya = fopen("newsread.txt", "r");
            while (fscanf(dosya, "%d", &test) != EOF) {
                if (test == 2) {
                    printf("do you want read?");
                    scanf("%d", &b);
                    if (b == 1) {
                        newsfile(secim);
                        news = 0;
                        break;
                    } else if (b == 0) {
                       return 0;
                    }
                }
            }
            if (news == 1) {
                newsfile(secim);
            }
            fclose(dosya);
            break;

        case 3:
            dosya = fopen("newsread.txt", "r");
            while (fscanf(dosya, "%d", &test) != EOF) {
                if (test == 3) {
                    printf("do you want read?");
                    scanf("%d", &b);
                    if (b == 1) {
                        newsfile(secim);
                        news = 0;
                        break;
                    } else {
                        return 0;
                    }
                }
            }
            if (news == 1) {
                newsfile(secim);
            }
            fclose(dosya);
            break;

        case 4:
            dosya = fopen("newsread.txt", "r");
            while (fscanf(dosya, "%d", &test) != EOF) {
                if (test == 4) {
                    printf("do you want read?");
                    scanf("%d", &b);
                    if (b == 1) {
                        newsfile(secim);
                        news = 0;
                        break;
                    } else {
                       return 0;
                    }
                }
            }
            if (news == 1) {
                newsfile(secim);
            }
            fclose(dosya);
            break;

        default:
            printf("Gecersiz secim!\n");
            break;
    }
    return 1;
}

int menu() {
    char choose;
    int secim;
    int z;
    int a;
    int t;
    int flag = 0;

    printf("Daily Press\n");
    printf("Title of 1. news:Astronot Alper Gezeravci'nin Dunya'ya donusu ertelendi.\n");
    printf("Title of 2. news:Bakaacýr, Astronot Gezeravcý ile Videokonferans Görüþmesi Gerçeklestirdi.\n");
    printf("Title of 3. news:Alper Gezeravcý uzayda 9. deneyini yaptý.\n");
    printf("Title of 4. news: Astronotlarýn uzaydaki ilk sözleri\n");
    printf("What do you want to do?\n");
    printf("a.Read a new\n");
    printf("b.List the readed news\n");
    printf("c.Get decrypted information from news\n");
    scanf(" %c", &choose);

    switch (choose) {
        case 'b':
            printf("List of readed news:\n");
            FILE *dosya = fopen("newsread.txt", "r");
            int t;
            while (fscanf(dosya, "%d", &t) != EOF) {
                printf("%d news is readed\n", t);
            }
            fclose(dosya);
            break;

        case 'c':
            printf("Which news do you want:\n");
            scanf("%d", &secim);
            newsfile(secim);
            magicnum(secim);
            break;

        case 'a':
            printf("Which news do you want:\n");
            scanf("%d", &secim);
            t = read(secim);
            if(t==0){
		return 0; /* eger read fonskiyonun icinde haberi okumak istemezse sonlandirmak icin */
		}

            break;

        default:
            printf("Invalid option!\n");
            break;
    }
       printf("\n Do you want to continue?\n");
    scanf("%d", &a);
    if (a == 0) {
        return 0;
    } else if (a == 1) {
        menu();
    } else {
        printf("invalid character");
    }

}

int main() {
    menu();
    return 0;
}
