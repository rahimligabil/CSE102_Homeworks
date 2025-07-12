#include <stdio.h>
#include <stdlib.h>

void median(int arr[],int a,int b){
    int i;
    int j = 0;
    int c;
    int x = 0;
    float median;
    int temparr[100];
    int count = 0;
    int flag = 0;
    for(i=0;arr[i]!=-1;i++){
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = 1;
            }
        }
        if(flag==0 && (arr[i]>=a && arr[i]<=b)){
            temparr[x]=arr[i];
            x++;
        }
        flag = 0;
     }
    for (i = 0; i < x; ++i) 
        {
 
            for (j = i + 1; j < x; ++j)
            {
 
                if (temparr[i] > temparr[j]) 
                {
 
                    a =  temparr[i];
                    temparr[i] = temparr[j];
                    temparr[j] = a;
 
                }
 
            }
 
        }
     
     if(x%2==1){
         median = temparr[x/2];
         printf("\n Median of array =  %.2f ",median);
     }
     if(x%2==0){
          median = temparr[x/2] + temparr[(x/2)-1];
          median = median / 2;
         printf("\n Median of array =  %.2f ",median);
     }
      
}


void average(int arr2[],int a,int b){
    int i;
    float count = 0.0;
    float  sum = 0.0;
    float average = 0.0;
    for(i=0;arr2[i]!=-1;i++){
        if(arr2[i]>=a && arr2[i]<=b){
            sum = sum + arr2[i];
            count++;
        }
    }
    average = sum / count;
    
    printf("\nAverage of array =  %.2f",average);
}

void mode(int arr1[],int a,int b){
    int count = 0;
    int maxcount = 0;
    int mode;
    int freq[1000];
    for(int i=0;i<1000;i++){
        freq[i] = 0;
    }
    for (int i = 0; arr1[i] != -1; i++) {
        if(arr1[i]>a && arr1[i]<b){
           freq[arr1[i]]++; 
        }

        if (freq[arr1[i]] >= maxcount) {
            maxcount = freq[arr1[i]];
        }
    }
    printf("Modes of array = ");
  for(int i=0;i<1000;i++){
      if(freq[i]==maxcount){
          printf("%d ",i);
      }
  }
}
    

int find_size_of_array(int A[]){
    int i = 0;
    int size = 0;
    while(A[i] != -1){
        size++;
        i++;
    }
    return size;
}


void histogram(int A[],int min,int max,int maxrepeat){
    int i,j;

    int max1;
    max1 = maxrepeat;

    for(i=max1;i>0;i--){
        for(j=min;j<=max;j++){
            if(A[j]==max1){
                printf("*");
                A[j]--;

            }
            else{
            printf(" ");
        }
            
        }
        max1--;
        printf("\n");
    }
}

int maxx(int arr[], int size,int A,int B,int testarr[]){
    int i,j;
    int count = 0;
    int maxrepeat = 0;
      for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(arr[i]==arr[j]){
                count = count + 1;
            }

        }
        if(count>maxrepeat){
            maxrepeat = count; /* en cok tekrar sayini buluyor */

        }
        count = 0;

    }
    count = 0;
    for(j=A;j<=B;j++){
        for(i=0;i<size;i++){
            if(arr[i]==j){
                count++;
            }
        }
        testarr[j]=count; /* yeni arrayimizde kac sayidan kac tane oldugunu bastiriiyo */

        count = 0;
    }
    return maxrepeat;
    
}



int main()
{
    int number_array[] = { 
         45,  46,  47,  48,  49,  50,  133,  52,  53,  54,  55,  111,  57,  58,  59,  60, 
         61,  62,  63,  64,  65,  66,  55,  55,  69,  70,  55,  45,  73,  55,  75,  76,
         77,  78,  79,  80,  81,  82,  55,  55,  85,  86,  87,  88,  89,  90,  91,  92,
         93,  193, 95,   133,  76,  191,  55, 100, 101, 102, 76, 104, 105, 106, 107, 108,
        120, 110, 111, 112, 113, 114, 115, 116, 117, 118, 163, 120, 121, 122, 193, 124,
        125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
        141, 193, 133, 144, 145, 146, 147, 148, 149, 150, 151, 193, 153, 154, 155, 156,
        157, 158, 111, 160, 120, 162, 163, 128, 165, 166, 167, 168, 169, 170, 171, 172,
        173, 174, 175, 176, 177, 111, 179, 180, 181, 111, 120, 184, 133, 186, 187, 188,
        125, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 125, 201, 202, 203, 173,
        205,  61, 128, 173,  76, 111,133,45,-1};
    int A,B;
    int max = -1;
    int count = 0;
    int maxrepeat = 0;
    int i,j,b;
    int size,size1;
    int add;
    int count1 = 0;
    printf("Enter the A and B value:\n");
    scanf("%d %d",&A,&B);
    size = find_size_of_array(number_array);
    size1 = size + 5;
    int newarr[size1];
    int testarr[B];
    maxrepeat =  maxx(number_array,size,A,B,testarr);
    histogram(testarr,A,B,maxrepeat);   
    
      for(i=0;number_array[i]!=-1;i++){
     newarr[i] = number_array[i];
     }
     newarr[i] = -1; /* sonuna -1 ekliyo arragin bitdigi icin */
    printf("\n Do you want to add numbers?\n");
    scanf("%d",&b);
    if(b==1){
        for(i=0;i<5;i++){
            scanf("%d",&add);
            if(add == -1){
                break;
            }
            else{
                newarr[size + i] = add;
                newarr[size + i + 1] = -1;
                count1++;
            }
        }
        size1 = find_size_of_array(newarr);
        maxrepeat =  maxx(newarr,size1,A,B,testarr);
        histogram(testarr,A,B,maxrepeat); 
        mode(newarr,A,B);
        median(newarr,A,B);
    }
    if(b==0){
     mode(newarr,A,B);
     average(newarr,A,B);
     median(newarr,A,B);
    }
    
   


    return 0; 
}