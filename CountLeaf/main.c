#include <stdio.h>
#include <malloc.h>

typedef struct BitNode{
    char data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode,*BiTree;
void CreatTree(BiTree *T);//creat the tree
void Count(BiTree T,int *count);
int Cou(BiTree T);
int main() {
    BiTree  tree = NULL;
    CreatTree(&tree);
    int count  = 0;
    Count(tree,&count);
    int num = Cou(tree);
    printf("%d\n",count);
    printf("%d\n",num);
    return 0;
}
void CreatTree(BiTree *T){
    char ch;
    ch = getchar();
    if(ch == ' ')
        *T = NULL;
    else{
        *T = (BiTree)malloc(sizeof(BitNode));
        (*T)->data = ch;
        CreatTree(&((*T)->lchild));
        CreatTree(&((*T)->rchild));
    }
}
void Count(BiTree T,int *count){

    if(T){
        if(!(T->rchild)&&!(T->lchild))
            (*count)++;
        Count(T->lchild,count);
        Count(T->rchild,count);
    }
}
int Cou(BiTree T){
    if(T==NULL)
        return 0;
    else if((T->rchild==NULL)&&(T->lchild==NULL))
        return 1;
    else
        return Cou(T->lchild)+ Cou(T->rchild);
}