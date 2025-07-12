#include <stdio.h>
#include <stdlib.h>

struct botanist {
    int cordx;
    int cordy;
    int numberofbottle;
};

struct forest {
    char map[50][50];
    int width;
    int height;
    int flower_x[50];
    int flower_y[50];
};

void initgame(struct forest *s2, struct botanist *s1) {
    int i = 0;
    int j = 0;
    char c;
    FILE *file;
    file = fopen("init.txt", "r");
    fscanf(file, "%d,%d\n", &s2->width, &s2->height);
    fscanf(file, "%d,%d,%d\n", &s1->cordx, &s1->cordy, &s1->numberofbottle);

    while (fscanf(file, "%c", &c) == 1) { /* karakterleri tek tek okuyo */
        if (c == ',') {  /*virgul gorunce atliyor */
            continue;
        }
        if (c == '\n') {
            i++;
            j = 0;
            continue;
        }
        s2->map[i][j] = c;
        j++;
    }
    for (i = 0; i < s2->height; i++) {
        for (j = 0; j < s2->width; j++) {
            printf(" %c ", s2->map[i][j]);
        }
        printf("\n");
    }
}

void displayforest(struct forest *s2, struct botanist *s1,int num) {
    int number;
    int i, j;
    for (i = 0; i < s2->height; i++) {
        for (j = 0; j < s2->width; j++) {
            printf(" %c ", s2->map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Botanist cordinates: %d %d\n", s1->cordx, s1->cordy);
    printf("Flower numbers = %d\n",num);
}
void search(struct forest *s2, struct botanist *s1,int *n,int bottle) {
    int i, j;
    char ch;
    int x, y;
    int a = 0;
    int flowernum;
    printf("\nW A S D tuslarindan birine basiniz\n");
    scanf(" %c", &ch);
    if(ch >= 65 && ch <= 90){ /* buyuk karakter girilirse ascii degerine 32 ekleyerek kucuk karakter yapiyo */
    ch = ch + 32;
    }

    for (i = 0; i < s2->height; i++) {
        for (j = 0; j < s2->width; j++) {
            if (s2->map[i][j] == 'B') {
                s1->cordx = i;
                s1->cordy = j;
            }
        }
    }


    if (ch == 'w') {
        if((s1->cordx - 1) < 0){
            printf("Gecemez.\n");
        }
       else if (s2->map[s1->cordx - 1][s1->cordy] == 'X') {
        if(*n==1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx - 1][s1->cordy] = 'B';
        s1->numberofbottle--;
        (*n)--;
        flowernum = bottle - *n;
        displayforest(s2, s1,bottle);
        printf("I've found it.\n");
        printf("Oyun bitti!\n");
        return;
        }
        if(*n > 1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx - 1][s1->cordy] = 'B';
        s1->numberofbottle--;
        (*n)--;
        printf("I've found it.\n");
        }
    }

       else if(s2->map[s1->cordx - 1][s1->cordy] == 'T'){
            printf("Warning!\n");
        }
        else{
        s2->map[s1->cordx - 1][s1->cordy] = s2->map[s1->cordx][s1->cordy];
        s2->map[s1->cordx][s1->cordy] = ' ';
        s1->cordx--;
        }
    }
    if (ch == 'd') {
            if((s1->cordy + 1) > s2->width - 1){
            printf("Gecemez.\n");
        }
      else  if (s2->map[s1->cordx][s1->cordy + 1] == 'X') {
        if(*n==1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx][s1->cordy + 1] = 'B';
        s1->numberofbottle--;
        (*n)--;
        flowernum = bottle - *n;
        displayforest(s2, s1,bottle);
        printf("I've found it.\n");
        printf("Oyun bitti!\n");
        return;
        }
        if(*n > 1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx][s1->cordy + 1] = 'B';
        s1->numberofbottle--;
        (*n)--;
        printf("I've found it.\n");
        }
    }
        else if(s2->map[s1->cordx][s1->cordy + 1] == 'T'){
          printf("Warning!\n");
        }
        else{
        s2->map[s1->cordx][s1->cordy + 1] = s2->map[s1->cordx][s1->cordy];
        s2->map[s1->cordx][s1->cordy] = ' ';
        s1->cordy++;
        }
    }
    if (ch == 's') {
         if((s1->cordx + 1) > s2->height - 1){
            printf("Gecemez.\n");
        }
       else if (s2->map[s1->cordx + 1][s1->cordy] == 'X') {
         if(*n ==1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx + 1][s1->cordy] = 'B';
        s1->numberofbottle--;
        (*n)--;
        flowernum = bottle - *n;
        displayforest(s2, s1,bottle);
        printf("I've found it.\n");
        printf("Oyun bitti!\n");
        return;
        }
        if(*n > 1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx + 1][s1->cordy] = 'B';
        s1->numberofbottle--;
        (*n)--;
        printf("I've found it.\n");
        }
    }
        else if(s2->map[s1->cordx + 1][s1->cordy] == 'T'){ /* t lerin uzerinden gecmek isterse izin vermiyo ve warning yazdiiriyor*/
            printf("Warning!\n");
        }
        else{
        s2->map[s1->cordx + 1][s1->cordy] = s2->map[s1->cordx][s1->cordy];
        s2->map[s1->cordx][s1->cordy] = ' ';
        s1->cordx++;
        }
    }
    if (ch == 'a') {
         if((s1->cordy - 1) < 0){
            printf("Gecemez.\n");
        }
        else if (s2->map[s1->cordx][s1->cordy - 1] == 'X') {
        if(*n==1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx][s1->cordy - 1] = 'B';
        s1->numberofbottle--;
        (*n)--;  /*when finds the flower decrase the flower numbers */
        flowernum = bottle - *n;
        displayforest(s2, s1,bottle);
        printf("I've found it.\n");
        printf("Oyun bitti!\n");
        return;
        }
        else if(*n > 1){
        s2->map[s1->cordx][s1->cordy] = ' ';
        s2->map[s1->cordx][s1->cordy - 1] = 'B';
        s1->numberofbottle--;
        (*n)--;
        printf("I've found it.\n");
        }
    }
        else if(s2->map[s1->cordx][s1->cordy - 1] == 'T'){
            printf("Warning!\n");
        }
        else {
        s2->map[s1->cordx][s1->cordy - 1] = s2->map[s1->cordx][s1->cordy];
        s2->map[s1->cordx][s1->cordy] = ' ';
        s1->cordy--;
        }
    }
    flowernum = bottle - *n;
    displayforest(s2, s1,flowernum);
    search(s2,s1,n,bottle);
}



int main() {
    struct botanist s1;
    struct forest s2;
    int n = 0;
    int i,j;
    int a = 0;
    initgame(&s2, &s1);
      for (i = 0; i < s2.height; i++) {
        for (j = 0; j < s2.width; j++) {
            if (s2.map[i][j] == 'X') {
                n++;
                s2.flower_x[a] = i;
                s2.flower_y[a] = j;
                a++;
            }
        }
    }
    int bottle = n;
    search(&s2, &s1,&n,bottle);
    FILE *file = fopen("last.txt","w"); /* tablonun son halini bastirmak icin yeni bir txt file */
        if (file == NULL) {
        perror("Error opening file");
    	}
    	for(i = 0; i < s2.height ;i++)
    	{
    		for(j = 0; j < s2.width ; j++)
    		{
    			fprintf(file,"%c",s2.map[i][j]);
    			if(j != 9)
    				fprintf(file,"%c",',');
    		}
    		fprintf(file,"%c",'\n');
    	}
    
    return 0;
}

