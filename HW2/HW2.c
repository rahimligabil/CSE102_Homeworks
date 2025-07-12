
#include <stdio.h>

int main() {
    FILE *file;
    int x,y,z;
    int max = -1;
    int min = 100000;
    int min1 = 100000;
    int max1 = -1;
    int max2 = -1;
    int max3 = -1;
    int min2 = 10000;
    int min3 = 10000;
    int choose;
    int maxX,maxY;


    printf("1.Explore the data.\n");
    printf("2.Train model.\n");
    printf("3.Test model.\n");
    printf("4.Exit.\n");

    printf("Please seleect from the menu:");
    while(scanf("%d",&choose) == 1){


   if(choose == 1){
   file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }


    while (fscanf(file, "%d %d %d", &x, &y, &z) == 3) {
            if(z == 0){
            if(x>max){
                max = x;
            }
            if(y > max1){
                max1 = y;
            }
            if(x < min){
                min = x;
            }
            if(y < min1){
            min1 = y;
            }}
            else{
                if(x > max2){
                max2 = x;
                }
            if(y > max3){
                max3 = y;
            }
              if(x < min2){
                min2 = x;
            }
            if(y < min3){
            min3 = y;
            }
            }
            if(max2>max){
            maxX = max2;
            }
            else{
            maxX = max;
            }


    }
    printf(" class 0 : X in [%d %d], Y in [%d %d]  \n ",max,min,max1,min1);
    printf("class 1 : X in [%d %d], Y in [%d %d]\n ",max2,min2,max3,min3);


    fclose(file);

   }


    int suc;
    int count = 0;
    int dx,dy;
    int minerror;
    minerror = 10000;
    int i;
    int r1,r2,r3,r4;
    int error;
    error = 0;
    int sep,sep2;
    int label1,label2,label3,label4;
    int class;
    if(choose == 2){
    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }


    while (fscanf(file, "%d %d %d", &x, &y, &z) == 3) {
            if(z == 0){
            if(x>max){
                max = x;
            }
            if(y > max1){
                max1 = y;
            }
            if(x < min){
                min = x;
            }
            if(y < min1){
            min1 = y;
            }}
            else{
                if(x > max2){
                max2 = x;
                }
            if(y > max3){
                max3 = y;
            }
              if(x < min2){
                min2 = x;
            }
            if(y < min3){
            min3 = y;
            }
            }
            if(max2>max){
            maxX = max2;
            }
            else{
            maxX = max;
            }
            if(max1>max3){
            maxY = max1;
            }
            else{
            maxY = max3;
            }


    }


    fclose(file);

    file = fopen("data.txt", "r");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    for(r1=0;r1<2;r1++){
        for(r2=0;r2<2;r2++){
            for(r3=0;r3<2;r3++){
                for(r4=0;r4<2;r4++){
        for(x=1;x<=maxX;x++){
        for(y=0;y<=maxY;y++){
        fclose(file);

    file = fopen("data.txt", "r");
     while (fscanf(file, "%d %d %d", &dx, &dy, &z) == 3){

        if(dx<=x && dy>y){
        if(r1==z){
                r1 = z;
        }
        else{
                error = error + 1;


        }
    }
      if(dx>x && dy>y){
        if(r2==z){
                r2 = z;
        }
        else{
                error = error + 1;

        }
    }
      if(dx<=x && dy<=y){
        if(r3==z){
                r3 = z;
        }
        else{
                error = error + 1;

        }
    }
      if(dx >= x && dy <= y){
        if(r4==z){
             r4 = z;
        }
        else{
                error = error + 1;


        }

    }

    }
     if(error < minerror){
        minerror = error;
        sep = x;
        sep2 = y;
        label1 = r1;
        label2 = r2;
        label3 = r3;
        label4 = r4;

    }
    error = 0;

     }

     }
    }
            }
        }
    }
            printf(" Seperators: %d %d \n",sep,sep2);
    printf(" Labels of the regions: r1 = %d,r2 = %d,r3 = %d,r4 = %d \n",label1,label2,label3,label4);

    printf(" Minerror = %d\n",minerror);

    fclose(file);
    error = 0;
    x = sep;
    y = sep2;

    }

     if(choose == 3){
     file = fopen("data.txt", "r");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    for(r1=0;r1<2;r1++){
        for(r2=0;r2<2;r2++){
            for(r3=0;r3<2;r3++){
                for(r4=0;r4<2;r4++){
        for(x=1;x<=49;x++){
        for(y=0;y<=49;y++){
        fclose(file);
        file = fopen("data.txt", "r");
     while (fscanf(file, "%d %d %d", &dx, &dy, &z) == 3){

        if(dx<=x && dy>y){
        if(r1==z){
                r1 = z;
        }
        else{
                error = error + 1;


        }
    }
      if(dx>x && dy>y){
        if(r2==z){
                r2 = z;
        }
        else{
                error = error + 1;

        }
    }
      if(dx<=x && dy<=y){
        if(r3==z){
                r3 = z;
        }
        else{
                error = error + 1;

        }
    }
      if(dx >= x && dy <= y){
        if(r4==z){
             r4 = z;
        }
        else{
                error = error + 1;


        }

    }

    }
     if(error < minerror){
        minerror = error;
        sep = x;
        sep2 = y;
        label1 = r1;
        label2 = r2;
        label3 = r3;
        label4 = r4;

    }
    error = 0;

     }

     }
    }
            }
        }

    }
    fclose(file);
    error = 0;
    x = sep;
     y = sep2;
     file = fopen("test1.txt", "r");
     while (fscanf(file, "%d %d %d", &dx, &dy, &z) == 3){
	count = count + 1;
        if(dx<=x && dy>y){
        if(label1==z){
                continue;
        }
        else{
                error = error + 1;


        }
    }
      if(dx>x && dy>y){
        if(label2==z){
                continue;
        }
        else{
                error = error + 1;

        }
    }
      if(dx<=x && dy<=y){
        if(label3==z){
                continue;
        }
        else{
                error = error + 1;

        }
    }
      if(dx >= x && dy <= y){
        if(label4==z){
             continue;
        }
        else{
                error = error + 1;


        }

    }
    }
    suc = ((count-error)*100) / 12 ;
    fclose(file);




    printf(" Minerror = %d\n",minerror);
    printf(" success rate  = %d\n",suc);


     file = fopen("testfinal.txt", "r");
     while (fscanf(file, "%d %d", &dx, &dy) == 2){

        if(dx<=x && dy>y){
         class = label1;
        }
      if(dx>x && dy>y){
         class = label2;
    }
      if(dx<=x && dy<=y){
        class = label3;
    }
      if(dx >= x && dy <= y){
         class = label4;
    }

    printf("X=%d and Y=%d cordinates,predicted label = %d\n",dx,dy,class);
    continue;
     }
     }

     if(choose == 4){
        printf("Exit.\n");
        break;
     }

    }











    return 0;
}
