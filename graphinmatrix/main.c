/*
�ļ�����ArrayNotation.c
������ͼ�������ʾ��
ʱ�䣺2018/11/19
		2019.1.3��ȫ
*/


#include<stdio.h>
#include <malloc.h>

//-------------ͼ�����飨�ڽӾ��󣩴洢��ʾ---------------
#define INFINITY 95533	// ���ֵ
#define MAX_VERTEX_NUM 20	//��󶥵����
#define VRType int		//�����ϵ���ͣ�����Ȩͼ����1��0��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
#define InfoType int	// ������Ϣ����
#define VErtexType int	//ͼ��������
typedef enum {DG,DN,UDG,UDN}GraphKind;	//ͼ�����ࣨ����ͼ��������������ͼ����������****ö������enum
typedef struct ArcCell {
    VRType adj;		//�����ϵ����
    InfoType *info;	//�û������Ϣ��ָ��
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    VErtexType vexs[MAX_VERTEX_NUM];	//��������
    AdjMatrix arcs;		//�ڽӾ���
    int vexnum, arcnum;		//ͼ�ĵ�ǰ�������ͻ���
    GraphKind	kind;		//ͼ�������־
}MGraph;


int LocateVex(MGraph *G, VRType point)	//ȷ��ĳ��������ͼG�е�λ��
{
    int i, j;
    for (i = 0; i < G->vexnum; i++)
        if (G->vexs[i] == point)
            return i;

}//LocateVex


void CreatUDN(MGraph *G)	//�������飨�ڽӾ��󣩣�����������G
{
    int i, j, k;
    VRType origin, terminus, weight; 	//�ߵ����,�յ�,Ȩֵ
    printf("����ͼ�Ķ����� ����");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//������ֵ�洢��ȥ
    {
        printf("���붥��ֵ��");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???����
    {
        printf("����һ���ߵ������Լ�Ȩֵ");
        scanf("%d %d %d", &origin, &terminus ,&weight);
        i = LocateVex(G, origin);	//����LocateVex����ȷ�����(origin)���յ�(terminus)��G��λ��
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[j][i].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
        G->arcs[j][i].info = (InfoType *)malloc(sizeof(InfoType));
        *(G->arcs[i][j].info) = weight;
        *(G->arcs[j][i].info) = weight;
    }//for
    printf("�����ɹ�\n");
}//CreatUDN

void CreatDG(MGraph *G)		//����ͼ
{
    int i, j, k;
    VRType origin, terminus; 	//�ߵ����,�յ�
    printf("����ͼ�Ķ����� ����");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//������ֵ�洢��ȥ
    {
        printf("���붥��ֵ��");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???����
    {
        printf("����һ���ߵ�����յ�");
        scanf("%d %d", &origin, &terminus);
        i = LocateVex(G, origin);	//����LocateVex����ȷ�����(origin)���յ�(terminus)��G��λ��
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
    }//for
    printf("�����ɹ�\n");

}

void CreatDN(MGraph *G)		//������
{
    int i, j, k;
    VRType origin, terminus, weight; 	//�ߵ����,�յ�,Ȩֵ
    printf("����ͼ�Ķ����� ����");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//������ֵ�洢��ȥ
    {
        printf("���붥��ֵ��");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???����
    {
        printf("����һ���ߵ�����յ��Լ�Ȩֵ");
        scanf("%d %d %d", &origin, &terminus, &weight);
        i = LocateVex(G, origin);	//����LocateVex����ȷ�����(origin)���յ�(terminus)��G��λ��
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
        *(G->arcs[i][j].info) = weight;
    }//for
    printf("�����ɹ�\n");
}//CreatUDN


void CreatUDG(MGraph *G)	//����ͼ
{
    int i, j, k;
    VRType origin, terminus; 	//�ߵ����,�յ�
    printf("����ͼ�Ķ����� ����");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//������ֵ�洢��ȥ
    {
        printf("���붥��ֵ��");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???����
    {
        printf("����һ���ߵ�����");
        scanf("%d %d", &origin, &terminus);
        i = LocateVex(G, origin);	//����LocateVex����ȷ�����(origin)���յ�(terminus)��G��λ��
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[j][i].adj = 0;
    }//for
    printf("�����ɹ�\n");

}

void CreatGraph(MGraph *G)		//��������(�ڽӾ���)��ʾ������ͼG
{
    int kind;
    printf("����ͼ���ͣ�1.DG/2.DN/3.UDG/4.UDN��:");
    scanf("%d", &kind);
    switch (kind)
    {
        case 1: CreatDG(G);	break;
        case 2: CreatDN(G);	break;
        case 3:CreatUDG(G);	break;
        case 4:CreatUDN(G);	break;
        default: printf("ERROR!"); break;
    }//switch
}//CreatGraph

int main()
{
    MGraph G;
    CreatGraph(&G);

    return 0;
}