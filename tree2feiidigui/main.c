#include <stdio.h>
#include <stdlib.h>

#define BITREE_NODE_TYPE_ELEMENT char
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 50
#define StackElementType BiTree

typedef struct bi_tree_node
{
    BITREE_NODE_TYPE_ELEMENT data;
    struct bi_tree_node *LChild;
    struct bi_tree_node *RChild;
} BiTree_Node, *BiTree;

typedef struct
{
    StackElementType elem[MAX_SIZE];
    int top;
} SeqStack;

void createBiTree(BiTree *bi_tree);           //声明 创建二叉树 函数
void postOrder(BiTree root);                  //声明 后序遍历 函数
void inOrder(BiTree root);                    //声明 中序遍历 函数
void preOrder(BiTree root);                   //声明 先序遍历 函数

void visit(BITREE_NODE_TYPE_ELEMENT data);    //声明 访问结点数据 函数
void InitStack(SeqStack *S);                  //声明 初始化 函数
int IsEmpty(SeqStack S);                     //声明 判空 函数
int IsFull(SeqStack S);                      //声明 判满 函数
int Push(SeqStack *S, StackElementType x);    //声明 压栈 函数
int Pop(SeqStack *S, StackElementType *x);    //声明 弹栈 函数
int GetTop(SeqStack S, StackElementType *x); //声明 取栈顶元素 函数

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
    system("pause");
    return 0;
}

//定义 访问结点数据 函数
void visit(BITREE_NODE_TYPE_ELEMENT data)
{
    putchar(data);
}

//定义 创建二叉树 函数
void createBiTree(BiTree *bi_tree)
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
{
    SeqStack s;
    BiTree temp_tree = root;
    InitStack(&s);
    while (temp_tree != NULL || IsEmpty(s) != TRUE)
    {
        while (temp_tree != NULL)
        {
            visit(temp_tree->data); //访问根节点
            if (IsFull(s) == TRUE)
                return;
            Push(&s, temp_tree);           //根指针进栈
            temp_tree = temp_tree->LChild; //遍历左子树
        }

        if (IsEmpty(s) != TRUE)
        {
            Pop(&s, &temp_tree);           //根指针弹栈
            temp_tree = temp_tree->RChild; //遍历右子树
        }
    }
}

//定义 中序遍历 函数
void inOrder(BiTree root)
{
    SeqStack s;
    BiTree temp_tree = root;
    InitStack(&s);
    while (temp_tree != NULL || IsEmpty(s) != TRUE)
    {
        while (temp_tree != NULL)
        {
            if (IsFull(s) == TRUE)
                return;
            Push(&s, temp_tree);           //根指针进栈
            temp_tree = temp_tree->LChild; //遍历左子树
        }
        if (IsEmpty(s) != TRUE)
        {
            Pop(&s, &temp_tree);           //根指针弹栈
            visit(temp_tree->data);        //访问根节点
            temp_tree = temp_tree->RChild; //遍历右子树
        }
    }
}

void postOrder(BiTree root)
{
    SeqStack s;
    BiTree temp_tree = root, flag_tree = NULL;
    InitStack(&s);
    while (temp_tree != NULL || IsEmpty(s) != TRUE)
    {
        while (temp_tree != NULL)
        {
            if (IsFull(s) == TRUE)
                return;
            Push(&s, temp_tree);           //根指针进栈
            temp_tree = temp_tree->LChild; //遍历左子树
        }
        if (IsEmpty(s) != TRUE)
        {
            GetTop(s, &temp_tree);
            if (temp_tree->RChild == NULL || temp_tree->RChild == flag_tree)
            {
                Pop(&s, &temp_tree);    //根指针弹栈
                visit(temp_tree->data); //访问根节点
                flag_tree = temp_tree;
                temp_tree = NULL;
            }
            else
                temp_tree = temp_tree->RChild; //遍历右子树
        }
    }
}

//定义 初始化 函数
void InitStack(SeqStack *S)
{
    S->top = -1;
}

//定义 判空 函数
int IsEmpty(SeqStack S)
{
    return (S.top == -1 ? TRUE : FALSE);
}

//定义 判满 函数
int IsFull(SeqStack S)
{
    return (S.top == MAX_SIZE - 1 ? TRUE : FALSE);
}

//定义 压栈 函数
int Push(SeqStack *S, StackElementType x)
{
    if (S->top == MAX_SIZE - 1)
        return (FALSE);
    S->top++;
    S->elem[S->top] = x;
    return (TRUE);
}

//定义 弹栈 函数
int Pop(SeqStack *S, StackElementType *x)
{
    if (S->top == -1)
        return (FALSE);
    else
    {
        *x = S->elem[S->top];
        S->top--;
        return (TRUE);
    }
}

//定义 取栈顶元素 函数
int GetTop(SeqStack S, StackElementType *x)
{
    if (S.top == -1)
        return (FALSE);
    else
    {
        *x = S.elem[S.top];
        return (TRUE);
    }
}

