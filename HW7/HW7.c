#include <stdio.h>
#define CUPS 6
#define PLAYER 0
#define COMPUTER 1


void initalizegame(int board[][7]){
 int n;
 printf("Her delikte kac tane tas olsun:\n");
 scanf("%d",&n);
 int i,j;
 board[PLAYER][6] = 0;
 board[COMPUTER][6] = 0;
 for(i=0;i<2;i++){
     for(j=0;j<CUPS;j++){
         board[i][j] = n; /* tum cuplarin icine n sayda tas doldurur*/
    }
  }
}


void printboard(int board[][7]){
    printf("+----+---+---+---+---+---+---+----+\n");
    printf("|    | %d | %d | %d | %d | %d | %d |    |\n",board[COMPUTER][5],board[COMPUTER][4],board[COMPUTER][3],board[COMPUTER][2],board[COMPUTER][1],board[COMPUTER][0]);
    printf("| %d  |---+---+---+---+---+---| %d  |\n",board[COMPUTER][6],board[PLAYER][6]);
    printf("|    | %d | %d | %d | %d | %d | %d |    |\n",board[PLAYER][0],board[PLAYER][1],board[PLAYER][2],board[PLAYER][3],board[PLAYER][4],board[PLAYER][5]);
    printf("+----+---+---+---+---+---+---+----+\n");
    }

int move(int cup,int c,int board[][7]){
        int j,a,n;
        int current = c;
        if(c==0){
        a = 0;
         cup = cup - 1;
        j = cup + 1;
        n = board[a][cup];
        board[a][cup] = 0;
        while(n > 0){
             if(board[a][j]==0 && n==1){
               board[a][j]++;
               n--;
               current = 1;
              continue;
           }
                if(board[a][j] != 0 && n==1){
                 board[a][j]++;
                 if(j==6){
                     break;
                 }
                 n = board[a][j];
                 board[a][j] = 0;
                 j++;
                 continue;
                }
             if(a==0 && j==6){
                if(n==1){
                    board[a][j]++;
                    n--;
                    current = 0;
                    continue;

                }
                    else{
                    board[a][j]++;
                    n--;
                    a = 1;
                    j = 0;
                    continue;
                }

            }
            if(a==1 && j==6){
                 a = 0;
                 j = 0;
            }
           board[a][j]++;
           j++;
           n--;

        }


        if(a==0 && j==6){
            printboard(board);
            current = 0;
            return 0;
        }
        current = 1;
        printboard(board);
        return current;


}

        if(c==1){
        cup = cup - 1;
        a = 1;
        j = cup + 1;
        n = board[a][cup];
        int x,y;
        board[a][cup] = 0;
         while(n > 0){
             if(a==1 && j==6){
                if(n==1){
                    board[a][j]++;
                    n--;
                    current = 1;
                    continue;

                }
                    else{
                    board[a][j]++;
                    n--;
                    a = 0;
                    j = 0;
                    continue;
                }

            }
              if(board[a][j] != 0 && n==1){
                 board[a][j]++;
                 if(j==6){
                     break;
                 }
                 n = board[a][j];
                 board[a][j] = 0;
                 j++;
                 continue;
                }
            if(board[a][j]==0 && n==1){
               board[a][j]++;
               n--;
               current = 0;
              continue;
           }

                  if(a==0 && j==6){
                 a = 1;
                 j = 0;
            }

           board[a][j]++;
           j++;
           n--;

        }

        if(a==1 && j==6){
            printboard(board);
            current = 1;
            return 1;
        }
        current = 0;
        printboard(board);
        return current;
    }
}


int gameplay(int board[][7]) {
    int current = 0; /* 0 eger player oynuyosa,1 eger bilgisayar oynuyorsa */
    int cup;
    int i;

    while (1) {
        if (current == 0) {
            int a = PLAYER;
            printf("Select the cup\n");
            scanf("%d", &cup);
            current = move(cup, 0, board);
            if (current == 0) {
                continue;
            }
        }

        if (current == 1) {
            int a = COMPUTER;
            int c;
            for (i = 0; i < 6; i++) {
                if (board[a][i] > 0) {
                    c = i;
                    break;
                }
            }
            cup = c + 1;
            current = move(cup, 1, board);
            if (current == 1) {
                continue;
            }
        }
          int i, flag = 0;
    for (i = 0; i < CUPS; i++) {
        if (board[PLAYER][i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        if(board[1][6]>board[0][6]){
        printf("Oyun bitti. Bilgisayar kazandı!\n");
        break;
        }
        else{
             printf("Oyun bitti. Oyuncu kazandı!\n");
             break;;
        }
    }

    flag = 0;
    for (i = 0; i < CUPS; i++) {
        if (board[COMPUTER][i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        if(board[1][6]>board[0][6]){
        printf("Oyun bitti. Bilgisayar kazandı!\n");
        break;
        }
        else{
             printf("Oyun bitti. Oyuncu kazandı!\n");
             break;
        }
    }


    }
}


 int main() {
 int board[2][7];
 initalizegame(board);
 printboard(board);
 gameplay(board);


  return 0;
 }
