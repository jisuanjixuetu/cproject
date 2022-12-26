#include <stdio.h>
#include <malloc.h>

typedef struct BitNode{
    int data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode,*BitTree;
BitTree CreatBitTree(int n,int late[],int mid[]);
void preOrderedTrverse(BitTree T);
int main() {
    int n;
    printf("Please enter the number of numbers you want to input\n");
    scanf("%d",&n);
    int late[n];
    int mid[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&late[i]);
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&mid[i]);
    }
    BitTree root;
    root=CreatBitTree(n,late,mid);
    preOrderedTrverse(root);
    return 0;
}
BitTree CreatBitTree(int n,int late[],int mid[]){
    if(n<=0)
        return 0 ;
else{
    BitTree root = (BitTree)malloc(sizeof(BitNode));
    root->data = late[n-1];
    root->lchild = NULL;
    root->rchild = NULL;
    int i;
    for(i = 0;i<n;i++){
        if(mid[i]==late[n-1])
            break;
    }
    root->lchild = CreatBitTree(i,late,mid);
    root->rchild = CreatBitTree(n-i-1,late+i,mid+i+1);
        return root;
}
}
void preOrderedTrverse(BitTree T){
    if(T==NULL){
        return;
    }
    else{
        printf("%d",T->data);
        preOrderedTrverse(T->lchild);
        preOrderedTrverse(T->rchild);
    }
}
