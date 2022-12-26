#include <stdio.h>
#include <math.h>
#define N 4
void nqueen(int k);
int queenPos[N];
int main() {
    setbuf(stdout,NULL);
    //int queenPos[N];
    nqueen(0);
    return 0;
}
void nqueen(int k)//in the circumstnce that 0-k-1 queen is placed well,then place the next
{
    int i;
    if(k==N)//N queens is placed well
    {
        for(i = 0;i<N;i++){
            printf("%d",queenPos[i]+1);
        }
        printf("\n");
    }
    for(i = 0;i<N;i++){//try to place the k queen ,lie xu
        int j;
        for(j = 0;j<k;j++){
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))//duijiaoxian
                break;
        }
        if(j==k)//when the i placement is correct
        {
            queenPos[k] = i;//put the k queen in the i place that is to say ,i is the line
            nqueen(k+1);
        }
    }
}
