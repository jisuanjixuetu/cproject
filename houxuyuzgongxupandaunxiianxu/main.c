#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode* BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
BinTree CreatBintree(int n,int Late[],int Mid[])
{

    if(n<=0)
        return 0;
    else
    {
        BinTree Root=(BinTree)malloc(sizeof(struct TNode));
        Root->Data=Late[n-1];
        Root->Left=NULL;
        Root->Right=NULL;
        int i;
        for( i=0;i<n;i++)
        {
            if(Mid[i]==Late[n-1])
            break;
        }
        Root->Left=CreatBintree(i,Late,Mid);
        Root->Right=CreatBintree(n-i-1,Late+i,Mid+i+1);
        return Root;
    }

}
void PreorderTraversal(BinTree BT)
{
    if(BT==NULL)
        return;
    else
    {
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
        return ;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int Late[n],Mid[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Late[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Mid[i]);
    }
    BinTree BT;
    BT=CreatBintree(n, Late, Mid);
    printf("Preorder:");
    PreorderTraversal(BT);
}


