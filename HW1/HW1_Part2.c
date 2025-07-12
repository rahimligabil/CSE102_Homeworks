#include <stdio.h>
int main(){
char c;
int count,comment;
int key0 = 0;
int key = 0;
char id[] = "230104004902";
count = 0;
char a[61] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','(','<','=','+',')','[','*','/',']','{','>','!','-','}','?','\\','&','|','%','_',';','"','#','.','\'','0','1','2','3','4','5','6','7','8','9'};
int i;
for(i=0;i<12;i++){
key0 = key0 + id[i];
}
while(key0 != 0){
key = key + (key0 % 10);
key0 = key0 / 10;
}
while(scanf("%c",&c) == 1){
if(c == '@'){
scanf("%d",&comment);
comment = comment - 77;
printf("/* The comment line is %d  character */",comment);
continue;
}

for(int i=0;i<sizeof(a);i++){

if(c == a[i]){
c = a[((i-key)+61)%61];
printf("%c",c);
break;
}
if(c == '\0'){
break;}
if(c ==' '){
printf("%c",c);
break;
}
if(c=='\n'){
printf("\n");
break;
}
else{
continue;
}
}
}
return 0;
}
