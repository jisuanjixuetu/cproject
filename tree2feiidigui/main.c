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

void createBiTree(BiTree *bi_tree);           //���� ���������� ����
void postOrder(BiTree root);                  //���� ������� ����
void inOrder(BiTree root);                    //���� ������� ����
void preOrder(BiTree root);                   //���� ������� ����

void visit(BITREE_NODE_TYPE_ELEMENT data);    //���� ���ʽ������ ����
void InitStack(SeqStack *S);                  //���� ��ʼ�� ����
int IsEmpty(SeqStack S);                     //���� �п� ����
int IsFull(SeqStack S);                      //���� ���� ����
int Push(SeqStack *S, StackElementType x);    //���� ѹջ ����
int Pop(SeqStack *S, StackElementType *x);    //���� ��ջ ����
int GetTop(SeqStack S, StackElementType *x); //���� ȡջ��Ԫ�� ����

int main()
{
    //�������ݣ�ABC**DE*G**F***
    //����:ABCDEGF
    //����:CBEGDFA
    //����:CGEFDBA
    BiTree bi_tree = NULL;
    puts("�밴������������һ�Ŷ������Ľ�����ݣ���'*'�������ֵ��");
    createBiTree(&bi_tree);
    printf("\n�������У�");
    preOrder(bi_tree);
    printf("\n�������У�");
    inOrder(bi_tree);
    printf("\n�������У�");
    postOrder(bi_tree);
    putchar('\n');
    system("pause");
    return 0;
}

//���� ���ʽ������ ����
void visit(BITREE_NODE_TYPE_ELEMENT data)
{
    putchar(data);
}

//���� ���������� ����
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

//���� ������� ����
void preOrder(BiTree root)
{
    SeqStack s;
    BiTree temp_tree = root;
    InitStack(&s);
    while (temp_tree != NULL || IsEmpty(s) != TRUE)
    {
        while (temp_tree != NULL)
        {
            visit(temp_tree->data); //���ʸ��ڵ�
            if (IsFull(s) == TRUE)
                return;
            Push(&s, temp_tree);           //��ָ���ջ
            temp_tree = temp_tree->LChild; //����������
        }

        if (IsEmpty(s) != TRUE)
        {
            Pop(&s, &temp_tree);           //��ָ�뵯ջ
            temp_tree = temp_tree->RChild; //����������
        }
    }
}

//���� ������� ����
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
            Push(&s, temp_tree);           //��ָ���ջ
            temp_tree = temp_tree->LChild; //����������
        }
        if (IsEmpty(s) != TRUE)
        {
            Pop(&s, &temp_tree);           //��ָ�뵯ջ
            visit(temp_tree->data);        //���ʸ��ڵ�
            temp_tree = temp_tree->RChild; //����������
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
            Push(&s, temp_tree);           //��ָ���ջ
            temp_tree = temp_tree->LChild; //����������
        }
        if (IsEmpty(s) != TRUE)
        {
            GetTop(s, &temp_tree);
            if (temp_tree->RChild == NULL || temp_tree->RChild == flag_tree)
            {
                Pop(&s, &temp_tree);    //��ָ�뵯ջ
                visit(temp_tree->data); //���ʸ��ڵ�
                flag_tree = temp_tree;
                temp_tree = NULL;
            }
            else
                temp_tree = temp_tree->RChild; //����������
        }
    }
}

//���� ��ʼ�� ����
void InitStack(SeqStack *S)
{
    S->top = -1;
}

//���� �п� ����
int IsEmpty(SeqStack S)
{
    return (S.top == -1 ? TRUE : FALSE);
}

//���� ���� ����
int IsFull(SeqStack S)
{
    return (S.top == MAX_SIZE - 1 ? TRUE : FALSE);
}

//���� ѹջ ����
int Push(SeqStack *S, StackElementType x)
{
    if (S->top == MAX_SIZE - 1)
        return (FALSE);
    S->top++;
    S->elem[S->top] = x;
    return (TRUE);
}

//���� ��ջ ����
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

//���� ȡջ��Ԫ�� ����
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

