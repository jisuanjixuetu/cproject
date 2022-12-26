/*
文件名：ArrayNotation.c
描述：图的数组表示法
时间：2018/11/19
		2019.1.3补全
*/


#include<stdio.h>
#include <malloc.h>

//-------------图的数组（邻接矩阵）存储表示---------------
#define INFINITY 95533	// 最大值
#define MAX_VERTEX_NUM 20	//最大顶点个数
#define VRType int		//顶点关系类型，对无权图，用1或0表示相邻否；对带权图，则为权值类型
#define InfoType int	// 顶点信息类型
#define VErtexType int	//图顶点类型
typedef enum {DG,DN,UDG,UDN}GraphKind;	//图的种类（有向图，有向网，无向图，无向网）****枚举类型enum
typedef struct ArcCell {
    VRType adj;		//顶点关系类型
    InfoType *info;	//该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    VErtexType vexs[MAX_VERTEX_NUM];	//顶点向量
    AdjMatrix arcs;		//邻接矩阵
    int vexnum, arcnum;		//图的当前顶点数和弧数
    GraphKind	kind;		//图的种类标志
}MGraph;


int LocateVex(MGraph *G, VRType point)	//确定某个顶点在图G中的位置
{
    int i, j;
    for (i = 0; i < G->vexnum; i++)
        if (G->vexs[i] == point)
            return i;

}//LocateVex


void CreatUDN(MGraph *G)	//采用数组（邻接矩阵），构造无向网G
{
    int i, j, k;
    VRType origin, terminus, weight; 	//边的起点,终点,权值
    printf("输入图的顶点数 弧数");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//将顶点值存储进去
    {
        printf("输入顶点值：");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//初始化邻接矩阵
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???弧数
    {
        printf("输入一条边的两端以及权值");
        scanf("%d %d %d", &origin, &terminus ,&weight);
        i = LocateVex(G, origin);	//利用LocateVex函数确定起点(origin)及终点(terminus)在G中位置
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[j][i].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
        G->arcs[j][i].info = (InfoType *)malloc(sizeof(InfoType));
        *(G->arcs[i][j].info) = weight;
        *(G->arcs[j][i].info) = weight;
    }//for
    printf("创建成功\n");
}//CreatUDN

void CreatDG(MGraph *G)		//有向图
{
    int i, j, k;
    VRType origin, terminus; 	//边的起点,终点
    printf("输入图的顶点数 弧数");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//将顶点值存储进去
    {
        printf("输入顶点值：");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//初始化邻接矩阵
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???弧数
    {
        printf("输入一条边的起点终点");
        scanf("%d %d", &origin, &terminus);
        i = LocateVex(G, origin);	//利用LocateVex函数确定起点(origin)及终点(terminus)在G中位置
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
    }//for
    printf("创建成功\n");

}

void CreatDN(MGraph *G)		//有向网
{
    int i, j, k;
    VRType origin, terminus, weight; 	//边的起点,终点,权值
    printf("输入图的顶点数 弧数");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//将顶点值存储进去
    {
        printf("输入顶点值：");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//初始化邻接矩阵
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???弧数
    {
        printf("输入一条边的起点终点以及权值");
        scanf("%d %d %d", &origin, &terminus, &weight);
        i = LocateVex(G, origin);	//利用LocateVex函数确定起点(origin)及终点(terminus)在G中位置
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[i][j].info = (InfoType *)malloc(sizeof(InfoType));
        *(G->arcs[i][j].info) = weight;
    }//for
    printf("创建成功\n");
}//CreatUDN


void CreatUDG(MGraph *G)	//无向图
{
    int i, j, k;
    VRType origin, terminus; 	//边的起点,终点
    printf("输入图的顶点数 弧数");
    scanf("%d %d", &(G->vexnum), &(G->arcnum));
    for (i = 0; i < G->vexnum; i++)	//将顶点值存储进去
    {
        printf("输入顶点值：");
        scanf("%d", &(G->vexs[i]));
    }//for
    for (i = 0; i < G->vexnum; i++)	//初始化邻接矩阵
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }//for
    for (k = 0; k < G->arcnum; k++)	//	arcnum???弧数
    {
        printf("输入一条边的两端");
        scanf("%d %d", &origin, &terminus);
        i = LocateVex(G, origin);	//利用LocateVex函数确定起点(origin)及终点(terminus)在G中位置
        j = LocateVex(G, terminus);
        G->arcs[i][j].adj = 0;
        G->arcs[j][i].adj = 0;
    }//for
    printf("创建成功\n");

}

void CreatGraph(MGraph *G)		//采用数组(邻接矩阵)表示法构造图G
{
    int kind;
    printf("输入图类型（1.DG/2.DN/3.UDG/4.UDN）:");
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