#include <stdio.h>
#include <malloc.h>

typedef enum {
    Link,
    Thread
}PointerTag;
typedef struct BiThrNode{
    char data;
    struct BiThrNode*lchild,*rchild;
    PointerTag Ltag,Rtag;
}BiThrNode,*BiThrTree;
BiThrTree pre = NULL;
void InorderThreading(BiThrTree T);
void InorderTraver(BiThrTree T);
void CreatTree(BiThrTree *T);
int main() {
    BiThrTree tree;
    CreatTree(&tree);
    InorderThreading(tree);
    InorderTraver(tree);
    return 0;
}
void InorderThreading(BiThrTree T){
    if(T){
        InorderThreading(T->lchild);
        if(!T->lchild){
            T->Ltag = Thread;
            T->lchild = pre;
        }
        if(pre&&!pre->rchild){
            T->Rtag = Thread;
            pre->rchild = T;
        }
        pre = T;
        InorderThreading(T->rchild);
    }
}
void InorderTraver(BiThrTree T)
{
    while(T) {
        while (T->Ltag == Link) {
            T = T->lchild;
        }
        printf("%c",T->data);
        while (T->Rtag==Thread&&T->rchild!=NULL){
            T = T->rchild;
            printf("%c",T->data);
        }
        T = T->rchild;
    }
}
void CreatTree(BiThrTree *T){
    char ch;
    ch = getchar();
    if(ch ==' ')
        (*T) ==NULL;
    else{
        (*T) = (BiThrTree)malloc(sizeof (BiThrNode));
        (*T)->data = ch;
        CreatTree(&((*T)->lchild));
        CreatTree(&((*T)->rchild));
    }
}