#include<stdio.h>
#include<stdlib.h>

#define BITREE_NODE_TYPE_ELEMENT char

typedef struct bi_tree_node
{
    BITREE_NODE_TYPE_ELEMENT data;
    struct bi_tree_node* LChild;
    struct bi_tree_node* RChild;
}BiTree_Node, * BiTree;

void postOrder(BiTree root);	//声明 后序遍历 函数
void inOrder(BiTree root);	//声明 中序遍历 函数
void preOrder(BiTree root);	//声明 先序遍历 函数
void createBiTree(BiTree* bi_tree);	//声明 创建二叉树 函数
void visit(BITREE_NODE_TYPE_ELEMENT data);	//声明 访问结点数据 函数

int main()
{
    //测试数据：ABC**DE*G**F***
    //先序:ABCDEGF
    //中序:CBEGDFA
    //后序:CGEFDBA
    BiTree bi_tree = NULL;
    puts("请按先序序列输入一颗二叉树的结点数据，以'*'来代表空值：");
    createBiTree(&bi_tree);
    printf("\n先序序列：");
    preOrder(bi_tree);
    printf("\n中序序列：");
    inOrder(bi_tree);
    printf("\n后序序列：");
    postOrder(bi_tree);
    putchar('\n');
    return 0;
}

//定义 访问结点数据 函数
void visit(BITREE_NODE_TYPE_ELEMENT data)
{
    putchar(data);
}

//定义 创建二叉树 函数
void createBiTree(BiTree* bi_tree)
{
    char ch;
    ch = getchar();
    if (ch == '*')
        *bi_tree = NULL;
    else
    {
        *bi_tree = (BiTree)malloc(sizeof(BiTree_Node));
        (*bi_tree)->data = ch;
        createBiTree(&((*bi_tree)->LChild));
        createBiTree(&((*bi_tree)->RChild));
    }
}

//定义 先序遍历 函数
void preOrder(BiTree root)
//先序遍历二叉树，root为指向二叉树（或某一子树）根节点的指针
{
    if (root != NULL)
    {
        visit(root->data);	//访问根节点
        preOrder(root->LChild);	//先序遍历左子树
        preOrder(root->RChild);//先序遍历右子树
    }
}

//定义 中序遍历 函数
void inOrder(BiTree root)
//中序遍历二叉树，root为指向二叉树（或某一子树）根节点的指针
{
    if (root != NULL)
    {
        inOrder(root->LChild);	//中序遍历左子树
        visit(root->data);	//访问根节点
        inOrder(root->RChild);	//中序遍历右子树
    }
}

//定义 后序遍历 函数
void postOrder(BiTree root)
//后序遍历二叉树，root为指向二叉树（或某一子树）根节点的指针
{
    if (root != NULL)
    {
        postOrder(root->LChild);	//后序遍历左子树
        postOrder(root->RChild);	//后序遍历右子树
        visit(root->data);	//访问根节点
    }
}

