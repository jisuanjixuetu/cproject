#include <stdio.h>
#include <malloc.h>

typedef struct BitNode{
    char data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode,*BiTree;
void CreatTree(BiTree *T);//creat the tree
void PreOrdered(BiTree T);//xianxu bianli
void Inordered(BiTree T);//zhongxu bianli
void PostOrdered(BiTree T);//houxu bianli
int main() {
    BiTree T = NULL;
    printf("Please enter some chars\n");
    CreatTree(&T);
    printf("\nThe preordered is :\n");
    PreOrdered(T);
    printf("\nThe Inordered is :\n");
    Inordered(T);
    printf("\nThe PosOrdered is :\n");
    PostOrdered(T);
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
void PreOrdered(BiTree T){
    if(T!=NULL){
        putchar(T->data);
        PreOrdered(T->lchild);
        PreOrdered(T->rchild);
    }
}
void Inordered(BiTree T){
    if(T!=NULL){
        Inordered(T->lchild);
        putchar(T->data);
        Inordered(T->rchild);
    }
}
void PostOrdered(BiTree T){
    if(T!=NULL){
        PreOrdered(T->lchild);
        PreOrdered(T->rchild);
        putchar(T->data);
    }
}
