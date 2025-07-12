#include <stdio.h>


char_first_initial(FILE *file,int id){
    int x;
    char a;

file = fopen("second1.txt","r");

while(fscanf(file,"%d",&x)==1){
if(id==x){
    while(fscanf(file," %c",&a)==1){
    if(a==';'){
        continue;
    }
    else if(a ==' '){
        continue;
    }
    printf("%c",a);
    break;
    }
}
else{
    while (fscanf(file, "%c", &a) != EOF && a != '\n') {
        continue;
        }

    continue;
}
}
}

char_last_initial(FILE *file,int id){
   int x;
   char a;

file = fopen("second1.txt","r");

while(fscanf(file,"%d",&x)==1){
if(id==x){
    while(fscanf(file," %c",&a)==1){
    if(a==';'){
    continue;
    }
    while(a!=';'){
    fscanf(file," %c",&a);
    }
    fscanf(file," %c",&a);
    printf("%c",a);
    break;
    }
}
else{
    while (fscanf(file, "%c", &a) != EOF && a != '\n') {
    continue;
        }
    continue;
}
}
}


int get_id_fi(FILE *file, char first_initial) {
    int x;
    char a;
    file = fopen("second1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }


    while (fscanf(file, "%d %c", &x, &a) == 2) {

        if (a == ';') {
            fscanf(file, "%c", &a);
            if (first_initial == a){
                fclose(file);
                return x;
            }

           else {
            while (fscanf(file, "%c", &a) != EOF && a != '\n') {
                continue;
            }
            continue;
        }
        }
}
}


int ged_id_li(FILE *file,char last_initial){
int x;
char a;

 file = fopen("second1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }


    while (fscanf(file, "%d %c", &x, &a) == 2) {
    if(a==';'){
    fscanf(file," %c",&a);
    }
    while(a!=';'){
    fscanf(file," %c",&a);
    }
    fscanf(file," %c",&a);
    if(last_initial==a){
         fclose(file);
            return x;
    }
     else {
            while (fscanf(file, "%c", &a) != EOF && a != '\n') {
                continue;
            }
            continue;

}
    }



}


void average_grade(FILE *file, int id) {
    int x;
    char c;
    int mid1 = 0;
    int mid2 = 0;
    int final1 = 0;
    int average = 0;
    int midaverage = 0;
    int a = 0;
    int y  = 0;
    int z = 0;
    int flag = 0;
    int count1 = 1;
    int count = 1;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
 while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                mid1 = a;
                final1 = y;
                average = (mid1 + final1) / 2;
                if(count>0){
                    count = count - 1;
                }

                printf("%d\n", average); // Ortalama hesaplama
            }
            else {
                if(count1>0){
                    count1 = count1 - 1;
                }
                midaverage = (a + y) / 2; // Midlerin ortalamasını al
                average = (midaverage + z) / 2;
                printf("%d\n", average);
            }
            if(z==0){
                printf("Bu ogrenci degi\n");
            }

           while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;


    }
    fclose(file); // Dosyayı kapat
}


void class_average(FILE *file) {
    int x;
    char c;
    float mid1;
    int mid2 = 0;
    int final1 = 0;
    float average = 0.0;
    float average1 = 0.0;
    float testaverage = 0.0;
    int a;
    int  y;
    int z;
    float classaverage;
    float classaverage1;
    int flag = 0;
    float count1 = 0.0;
    float sum = 0.0;
    float sum1 = 0.0;
    int i = 0;
    float sum4 = 0.0;
    float sum5 = 0.0;
    int sum2 = 0;
    int sum3 = 0;
    float count = 0.0;
    int count2 = 1;
    int count3 = 1;
    float finalaverage ;
    float midaverage = 0.0;
    float midaverage1 = 0.0;
    float finalaverage1;
    int final2;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
 while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                mid1 = a / 2.0;
                final1 = y;
                average = (mid1 + final1) / 2;
                sum = sum + average;
                sum4 = sum4 + a;
                sum2 = sum2 + final1;
                count = count + 1.0;



              // Ortalama hesaplama
            }
            else {
                testaverage = (a + y) / 2.0; // Midlerin ortalamasını al
                average1 =  (testaverage + z) / 2;
                sum1 = sum1 + average1;
                sum3 = sum3 + z;
                sum5 = sum5 + testaverage;
                count1 = count1 + 1.0;

            }
            if(z==0){
                printf("Bu ogrenci degi\n");
            }


           while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;


    }

            classaverage = sum / count;
            classaverage1 = sum1 / count1;
             midaverage = sum4 / count;
            midaverage1 = sum5 / count1;
            finalaverage = sum2 / count;
            finalaverage1 = sum3 / count1;
    fclose(file); // Dosyayı kapat


    /*harf notunu bulan kisim,yukarisi ortalamayi buluyo*/

     file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }

     while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                mid1 = a / 2;
                final2 = y;
                average = (mid1 + final2) / 2;
                while(i>1){
                printf("for class 108\n");
                i++;
                }
                if((mid1<40 && mid1<midaverage) && (final2 < 40 && final2<finalaverage)){
                    printf("FAIL\n");
                }
                else if((mid1>40 && mid1<midaverage) && (final2 > 40 && final2<finalaverage)){
                    printf("PASS WITH D\n");
                }
                else if((mid1>40 && mid1>midaverage) && (final2>40 && final2>finalaverage)){
                    printf("PASS WITH C\n");
                }
                else if((mid1<90 && mid1>midaverage) && (final2<90 && final2>finalaverage)){
                    printf("PASS WITH B\n");
                }

                else if(mid1>=90 && final2>=90 ){
                    printf("PASS WITH A\n");
                }

            }



            else {
                final1 = z;
                testaverage = (a + y) / 2.0;
                average1 =  (testaverage + final1) / 2.0;
                 for(i=0;i<1;i++){
                printf("for class 102\n");
                }

                if((testaverage<40 && testaverage<midaverage1) && (final1<40 && final1<finalaverage1)){
                    printf("FAIL\n");
                }
                 if((testaverage>40 && testaverage<midaverage1) && (final1>40 && final1<finalaverage1)){
                    printf("PASS WITH D\n");
                }
                 if((testaverage>40 && testaverage>midaverage1) && (final1>40 && final1>finalaverage1)){
                    printf("PASS WITH C\n");
                }
                 if((testaverage<90 && testaverage>midaverage1) && (final1<90 && final1>finalaverage)){
                    printf("PASS WITH B\n");
                }

                 if(mid1>=90 && final1>=90){
                    printf("PASS WITH A\n");
                }

            }




            if(z==0){
                printf("Bu ogrenci degi\n");
            }

           while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;
}


    fclose(file);
}



void specific_id(FILE *file, char c){ /*menudeki n fonksiyonu */


      int x;
    char cc;
    float mid1;
    int mid2 = 0;
    int final1 = 0;
    float average = 0.0;
    float average1 = 0.0;
    float testaverage = 0.0;
    int a;
    int  y;
    int z;
    float classaverage;
    float classaverage1;
    int flag = 0;
    float count1 = 0.0;
    float sum = 0.0;
    float sum1 = 0.0;
    float sum4 = 0.0;
    float sum5 = 0.0;
    int sum2 = 0;
    int sum3 = 0;
    float count = 0.0;
    int count2 = 1;
    int count3 = 1;
    float finalaverage ;
    float midaverage = 0.0;
    float midaverage1 = 0.0;
    float finalaverage1;
    int final2;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
 while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                 mid1 = a / 2.0;
                final1 = y;
                average = (mid1 + final1) / 2;
                sum = sum + average;
                sum4 = sum4 + a;
                sum2 = sum2 + final1;
                count = count + 1.0;



              // Ortalama hesaplama
            }
            else {
                testaverage = (a + y) / 2.0; // Midlerin ortalamasını al
                average1 =  (testaverage + z) / 2;
                sum1 = sum1 + average1;
                sum3 = sum3 + z;
                sum5 = sum5 + testaverage;
                count1 = count1 + 1.0;

            }
            if(z==0){
                printf("Bu ogrenci degi\n");
            }


           while (fscanf(file, "%c", &cc) != EOF && cc != '\n') {
                continue;
            }
            continue;


    }
            classaverage = sum / count;
            classaverage1 = sum1 / count1;
             midaverage = sum4 / count;
            midaverage1 = sum5 / count1;
            finalaverage = sum2 / count;
            finalaverage1 = sum3 / count1;
    fclose(file); // Dosyayı kapat

 int b;
 int id;






    char aa;
    file = fopen("second1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }


    while (fscanf(file, "%d %c", &x, &aa) == 2) {

        if (aa == ';') {
            fscanf(file, "%c", &aa);
            if (c == aa){
                fclose(file);
                id =  x;
            }
               else {
            while (fscanf(file, "%c", &aa) != EOF && aa != '\n') {
                continue;
            }
            continue;
        }
        }



}

  file = fopen("first1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }

 while (fscanf(file, "%d;%d;%d;%d", &x,&b,&y,&z) == 4) {// Tek bir satırı oku
        if(x==id){
            if (z == 108) {
               mid1 = a / 2.0;
                final2 = y;
                average = (mid1 + final2) / 2;
                printf("for class 108\n");
                if((mid1<40 && mid1<midaverage) && (final2 < 40 && final2<finalaverage)){
                    printf("FAIL\n");
                }
                else if((mid1>40 && mid1<midaverage) && (final2 > 40 && final2<finalaverage)){
                    printf("PASS WITH D\n");
                }
                else if((mid1>40 && mid1>midaverage) && (final2>40 && final2>finalaverage)){
                    printf("PASS WITH C\n");
                }
                else if((mid1<90 && mid1>midaverage) && (final2<90 && final2>finalaverage)){
                    printf("PASS WITH B\n");
                }

                else if(mid1>=90 && final2>=90 ){
                    printf("PASS WITH A\n");
                }
                 // Ortalama hesaplama
            }
            else{

               final1 = z;
                testaverage = (b + y) / 2.0;
                average1 =  (testaverage + final1) / 2.0;
                printf("%f\n",average1);

                if((testaverage<40 && testaverage<midaverage1) && (final1<40 && final1<finalaverage1)){
                    printf("FAIL\n");
                }
                 if((testaverage>40 && testaverage<midaverage1) && (final1>40 && final1<finalaverage1)){
                    printf("PASS WITH D\n");
                    break;
                }
                 if((testaverage>40 && testaverage>midaverage1) && (final1>40 && final1>finalaverage1)){
                    printf("PASS WITH C\n");
                    break;
                }
                 if((testaverage<90 && testaverage>midaverage1) && (final1<90 && final1>finalaverage)){
                    printf("PASS WITH B\n");
                }

                 if(mid1>=90 && final1>=90){
                    printf("PASS WITH A\n");
                }


            }
        }
        else{

              while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;


        }


}
}

void specific_id1(FILE *file){ /*menudeki g fonksiyonu */


      int x;
    char cc;
    float mid1;
    int mid2 = 0;
    int final1 = 0;
    float average = 0.0;
    float average1 = 0.0;
    float testaverage = 0.0;
    int a;
    int  y;
    int z;
    float classaverage;
    float classaverage1;
    int flag = 0;
    float count1 = 0.0;
    float sum = 0.0;
    float sum1 = 0.0;
    float sum4 = 0.0;
    float sum5 = 0.0;
    int sum2 = 0;
    int sum3 = 0;
    float count = 0.0;
    int count2 = 1;
    int count3 = 1;
    float finalaverage ;
    float midaverage = 0.0;
    float midaverage1 = 0.0;
    float finalaverage1;
    int final2;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
 while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                 mid1 = a / 2.0;
                final1 = y;
                average = (mid1 + final1) / 2;
                sum = sum + average;
                sum4 = sum4 + a;
                sum2 = sum2 + final1;
                count = count + 1.0;



              // Ortalama hesaplama
            }
            else {
                testaverage = (a + y) / 2.0; // Midlerin ortalamasını al
                average1 =  (testaverage + z) / 2;
                sum1 = sum1 + average1;
                sum3 = sum3 + z;
                sum5 = sum5 + testaverage;
                count1 = count1 + 1.0;

            }
            if(z==0){
                printf("Bu ogrenci degi\n");
            }


           while (fscanf(file, "%c", &cc) != EOF && cc != '\n') {
                continue;
            }
            continue;


    }
            classaverage = sum / count;
            classaverage1 = sum1 / count1;
             midaverage = sum4 / count;
            midaverage1 = sum5 / count1;
            finalaverage = sum2 / count;
            finalaverage1 = sum3 / count1;
    fclose(file); // Dosyayı kapat

 int b;
 int id;


 scanf("%d",&id);

    char aa;
    file = fopen("second1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }


    while (fscanf(file, "%d %c", &x, &aa) == 2) {

        if (id==x) {
                id =  x;
            }
               else {
            while (fscanf(file, "%c", &aa) != EOF && aa != '\n') {
                continue;
            }
            continue;
        }
        }

  file = fopen("first1.txt","r");

    if (file == NULL) {
        printf("Dosya açýlamadý.");
        return 1;
    }

 while (fscanf(file, "%d;%d;%d;%d", &x,&b,&y,&z) == 4) {// Tek bir satırı oku
        if(x==id){
            if (z == 108) {
               mid1 = b / 2.0;
                final2 = y;
                average = (mid1 + final2) / 2;
                printf("for class 108\n");
                if((mid1<40 && mid1<midaverage) && (final2 < 40 && final2<finalaverage)){
                    printf("FAIL\n");
                }
                else if((mid1>40 && mid1<midaverage) && (final2 > 40 && final2<finalaverage)){
                    printf("PASS WITH D\n");
                }
                else if((mid1>40 && mid1>midaverage) && (final2>40 && final2>finalaverage)){
                    printf("PASS WITH C\n");
                }
                else if((mid1<90 && mid1>midaverage) && (final2<90 && final2>finalaverage)){
                    printf("PASS WITH B\n");
                }

                else if(mid1>=90 && final2>=90 ){
                    printf("PASS WITH A\n");
                }
                 // Ortalama hesaplama
            }
            else{

               final1 = z;
                testaverage = (b + y) / 2.0;
                average1 =  (testaverage + final1) / 2.0;
                printf("%f\n",average1);

                if((testaverage<40 && testaverage<midaverage1) && (final1<40 && final1<finalaverage1)){
                    printf("FAIL\n");
                }
                 if((testaverage>40 && testaverage<midaverage1) && (final1>40 && final1<finalaverage1)){
                    printf("PASS WITH D\n");
                    break;
                }
                 if((testaverage>40 && testaverage>midaverage1) && (final1>40 && final1>finalaverage1)){
                    printf("PASS WITH C\n");
                    break;
                }
                 if((testaverage<90 && testaverage>midaverage1) && (final1<90 && final1>finalaverage)){
                    printf("PASS WITH B\n");
                }

                 if(mid1>=90 && final1>=90){
                    printf("PASS WITH A\n");
                }


            }
        }
        else{

              while (fscanf(file, "%c", &cc) != EOF && cc != '\n') {
                continue;
            }
            continue;


        }


}
}




void menu_c(FILE *file){
int x;
    char c;
    int mid1;
    int mid2 = 0;
    int final1 = 0;
    float average = 0.0;
    float average1 = 0.0;
    float testaverage = 0.0;
    int a;
    int  y;
    int z;
    float classaverage;
    float classaverage1;
    int flag = 0;
    float count1 = 0.0;
    float sum = 0.0;
    float sum1 = 0.0;
    float sum4 = 0.0;
    float sum5 = 0.0;
    int sum2 = 0;
    int sum3 = 0;
    float count = 0.0;
    int count2 = 1;
    int count3 = 1;
    float finalaverage ;
    float midaverage = 0.0;
    float midaverage1 = 0.0;
    float finalaverage1;
    int final2;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
 while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (z == 108) {
                mid1 = a / 2.0;
                final1 = y;
                average = (mid1 + final1) / 2;
                sum = sum + average;
                sum4 = sum4 + a;
                sum2 = sum2 + final1;
                count = count + 1.0;



              // Ortalama hesaplama
            }
            else {
                testaverage = (a + y) / 2.0; // Midlerin ortalamasını al
                average1 =  (testaverage + z) / 2;
                sum1 = sum1 + average1;
                sum3 = sum3 + z;
                sum5 = sum5 + testaverage;
                count1 = count1 + 1.0;

            }
            if(z==0){
                printf("Bu ogrenci degi\n");
            }


           while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;


    }

            classaverage = sum / count;
            classaverage1 = sum1 / count1;
             midaverage = sum4 / count;
            midaverage1 = sum5 / count1;
            finalaverage = sum2 / count;
            finalaverage1 = sum3 / count1;

    fclose(file); // Dosyayı kapat


    /*harf notunu bulan kisim,yukarisi ortalamayi buluyo*/

     file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
    int ch;
    scanf("%d",&ch);

     while (fscanf(file, "%d;%d;%d;%d", &x,&a,&y,&z) == 4) {// Tek bir satırı oku
            if (ch==z) {
                mid1 = a ;
                final2 = y;
                average = (mid1 + final2) / 2;

                if((mid1<40 && mid1<midaverage) && (final2 < 40 && final2<finalaverage)){
                    printf("FAIL\n");
                }
                 if((mid1>40 && mid1<midaverage) && (final2 > 40 && final2<finalaverage)){
                    printf("PASS WITH D\n");
                }
                 if((mid1>40 && mid1>midaverage) && (final2>40 && final2>finalaverage)){
                    printf("PASS WITH C\n");
                }
                 if((mid1<90 && mid1>midaverage) && (final2<90 && final2>finalaverage)){
                    printf("PASS WITH B\n");
                }

                if(mid1>=90 && final2>=90 ){
                    printf("PASS WITH A\n");
                }

            }



            else if(ch!=108){
                if(z==108){
                    break;
                }
                final1 = z;
                testaverage = (a + y) / 2.0;
                average1 =  (testaverage + final1) / 2.0;
                printf("%d %f %f %d %f %d \n",final1,midaverage1,finalaverage1,y,testaverage,a);


                if((testaverage < 40 && testaverage<midaverage1) && (final1 < 40 && final1<finalaverage1)){
                    printf("FAIL\n");
                }
                else if((testaverage > 40 && testaverage<midaverage1) && (final1 > 40 && final1<finalaverage1)){
                    printf("PASS WITH D\n");
                }
                else if((testaverage>40 && testaverage>midaverage1) && (final1>40 && final1>finalaverage1)){
                    printf("PASS WITH C\n");
                }
                else if((testaverage<90 && testaverage>midaverage1) && (final1<90 && final1>finalaverage)){
                    printf("PASS WITH B\n");
                }

               else  if(mid1>=90 && final1>=90){
                    printf("PASS WITH A\n");
                }

            }




            if(z==0){
                printf("Bu ogrenci degi\n");
            }

           while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;
}


    fclose(file);



}

void menu_t(FILE *file){
    int id;
    int a,b,c;
    char x;

     file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
    printf("id giriniz:\n");
    scanf("%d",&id);
    while(fscanf(file,"%d;%d;%d",&a,&b,&c)){
        if(id == a){
            printf("# of classes = %d\n",b);
        }
        else{
                while (fscanf(file, "%c", &x) != EOF && x != '\n') {
                continue;
            }
            continue;

        }
    }




}



void menu_d(FILE *file){
    char a,b,c;
    int x,y;
    int count = 0;
    char role;
    scanf("%c",&role);


    file = fopen("second1.txt","r");
     if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }
    while(fscanf(file,"%d %c",&x,&a)==2){
        if(a==';'){
            count++;
            while(count<3){
                fscanf(file,"%c",&a);
                if(a==';'){
                    count++;
                }
                else{
                    continue;
                }
            }

        }
            if(count==3){
            fscanf(file,"%c",&a);
            count = 0;
            if(role==a){
                    while(a!=';'){
                        fscanf(file,"%c",&a);
                    }
                fscanf(file,"%d",&y);
                printf("id = %d and depart = %d\n",x,y);
            }
            else{
                  while (fscanf(file, "%c", &a) != EOF && a != '\n') {
                continue;
            }
            continue;
            }
        }
        else{
            while (fscanf(file, "%c", &a) != EOF && a != '\n') {
                continue;
            }
            continue;
        }

    }
}



void menu_l(FILE *file,int id){
int x;
int a;
char c;
int count = 0;

 file = fopen("first1.txt", "r");

    if (file == NULL) {
        printf("Dosya açılamadı:\n");
        return;
    }

    while(fscanf(file,"%d",&x)){
        if(id==x){
                while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                    if(c==';'){
                        count++;
                    }
                continue;
            }
            if(count==4){
                printf("%d and 102",x);
                break;
            }
            if(count==3){
                    printf("%d and 108",x);
            break;

            }
            else{
                printf("ogrenci degil\n");
                break;
            }



        }
        else{
            while (fscanf(file, "%c", &c) != EOF && c != '\n') {
                continue;
            }
            continue;
        }
    }





}





int main(){


    int x;
    char c;
    int mid1 = 0;
    int mid2 = 0;
    int final1 = 0;
    int average = 0;
    int midaverage = 0;
    int a = 0;
    int y = 0;
    int z = 0;
    int id;
    char role;
    int flag = 0;
    int count = 1;
    int count1 = 1;
    FILE *file;
    char choose;

    while(1){
        printf("\nLutfen seciniz\n");
        scanf("%c",&choose);

        switch(choose){
    case 'p':
        class_average(file);
        break;
    case 'n':
        scanf("%c",&c);
        specific_id(file,c);
        break;

    case 'g':
        specific_id1(file);
        break;

    case 'c':
         menu_c(file);
         break;

    case 't':
        menu_t(file);
        break;

    case 'd':
        menu_d(file);
        break;

    case 'l':
        scanf("%d",&id);
         menu_l(file,id);
         break;


    case 'e':
        break;


        }

    }



}























