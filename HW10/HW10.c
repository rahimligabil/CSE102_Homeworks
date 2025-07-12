#include <stdio.h>
#include <string.h>
#define MAX_BINARY_LENGTH 9


/*  for (i = 0; i < 30; i++) {
        printf("%s %c %s\n", s1[i].opcode, s1[i].type, s1[i].format);
    } */

struct instruction {
    char opcode[9];
    char type;
    char format[5];
};

int stringtoint(char *str) {
    return atoi(str);
}


char* to_binary(int decimal_number) {
    char binary[MAX_BINARY_LENGTH];
    binary[MAX_BINARY_LENGTH - 1] = '\0';

    int index = MAX_BINARY_LENGTH - 2;
     int i;
    for (i = 0; i < 8; i++) {
        binary[index--] = (decimal_number % 2) + '0';
        decimal_number /= 2;
    }

    char *result = binary;
    return result;
}

int to_decimal(char binary[]){
    int result = 0;
    int power = 1;
    int i;
    int decimal = 0;
    int size = strlen(binary);
    for(i=size - 1;i >= 0;i--){
        decimal += (binary[i] - '0') * power;
        power = power * 2;

    }
    return decimal;



}


void memoryswap(char memory[][9], char reg, char operand[], int *num) {
    int num1;
    int num2;
    int number;
    int i,j;
    if (reg == 'A') {
        strcpy(memory[(*num) + 1], "01100110");
    } else if (reg == 'B') {
        strcpy(memory[(*num) + 1], "01100111");
    } else if (strcmp(operand, "M[A]") == 0) {
        strcpy(memory[(*num) + 1], "00000101");
    }
    else if (strcmp(operand, "M[B]") == 0) {
        strcpy(memory[(*num) + 2], "00000110");
    }
     else {
        number = atoi(reg);
            char string_number[9];
            strcpy(memory[(*num) + 1],to_binary(number));
    }

    if (strcmp(operand,"A")==0) {
        strcpy(memory[(*num) + 2], "01100110");
    } else if (strcmp(operand,"B")==0) {
        strcpy(memory[(*num) + 2], "01100111");
    } else if (strcmp(operand, "M[B]") == 0) {
        strcpy(memory[(*num) + 2], "00000110");
    }
    else if (strcmp(operand, "M[A]") == 0) {
        strcpy(memory[(*num) + 2], "00000101");
    }
    else {
        number = stringtoint(operand);
         char string_number[9];
            strcpy(memory[(*num) + 2],to_binary(number));
    }
    strcpy(memory[105],memory[*num]);
    strcpy(memory[106],memory[*num + 1]);
    strcpy(memory[107],memory[*num + 2]);
    (*num) = (*num) + 3;
}

void LDAI(char memory[][9],char reg,char operand[5]){

int number;
 number = stringtoint(operand);
    char string_number[9];
            if(reg=='A'){
            strcpy(memory[101],to_binary(number));
            }
            if(reg=='B'){
            strcpy(memory[102], to_binary(number));;
            }
}

void LDA(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
    int number;
    char str[9];
if(strcmp(operand,"M[A]")==0){
    number = to_decimal(memoryA);
    strcpy(memoryA,memory[number - 1]);
}
if(strcmp(operand,"M[B]")==0){
    number = to_decimal(memoryB);
    strcpy(memoryB,memory[number - 1]);
}

}

void SHR(char reg,int num,char memoryA[],char memoryB[],char memory[][9]){
int i,j;
i = 7 - num;
j = 7;
char testarr[9];
if(reg=='A'){
        while(i>=0){
            testarr[j] = memoryA[i];
            j--;
            i--;
        }
        for(i=0;i<num;i++){
           testarr[i] = '0';
        }
        strcpy(memoryA,testarr);
        strcpy(memory[101],memoryA);
}

if(reg=='B'){
        while(i>=0){
            testarr[j] = memoryB[i];
            j--;
            i--;
        }
        for(i=0;i<num;i++){
           testarr[i] = '0';
        }
        strcpy(memoryB,testarr);
        strcpy(memory[102],memoryB);

}


}

void SHL(char reg,int num,char memoryA[],char memoryB[],char memory[][9]){
int i = num;
int j = 0;
char testarr[9];
if(reg=='A'){
        while(i<=7){
            testarr[j] = memoryA[i];
            j++;
            i++;
        }
        for(i=j;i<8;i++){
           testarr[i] = '0';
        }
        strcpy(memoryA,testarr);
        strcpy(memory[101],memoryA);

}

if(reg=='B'){
        while(i<=7){
            testarr[j] = memoryB[i];
            j++;
            i++;
        }
        for(i=j;i<8;i++){
           testarr[i] = '0';
        }
        strcpy(memoryB,testarr);
        strcpy(memory[102],memoryB);

}



}


void ADD(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){

int num1,num2;
int total;
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
total = num1 + num2;
if(reg=='A'){
strcpy(memory[101],to_binary(total));
strcpy(memoryA,to_binary(total));
}
else if(reg=='B'){
strcpy(memory[102],to_binary(total));
strcpy(memoryB,to_binary(total));
}

}

void PRI(char reg,char memoryA[],char memoryB[]){
int num;
if(reg == 'A'){
num = to_decimal(memoryA);
}
else if(reg == 'B'){
num = to_decimal(memoryB);
}
printf("\nResult = %d\n",num);


}

void ADDI(char reg,char operand[],char memoryA[],char memoryB[]){

int num1,num2;
int total;

if(reg =='A'){

num1 = to_decimal(memoryA);
num2 = stringtoint(operand);
total = num1 + num2;
strcpy(memoryA,to_binary(total));
}
if(reg =='B'){

num1 = to_decimal(memoryB);
num2 = stringtoint(operand);
total = num1 + num2;
strcpy(memoryB,to_binary(total));
}

}

void ADDM(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
int total;
int n;
char str[9];
if(reg == 'A' && (strcmp(operand,"M[B]")==0)){
num1 = to_decimal(memoryA);
n = to_decimal(memoryB); /* b nin icindeki deger adresi gosteriyor */
strcpy(str,memory[n - 1]);
num2 = to_decimal(str);
total  = num1 + num2;
strcpy(memoryA,to_binary(total));
}
if(reg == 'B' && (strcmp(operand,"M[B]")==0)){
num1 = to_decimal(memoryB);
n = to_decimal(memoryB); /* b nin icindeki deger adresi gosteriyor */
strcpy(str,memory[n - 1]);
num2 = to_decimal(str);
total  = num1 + num2;
strcpy(memoryB,to_binary(total));
}
if(reg == 'A' && (strcmp(operand,"M[A]")==0)){
num1 = to_decimal(memoryA);
n = to_decimal(memoryA); /* A nin icindeki deger adresi gosteriyor */
strcpy(str,memory[n - 1]);
num2 = to_decimal(str);
total  = num1 + num2;
strcpy(memoryA,to_binary(total));
}
if(reg == 'B' && (strcmp(operand,"M[A]")==0)){
num1 = to_decimal(memoryB);
n = to_decimal(memoryA); /* A nin icindeki deger adresi gosteriyor */
strcpy(str,memory[n - 1]);
num2 = to_decimal(str);
total  = num1 + num2;
strcpy(memoryB,to_binary(total));
}

}


void AND(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int i;
char str[9];
for(i=0;i<8;i++){
    if(memoryA[i] == memoryB[i]){
        str[i] = memoryA[i];
    }
    else{
        str[i] = '0';
    }

}
if(reg=='A'){
    strcpy(memoryA,str);
}
else if(reg=='B'){
    strcpy(memoryB,str);
}




}

void ANDI(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){

char str[9];
char testarr[9];
int num;
int i;
num = stringtoint(operand);
strcpy(str,to_binary(num));
if(reg=='A'){
for(i=0;i<8;i++){
    if(memoryA[i] == str[i]){
        testarr[i] = memoryA[i];
    }
    else{
        testarr[i] = '0';
    }

}
}
if(reg=='B'){
for(i=0;i<8;i++){
    if(memoryB[i] == str[i]){
        testarr[i] = memoryB[i];
    }
    else{
        testarr[i] = '0';
    }

}
}
if(reg=='A'){
    strcpy(memoryA,testarr);
}
else if(reg=='B'){
    strcpy(memoryB,testarr);
}
}

void ANDM(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){

int num;
char str[9];
char testarr[9];
int i;
num = to_decimal(memoryB);
strcpy(str,memory[num-1]);
for(i=0;i<8;i++){
    if(memoryA[i] == str[i]){
        testarr[i] = memoryA[i];
    }
    else{
        testarr[i] = '0';
    }


}
    strcpy(memoryA,testarr);

}

void INC(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num;
    if(reg=='A'){
    num = to_decimal(memoryA);
    num = num + 1;
    strcpy(memoryA,to_binary(num));
    }
    else if(reg=='B'){
    num = to_decimal(memoryB);
    num = num + 1;
    strcpy(memoryB,to_binary(num));
    }

}


void DEC(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num;
    if(reg=='A'){
    num = to_decimal(memoryA);
    num = num - 1;
    strcpy(memoryA,to_binary(num));
    }
    else if(reg=='B'){
    num = to_decimal(memoryB);
    num = num - 1;
    strcpy(memoryB,to_binary(num));
    }




}


void STR(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num;
if(reg=='A' && (strcmp(operand,"M[B]")==0)){
num = to_decimal(memoryB);
strcpy(memory[num - 1],memoryA);

}
if(reg=='B'&& (strcmp(operand,"M[B]")==0)){
num = to_decimal(memoryB);
strcpy(memory[num - 1],memoryB);

}
if(reg=='B'&& (strcmp(operand,"M[A]")==0)){
num = to_decimal(memoryA);
strcpy(memory[num - 1],memoryB);

}
if(reg=='A'&& (strcmp(operand,"M[A]")==0)){
num = to_decimal(memoryA);
strcpy(memory[num - 1],memoryA);

}


}


void SWP(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
char str[9];
strcpy(str,memoryA);
strcpy(memoryA,memoryB);
strcpy(memoryB,str);
}

void PRII(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[],int*num){
int num1;
num1 = atoi(reg);
printf("%d",num1);
strcpy(memory[*num + 1],to_binary(num1));
strcpy(memory[*num + 2],"00000000");
 strcpy(memory[105],memory[*num]);
strcpy(memory[106],memory[*num + 1]);
strcpy(memory[107],memory[*num + 2]);
*num = *num + 3;

}
void PRIM(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
char str[9];
int num;
if(strcmp(operand,"M[A]")==0){
strcpy(str,memoryA);
num = to_decimal(str);
printf("%s",memory[num - 1]);
}
if(strcmp(operand,"M[B]")==0){
strcpy(str,memoryB);
num = to_decimal(str);
printf("%s",memory[num - 1]);
}



}
void OR(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int i;
char str[9];
for(i=0;i<8;i++){
    if(memoryA[i] == memoryB[i]){
        str[i] = memoryA[i];
    }
    else{
        str[i] = '1';
    }

}
if(reg=='A'){
    strcpy(memoryA,str);
}
else if(reg=='B'){
    strcpy(memoryB,str);
}

}

void ORI(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
char str[9];
char testarr[9];
int num;
int i;
num = stringtoint(operand);
strcpy(str,to_binary(num));
if(reg=='A'){
for(i=0;i<8;i++){
    if(memoryA[i] == str[i]){
        testarr[i] = memoryA[i];
    }
    else{
        testarr[i] = '1';
    }

}
}
if(reg=='B'){
for(i=0;i<8;i++){
    if(memoryB[i] == str[i]){
        testarr[i] = memoryB[i];
    }
    else{
        testarr[i] = '1';
    }

}
}
if(reg=='A'){
    strcpy(memoryA,testarr);
}
else if(reg=='B'){
    strcpy(memoryB,testarr);
}

}

void ORM(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){

int num;
char str[9];
char testarr[9];
int i;
if(strcmp(operand,"M[B]")==0){
num = to_decimal(memoryB);
strcpy(str,memory[num-1]);
for(i=0;i<8;i++){
    if(memoryA[i] == str[i]){
        testarr[i] = memoryA[i];
    }
    else{
        testarr[i] = '1';
    }


}
    strcpy(memoryA,testarr);

}
if(strcmp(operand,"M[A]")==0){
num = to_decimal(memoryA);
strcpy(str,memory[num-1]);
for(i=0;i<8;i++){
    if(memoryA[i] == str[i]){
        testarr[i] = memoryA[i];
    }
    else{
        testarr[i] = '1';
    }


}
    strcpy(memoryA,testarr);

}
}

void SUB(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
int total;
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
total = num1 - num2;
if(reg=='A'){
    strcpy(memoryA,to_binary(total));
}
if(reg=='B'){
    strcpy(memoryB,to_binary(total));
}


}

void SUBI(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
int total;
if(reg =='A'){
num1 = to_decimal(memoryA);
num2 = stringtoint(operand);
total = num1 - num2;

strcpy(memoryA,to_binary(total));
}
if(reg =='B'){
num1 = to_decimal(memoryB);
num2 = stringtoint(operand);
total = num1 - num2;

strcpy(memoryB,to_binary(total));
}

}

void SUBM(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2,num3;
int total;
if(reg=='A' && strcmp(operand,"M[B]")==0){
num1 = to_decimal(memoryB);
num2 = to_decimal(memoryA);
num3 = stringtoint(memory[num1 - 1]);
total = num2 - num3;
strcpy(memoryA,to_binary(total));
}
if(reg=='A' && strcmp(operand,"M[A]")==0){
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryA);
num3 = stringtoint(memory[num1 - 1]);
total = num2 - num3;
strcpy(memoryA,to_binary(total));
}
if(reg=='B' && strcmp(operand,"M[B]")==0){
num1 = to_decimal(memoryB);
num2 = to_decimal(memoryB);
num3 = stringtoint(memory[num1 - 1]);
total = num2 - num3;
strcpy(memoryB,to_binary(total));
}
if(reg=='B' && strcmp(operand,"M[A]")==0){
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
num3 = stringtoint(memory[num1 - 1]);
total = num2 - num1;
strcpy(memoryB,to_binary(total));
}



}

void J(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
int total;
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
total = num1 + num2;
strcpy(memory[104],to_binary(total));
}

void LESS(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
if(num1>num2){
    strcpy(memoryA,"00000000");
}
else{
    strcpy(memoryA,"00000001");
}
}

void GRT(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int num1,num2;
num1 = to_decimal(memoryA);
num2 = to_decimal(memoryB);
if(num1>num2){
    strcpy(memoryA,"00000001");
}
else{
    strcpy(memoryA,"00000000");
}
}

void NOR(char memory[][9],char reg,char operand[],char memoryA[],char memoryB[]){
int i;
char str[9];
for(i=0;i<8;i++){
    if(memoryA[i] == memoryB[i] && memoryA[i]=='0'){
        str[i] = '1';
    }
    else{
        str[i] = '0';
    }

}
if(reg=='A'){
    strcpy(memoryA,str);
}
else if(reg=='B'){
    strcpy(memoryB,str);
}

}






int main() {
    struct instruction s1[30];
    char memory[128][9];
    char memoryA[9];
    char memoryB[9];
    FILE *file;
    int num = 0;
    file = fopen("instruction.txt", "r");
    if (file == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    char filename[100];
    char line[100];
    int i;
    for (i = 0; i < 30; i++) {
        fgets(line, sizeof(line), file);
        sscanf(line, "%8[^ ]|%c|%5[^ ]", s1[i].opcode, &s1[i].type, s1[i].format);
    }
    fclose(file);



    printf("Dosya adini giriniz(.asm): ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    char line2[25];
    while ((fgets(line2, sizeof(line2), file))) {
    char opcode[5],operand[5];
    char reg;
    int a;
    int ir = 0;
    sscanf(line2, "%d %s %c %s", &a, opcode, &reg, operand);
    for(i=0;i<30;i++){
        if(strcmp(s1[i].format,opcode)==0){
            strcpy(memory[num],s1[i].opcode);
        }
    }
    ir = ir + 3; /* memoryde 104 adresi program counter onu ekliyor hep 3 islem */
    strcpy(memory[104],to_binary(ir));

      if (strcmp(opcode, "LDAI") == 0) {
            memoryswap(memory,reg,operand,&num);
            LDAI(memory,reg,operand);
            if(reg=='A'){
            strcpy(memoryA,memory[101]);
            }
            if(reg=='B'){
            strcpy(memoryB,memory[102]);
            }


      }
         else if (strcmp(opcode, "LDA") == 0) {
            strcpy(memory[99],"00000101");
            strcpy(memory[100],"00000110");
            memoryswap(memory,reg,operand,&num);
            LDA(memory,reg, operand,memoryA,memoryB);
        }
         else if (strcmp(opcode, "SHR") == 0) {
            memoryswap(memory,reg,operand,&num);
            SHR(reg, atoi(operand),memoryA,memoryB,memory);
        }
         else if (strcmp(opcode, "SHL") == 0) {
            memoryswap(memory,reg,operand,&num);
            SHL(reg, atoi(operand),memoryA,memoryB,memory);
        }
         else if (strcmp(opcode, "ADD") == 0) {
            memoryswap(memory,reg,operand,&num);
            ADD(memory,reg,operand,memoryA,memoryB);
        }
        else if (strcmp(opcode, "PRI") == 0) {
                if(reg=='A'){
                strcpy(memory[num + 1],"01100110");
                }
                 if(reg=='B'){
                strcpy(memory[num + 1],"01100111" );
                }
                strcpy(memory[num + 2],"00000000");
                 strcpy(memory[105],memory[num]);
                 strcpy(memory[106],memory[num + 1]);
                  strcpy(memory[107],memory[num + 2]);
                num = num + 3;


            PRI(reg,memoryA,memoryB);
        }
         else if (strcmp(opcode, "EXIT") == 0) {
            strcpy(memory[num],"00011101");
            strcpy(memory[num + 2],"00000000");
            strcpy(memory[num + 1],"00000000");
            strcpy(memory[105],memory[num]);
            strcpy(memory[106],memory[num + 1]);
            strcpy(memory[107],memory[num + 2]);
            num = num  + 3;
            break;
        }
        else if(strcmp(opcode,"ADDI")==0){
            ADDI(reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
        else if(strcmp(opcode,"ADDM")==0){
            ADDM(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"AND")==0){
            AND(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"ANDI")==0){
            ANDI(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"ANDM")==0){
            ANDM(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
        else if(strcmp(opcode,"INC")==0){
            INC(memory,reg,operand,memoryA,memoryB);
            if(reg=='A'){
              strcpy(memory[num],"00001101");
            strcpy(memory[num + 1],memoryA);
            strcpy(memory[num + 2],"00000000");
            }
            if(reg=='B'){
              strcpy(memory[num],"00001101");
            strcpy(memory[num + 1],memoryB);
            strcpy(memory[num + 2],"00000000");
            }
            num = num + 3;
        }
         else if(strcmp(opcode,"DEC")==0){
            DEC(memory,reg,operand,memoryA,memoryB);
               if(reg=='A'){
              strcpy(memory[num],"00001110");
            strcpy(memory[num + 1],memoryA);
            strcpy(memory[num + 2],"00000000");
            }
            if(reg=='B'){
              strcpy(memory[num],"00001110");
            strcpy(memory[num + 1],memoryB);
            strcpy(memory[num + 2],"00000000");
            }
            num = num + 3;
        }
         else if(strcmp(opcode,"STR")==0){
            STR(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"SWP")==0){
            SWP(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"PRII")==0){
                int num3 = atoi(reg);
            PRII(memory,reg,operand,memoryA,memoryB,&num);
             strcpy(memory[num],"00011011");
            strcpy(memory[num + 1],to_binary(num3));
            strcpy(memory[num + 2],"00000000");
             strcpy(memory[105],memory[num]);
            strcpy(memory[106],memory[num + 1]);
            strcpy(memory[107],memory[num + 2]);
            num = num + 3;
        }
        else if(strcmp(opcode,"PRIM")==0){
            int num3;
             sscanf(line2, "%d %s %s %c", &a, opcode, operand, &reg);
            PRIM(memory,reg,operand,memoryA,memoryB);
             strcpy(memory[num],"00011100");
            strcpy(memory[num + 2],"00000000");
            if(strcmp(operand,"M[A]")==0){
                strcpy(memory[num + 1],"00000101");
            }
             if(strcmp(operand,"M[B]")==0){
                strcpy(memory[num + 1],"00000110");
            }
            strcpy(memory[105],memory[num]);
            strcpy(memory[106],memory[num + 1]);
            strcpy(memory[107],memory[num + 2]);
            num = num + 3;
        }

        else if(strcmp(opcode,"OR")==0){
            OR(memory,reg,operand,memoryA,memoryB);
              memoryswap(memory,reg,operand,&num);
        }
          else if(strcmp(opcode,"ORI")==0){
            ORI(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"ORM")==0){
            ORM(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"SUB")==0){
            SUB(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
           else if(strcmp(opcode,"SUBI")==0){
            SUBI(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
          else if(strcmp(opcode,"SUBM")==0){
            SUBI(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
          else if(strcmp(opcode,"J")==0){
            J(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }
         else if(strcmp(opcode,"LESS")==0){
            LESS(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }

         else if(strcmp(opcode,"GRT")==0){
            GRT(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }

         else if(strcmp(opcode,"NOR")==0){
            NOR(memory,reg,operand,memoryA,memoryB);
            memoryswap(memory,reg,operand,&num);
        }


        else {
            printf("Invalid opcode: %s\n", opcode);
        }
      }
      fclose(file);
      file = fopen(filename,"r");
    while ((fgets(line2, sizeof(line2), file))) {
    char opcode[5],operand[5];
    char reg;
    int a;
    int ir = 0;
    sscanf(line2, "%d %s %c %s", &a, opcode, &reg, operand);
    if(strcmp(opcode,"PRI")==0){
    printf("%d %s %c\n",a,opcode,reg);
    continue;
    }
    if(strcmp(opcode,"EXIT")==0){
    printf("%d %s\n",a,opcode);
    continue;
    }
    printf("%d %s %c %s\n",a,opcode,reg,operand);



 }


    return 0;
}
