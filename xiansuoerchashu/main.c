#include <stdio.h>
#include <stdlib.h>
#define TElemType char//宏定义，结点中数据域的类型
//枚举，Link为0，Thread为1
typedef enum {
    Link,
    Thread
}PointerTag;
//结点结构构造
typedef struct BiThrNode{
    TElemType data;//数据域
    struct BiThrNode* lchild,*rchild;//左孩子，右孩子指针域
    PointerTag Ltag,Rtag;//标志域，枚举类型
}BiThrNode,*BiThrTree;
BiThrTree pre=NULL;
//采用前序初始化二叉树
//中序和后序只需改变赋值语句的位置即可
void CreateTree(BiThrTree *tree);
void InThreading(BiThrTree p);
void InOrderThraverse_Thr(BiThrTree p);
//void PreThreading(BiThrTree Root);
void InitThread(BiThrTree T);

int main() {
    BiThrTree t;
    printf("输入前序二叉树:\n");
    CreateTree(&t);
    InitThread(t);
    InThreading(t);
    printf("输出中序序列:\n");
    InOrderThraverse_Thr(t);
    return 0;
}
void CreateTree(BiThrTree * tree){
    char data;
    scanf("%c",&data);
    if (data!=' '){
        if (!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
            printf("申请结点空间失败");
            return;
        }else{
            (*tree)->data=data;//采用前序遍历方式初始化二叉树
            CreateTree(&((*tree)->lchild));//初始化左子树
            CreateTree(&((*tree)->rchild));//初始化右子树
        }
    }else{
        *tree=NULL;
    }
}

//中序对二叉树进行线索化
void InThreading(BiThrTree p){
    //如果当前结点存在
    if (p) {
        InThreading(p->lchild);//递归当前结点的左子树，进行线索化
        //如果当前结点没有左孩子，左标志位设为1，左指针域指向上一结点 pre
        if (!p->lchild) {
            p->Ltag=Thread;
            p->lchild=pre;
        }
        //如果 pre 没有右孩子，右标志位设为 1，右指针域指向当前结点。
        if (pre&&!pre->rchild) {
            pre->Rtag=Thread;
            pre->rchild=p;
        }
        pre=p;//pre指向当前结点
        InThreading(p->rchild);//递归右子树进行线索化
    }
}
//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p)
{
    while(p)
    {
        //一直找左孩子，最后一个为中序序列中排第一的
        while(p->Ltag == Link){
            p = p->lchild;
        }
        printf("%c ", p->data);  //操作结点数据
        //当结点右标志位为1时，直接找到其后继结点
        while(p->Rtag == Thread && p->rchild !=NULL)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        //否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
        p = p->rchild;
    }
}
/*2.初始化tag*/
void InitThread(BiThrTree T) {
if (T != NULL) {
T->Ltag = Link;
T->Rtag = Link;	//初始化当前树中的tag指针为0，表示还未线索化
InitThread(T->lchild);	//递归遍历左子树
InitThread(T->rchild);	//递归遍历右子树
}
}

////xianxu xiansuohua
//void PreThreading(BiThrTree Root){
//    if (Root == NULL)
//    {
//        return;
//    }
//    if (Root->lchild == NULL) //没有左子树
//    {
//        Root->lchild = pre;   //前驱
//        Root->Ltag = Thread;
//    }
//    if (pre != NULL && pre->rchild == NULL) // 上一个节点有没有  右子树
//    {  //Prev第一次进来 为空
//        pre->rchild = Root;   //后继
//        pre->Rtag = Thread;
//    }
//    pre = Root;//前驱  ， 每次记住上次的节点
//
//    //判断Root是否有左右孩子
//    if (Root->Ltag == Link)
//        PreThreading(Root->lchild);
//    if (Root->Rtag == Link)
//        PreThreading(Root->rchild);
//}
