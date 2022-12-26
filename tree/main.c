#include<stdio.h>
#include<stdlib.h>

#define BITREE_NODE_TYPE_ELEMENT char

typedef struct bi_tree_node
{
    BITREE_NODE_TYPE_ELEMENT data;
    struct bi_tree_node* LChild;
    struct bi_tree_node* RChild;
}BiTree_Node, * BiTree;

void postOrder(BiTree root);	//���� ������� ����
void inOrder(BiTree root);	//���� ������� ����
void preOrder(BiTree root);	//���� ������� ����
void createBiTree(BiTree* bi_tree);	//���� ���������� ����
void visit(BITREE_NODE_TYPE_ELEMENT data);	//���� ���ʽ������ ����

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
    return 0;
}

//���� ���ʽ������ ����
void visit(BITREE_NODE_TYPE_ELEMENT data)
{
    putchar(data);
}

//���� ���������� ����
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

//���� ������� ����
void preOrder(BiTree root)
//���������������rootΪָ�����������ĳһ���������ڵ��ָ��
{
    if (root != NULL)
    {
        visit(root->data);	//���ʸ��ڵ�
        preOrder(root->LChild);	//�������������
        preOrder(root->RChild);//�������������
    }
}

//���� ������� ����
void inOrder(BiTree root)
//���������������rootΪָ�����������ĳһ���������ڵ��ָ��
{
    if (root != NULL)
    {
        inOrder(root->LChild);	//�������������
        visit(root->data);	//���ʸ��ڵ�
        inOrder(root->RChild);	//�������������
    }
}

//���� ������� ����
void postOrder(BiTree root)
//���������������rootΪָ�����������ĳһ���������ڵ��ָ��
{
    if (root != NULL)
    {
        postOrder(root->LChild);	//�������������
        postOrder(root->RChild);	//�������������
        visit(root->data);	//���ʸ��ڵ�
    }
}

