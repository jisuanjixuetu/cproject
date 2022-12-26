#include <stdlib.h>
#include <stdio.h>
typedef enum {
    Link,
    Thread
}PointTag;
typedef struct BitNode{
    char data;
    struct BitNode*lchild;
    struct BitNode*rchild;
    PointTag Ltag,Rtag;
}BitNode,*BiTree;
BiTree pre = NULL;
void PreThreading(BiTree root);
int main(){

}
void PreThreading(BiTree root){
    if(root){
        if(root->lchild==NULL){
            root->lchild=pre;
            root->Ltag = Thread;
        }
        if(!pre&&root->rchild==NULL){
            pre->rchild=root;
            pre->rchild=Thread;
        }
        pre=root;
    }
    if(root->lchild!=NULL)

}
