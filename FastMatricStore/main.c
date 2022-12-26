#include <stdio.h>
void FastTranst(TSMatrix M,TSMatrix N);
int main() {

}
void FastTranst(TSMatrix M,TSMatrix N){
    N.nu = M.mu;
    N.mu = M.nu;
    N.tu = M.tu;
    if(M.tu!=0){
        for(int col = 1;col<=M.nu;col++){
            num[col] = 0;//intiate the num;
        }
        for(int t = 1;t<=M.tu;t++)
            num[M.data[t].j]++;find the fei 0 in each col;
    }
    cpot[1] = 1;
    for(col = 2;col<=M.nu;col++)
        cpot[col] = cpot[col-1]+num[col-1];//qiu M zhong mei yi ge fei ling zai B.data zhong de xulie
        for(int p = 1;p<=M.tu;p++){
            col = M.data[p].j;
            q = cpot[col];
            N.data[q].i = M.data[p].j;
            N.data[q].j = M.data[p].i;
            N.data[q].value = M.data[p].value;
            cpot[col]++;

        }
}

