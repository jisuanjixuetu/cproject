#include <stdio.h>
#include <stdlib.h>
typedef  struct BitNode{
    char data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode,*BiTree;
void CreatTree(BiTree *T);
int CountDepth(BiTree T);
int main() {
    BiTree tree;
    CreatTree(&tree);
    int depth = CountDepth(tree);
    printf("%d",depth);
    return 0;
}
void CreatTree(BiTree *T){
    char ch;
    ch = getchar();
    if(ch==' ')
        *T = NULL;
    else{
        *T=(BiTree) malloc(sizeof (BitNode));
        (*T)->data = ch;
        CreatTree(&((*T)->lchild));
        CreatTree(&((*T)->rchild));
    }
}
int CountDepth(BiTree T){
    int depth;
    if(T==NULL)
        depth=0;
    else{
        int depthLeft = CountDepth(T->lchild);
        int depthRight = CountDepth(T->rchild);
        depth =1+(depthLeft>depthRight ? depthLeft:depthRight);
    }
    return depth;

}

