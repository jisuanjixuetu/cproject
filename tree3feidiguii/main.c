#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define MaxSize 100
typedef struct BitNode{
    char data;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

typedef struct seqstack{
    BitTree elem[MaxSize];
    int top
}Seqstack;
void CreatTree(BitTree *T);
void PreOrdered(BitTree T);
void InOrdered(BitTree T);
void PostOrdered(BitTree T);
void InitStack(Seqstack *s);
int IsEmpty(Seqstack s);
void visit(char ch);
int getTop(Seqstack S,BitTree *x);
int IsEmpty(Seqstack s);
int IsFull(Seqstack s);
int Push(Seqstack*s,BitTree x);
int Pop(Seqstack *s,BitTree *x);

int main() {
    BitTree tree = NULL;
    printf("please enter some chars empty to jump\n");
    CreatTree(&tree);
    printf("the PreOrdered: ");
    PreOrdered(tree);
    printf("\nthe Inordered: ");
    InOrdered(tree);
    printf("\nthe PostOrdered: ");
    PostOrdered(tree);
}
void CreatTree(BitTree *T){
    char ch;
    ch = getchar();
    if(ch==' ')
        *T = NULL;
    else{
        *T = (BitTree) malloc(sizeof (BitNode));
        if(!T)
            exit(OVERFLOW);
        else{
            (*T)->data = ch;
            CreatTree(&((*T)->lchild));
            CreatTree(&((*T)->rchild));
        }
    }
}
void PreOrdered(BitTree T){
    Seqstack S;
    BitTree current_tree = T;
    InitStack(&S);
    while(current_tree != NULL||IsEmpty(S)!=1)
    {
        while(current_tree!=NULL){
            visit(current_tree->data);
            if(IsFull(S)==1)
                return;
            Push(&S,current_tree);
            current_tree = current_tree->lchild;
        }
        if(IsEmpty(S)!=1){
            Pop(&S,&current_tree);
            current_tree = current_tree->rchild;
        }
    }
}
void InOrdered(BitTree T){
    Seqstack S;
    BitTree current_tree = T;
    InitStack(&S);
    while(current_tree!=NULL|| IsEmpty(S)!=1){
        while(current_tree!=NULL){
            if(IsFull(S)==1)
                return;
            Push(&S,current_tree);
            current_tree = current_tree->lchild;
        }
        if(IsEmpty(S)!=1){
            Pop(&S,&current_tree);
            visit(current_tree->data);
            current_tree = current_tree->rchild;
        }

    }
}
void PostOrdered(BitTree T){
    Seqstack S;
    BitTree current_tree = T;
    BitTree flag_tree = NULL;
    InitStack(&S);
    while(current_tree!=NULL|| IsEmpty(S)!=1){
        while(current_tree!=NULL){
            if(IsFull(S))
                return;
            Push(&S,current_tree);
            current_tree = current_tree->lchild;
        }
        if(IsEmpty(S)!=1){
            getTop(S,&current_tree);
            if(current_tree->rchild==NULL||current_tree->rchild == flag_tree){
                Pop(&S,&current_tree);
                visit(current_tree->data);
                flag_tree = current_tree;
                current_tree = NULL;
            }
            else{
                current_tree = current_tree->rchild;
            }
        }
    }

}
void InitStack(Seqstack*s){
    s->top = -1;
}
int IsEmpty(Seqstack s){
    if(s.top==-1)
        return 1;
    else
        return 0;
}
int IsFull(Seqstack s){
    if(s.top==MaxSize-1)
        return 1;
    else
        return 0;
}
int Push(Seqstack*s,BitTree x){
    if(s->top==MaxSize-1)
        return 0;
    s->top++;
    s->elem[s->top] = x;
    return 1;
}
int Pop(Seqstack *s,BitTree *x)
{
    if(s->top==-1)
        return 0;
    else{
        *x = s->elem[s->top];
        s->top--;
        return 1;
    }
}
void visit(char data){
    putchar(data);
}
int getTop(Seqstack S,BitTree *x){
    if(S.top==-1)
        return 0;
    else{
        *x =S.elem[S.top];
        return 1;
    }
}