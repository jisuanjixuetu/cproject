#include <stdio.h>
#define maxsize 100

typedef struct triple{
    int i,j;
    int value;
}Triple;
typedef union tsmatric{
    Triple data[maxsize];
    int mu;//line
    int nu;//col
    int tu;//number for the fei 0
}Tsmatric;
void transmatric(Tsmatric M,Tsmatric N);
int main() {
    Tsmatric M;


}
void transmatric(Tsmatric M,Tsmatric N){
    N.mu = M.nu;
    N.nu = M.mu;
    N.tu = M.tu;
    if(M.tu!=0){
        int q = 0;
        for(int col = 1;col<=M.nu;col++)//an M de lie zhuan
            for(int p = 1;p<=M.tu;p++)//dui M san yuan zu sao miao yibian
                if(M.data[p].j==col){
                    N.data[q].i=M.data[p].j;
                    N.data[q].j = M.data[p].i;
                    N.data[q].value = M.data[p].value;
                    q++;
                }
    }
}
