#include <stdio.h>
#include <stdlib.h>


#define MaxNum 10  //��󶥵���

//����
typedef struct endoe
{
    int adjvex;
    struct endoe *next;
}endoe;

//������
typedef struct vnode
{
    char vertex;
    endoe * first_edge;
}node;

//ͼ�ṹ
typedef struct ALGraph
{
    struct vnode adj_list[MaxNum];
    int n,e;
} ALGraph;

//��λ����Vex���±�λ��
int Locate_vex(ALGraph* G,char vex)
{
    for(int i=0;i<G->n;++i)
        if(G->adj_list[i].vertex==vex)
            return i;
}

//����ͼ
void CreateGraph(ALGraph * G)
{
    endoe* temp=NULL;
    int vex1,vex2;
    int i,j,k;
    printf("\n����������ͼ�Ķ������ƣ�");

    for(i=0;i<G->n;++i)
    {
        scanf("%c",&G->adj_list[i].vertex);
        G->adj_list[i].first_edge=NULL;
    }

    printf("\n����������ͼ��ÿ�����Ļ�β����ͻ�ͷ�������ƣ�\n");

    for(k=1;k<=G->e;++k)
    {
        printf("\n������� %d �����Ļ�β�������ƣ�",k);
        scanf("%c",&vex1);
        printf("������� %d �����Ļ�ͷ�������ƣ�",k);
        scanf("%c",&vex2);

        i=Locate_vex(G,vex1);
        j=Locate_vex(G,vex2);

        temp=(endoe*)malloc(sizeof(endoe));
        temp->adjvex=j;
        temp->next=G->adj_list[i].first_edge;
        G->adj_list[i].first_edge=temp;//
    }
}

//��ӡͼ����Ϣ
void PrintGraph(const ALGraph * G)
{
    int i;
    endoe* temp=NULL;

    printf("\n\n����ͼ�� %d �����㣺",G->n);
    for(i=0;i<G->n;++i)
        printf(" %c ",G->adj_list[i].vertex);

    printf("\n\n����ͼ�� %d ������",G->e);
    for(i=0;i< G->n;++i)
    {
        printf("\n%c -> ",G->adj_list[i].vertex);

        temp=G->adj_list[i].first_edge;
        while(temp)
        {
            printf("%c ",G->adj_list[temp->adjvex].vertex);
            temp=temp->next;
        }
    }
    printf("\n");
}

//���Դ���
int main()
{
    ALGraph G;

    printf("\n����ͼ���ڽӱ�ṹ�洢.....");

    printf("\n\n����������ͼ�Ķ�������");
    scanf("%d",&G.n);

    printf("\n����������ͼ�ж���������");
    scanf("%d",&G.e);

    CreateGraph(&G);
    PrintGraph(&G);

    printf("\n");

    return 0;
}
