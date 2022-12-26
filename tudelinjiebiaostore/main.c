#include <stdio.h>
#include <stdlib.h>


#define MaxNum 10  //最大顶点数

//表结点
typedef struct endoe
{
    int adjvex;
    struct endoe *next;
}endoe;

//定点结点
typedef struct vnode
{
    char vertex;
    endoe * first_edge;
}node;

//图结构
typedef struct ALGraph
{
    struct vnode adj_list[MaxNum];
    int n,e;
} ALGraph;

//定位顶点Vex的下标位置
int Locate_vex(ALGraph* G,char vex)
{
    for(int i=0;i<G->n;++i)
        if(G->adj_list[i].vertex==vex)
            return i;
}

//创建图
void CreateGraph(ALGraph * G)
{
    endoe* temp=NULL;
    int vex1,vex2;
    int i,j,k;
    printf("\n请输入有向图的顶点名称：");

    for(i=0;i<G->n;++i)
    {
        scanf("%c",&G->adj_list[i].vertex);
        G->adj_list[i].first_edge=NULL;
    }

    printf("\n请输入有向图中每条弧的弧尾顶点和弧头顶点名称：\n");

    for(k=1;k<=G->e;++k)
    {
        printf("\n请输入第 %d 条弧的弧尾顶点名称：",k);
        scanf("%c",&vex1);
        printf("请输入第 %d 条弧的弧头顶点名称：",k);
        scanf("%c",&vex2);

        i=Locate_vex(G,vex1);
        j=Locate_vex(G,vex2);

        temp=(endoe*)malloc(sizeof(endoe));
        temp->adjvex=j;
        temp->next=G->adj_list[i].first_edge;
        G->adj_list[i].first_edge=temp;//
    }
}

//打印图的信息
void PrintGraph(const ALGraph * G)
{
    int i;
    endoe* temp=NULL;

    printf("\n\n有向图有 %d 个顶点：",G->n);
    for(i=0;i<G->n;++i)
        printf(" %c ",G->adj_list[i].vertex);

    printf("\n\n有向图有 %d 条弧：",G->e);
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

//测试代码
int main()
{
    ALGraph G;

    printf("\n有向图的邻接表结构存储.....");

    printf("\n\n请输入有向图的顶点数：");
    scanf("%d",&G.n);

    printf("\n请输入有向图有多少条弧：");
    scanf("%d",&G.e);

    CreateGraph(&G);
    PrintGraph(&G);

    printf("\n");

    return 0;
}
