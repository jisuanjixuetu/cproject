#include<stdio.h>
#include<stdlib.h>
#include <rpcproxy.h>
#include <stdbool.h>

/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef int DataType;        /* 顶点存储的数据类型设为整型 */
boolean Visited[MaxVertexNum] = { false };
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
    DataType Data[MaxVertexNum];      /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */



MGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接矩阵 */
    /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
    for (V = 0; V<Graph->Nv; V++)
        for (W = 0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    printf("请输入顶点个数：\n");
    scanf("%d", &Nv);   /* 读入顶点个数 */
    getchar();
    Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */
    printf("请输入边数：\n");
    scanf("%d", &(Graph->Ne));
    getchar();/* 读入边数 */
    if (Graph->Ne != 0)
    { /* 如果有边 */
        E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i = 0; i<Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{ /* 返回未被收录顶点中dist最小者 */
    Vertex MinV, V;
    WeightType MinDist = INFINITY;

    for (V = 0; V<Graph->Nv; V++) {
        if (dist[V] != 0 && dist[V]<MinDist) {
            /* 若V未被收录，且dist[V]更小 */
            MinDist = dist[V]; /* 更新最小距离 */
            MinV = V; /* 更新对应顶点 */
        }
    }
    if (MinDist < INFINITY) /* 若找到最小dist */
        return MinV; /* 返回对应的顶点下标 */
    else return -1;  /* 若这样的顶点不存在，返回-1作为标记 */
}

int Prim(MGraph Graph)
{
    WeightType dist[MaxVertexNum], TotalWeight;
    Vertex parent[MaxVertexNum], V, W;
    int VCount;
    Edge E;

    /* 初始化。默认初始点下标是0 */
    for (V = 0; V<Graph->Nv; V++) {
        /* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
        dist[V] = Graph->G[0][V];
        parent[V] = 0; /* 暂且定义所有顶点的父结点都是初始点0 */
    }
    TotalWeight = 0; /* 初始化权重和     */
    VCount = 0;      /* 初始化收录的顶点数 */

    /* 将初始点0收录进MST */
    dist[0] = 0;
    VCount++;
    parent[0] = -1; /* 当前树根是0 */

    while (1) {
        V = FindMinDist(Graph, dist);
        /* V = 未被收录顶点中dist最小者 */
        if (V == -1) /* 若这样的V不存在 */
            break;   /* 算法结束 */

        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for (W = 0; W<Graph->Nv; W++) /* 对图中的每个顶点W */
            if (dist[W] != 0 && Graph->G[V][W]<INFINITY) {
                /* 若W是V的邻接点并且未被收录 */
                if (Graph->G[V][W] < dist[W]) {
                    /* 若收录V使得dist[W]变小 */
                    dist[W] = Graph->G[V][W]; /* 更新dist[W] */
                    parent[W] = V; /* 更新树 */
                }
            }
        printf("%d--%d\n", parent[V], V);
    } /* while结束*/
    if (VCount < Graph->Nv) /* MST中收的顶点不到|V|个 */
        TotalWeight = -1;
    return TotalWeight;   /* 算法执行完毕，返回最小权重和或错误标记 */
}

///*-------------------- 顶点并查集定义 --------------------*/
//typedef Vertex ElementType; /* 默认元素可以用非负整数表示 */
//typedef Vertex SetName;     /* 默认用根结点的下标作为集合名称 */
//typedef ElementType SetType[MaxVertexNum]; /* 假设集合元素下标从0开始 */
//
//void InitializeVSet(SetType S, int N)
//{ /* 初始化并查集 */
//    ElementType X;
//
//    for (X = 0; X<N; X++) S[X] = -1;
//}
//
//void Union(SetType S, SetName Root1, SetName Root2)
//{ /* 这里默认Root1和Root2是不同集合的根结点 */
//    /* 保证小集合并入大集合 */
//    if (S[Root2] < S[Root1]) { /* 如果集合2比较大 */
//        S[Root2] += S[Root1];     /* 集合1并入集合2  */
//        S[Root1] = Root2;
//    }
//    else {                         /* 如果集合1比较大 */
//        S[Root1] += S[Root2];     /* 集合2并入集合1  */
//        S[Root2] = Root1;
//    }
//}
//
//SetName Find(SetType S, ElementType X)
//{ /* 默认集合元素全部初始化为-1 */
//    if (S[X] < 0) /* 找到集合的根 */
//        return X;
//    else
//        return S[X] = Find(S, S[X]); /* 路径压缩 */
//}
//
//boolean CheckCycle(SetType VSet, Vertex V1, Vertex V2)
//{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
//    Vertex Root1, Root2;
//
//    Root1 = Find(VSet, V1); /* 得到V1所属的连通集名称 */
//    Root2 = Find(VSet, V2); /* 得到V2所属的连通集名称 */
//
//    if (Root1 == Root2) /* 若V1和V2已经连通，则该边不能要 */
//        return false;
//    else { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
//        Union(VSet, Root1, Root2);
//        return true;
//    }
//}
//
//int compare(const void *a, const void *b)
//{ /* 比较两整数。非降序排列 */
//    return (((const struct ENode*)a)->Weight - ((const struct ENode*)b)->Weight);
//}
//
//void InitializeESet(MGraph Graph, Edge ESet)
//{ /* 将图的边存入数组ESet，并且初始化为最小堆 */
//    Vertex V, W;
//    int ECount;
//
//    /* 将图的边存入数组ESet */
//    ECount = 0;
//    for (V = 0; V<Graph->Nv; V++)
//        for (W = V + 1; W<Graph->Nv; W++) {
//            ESet[ECount].V1 = V;
//            ESet[ECount].V2 = W;
//            ESet[ECount++].Weight = Graph->G[V][W];
//        }
//    /* 将图的边排序 */
//    qsort(ESet, Graph->Ne, sizeof(struct ENode), compare);
//}
//
//int Kruskal(MGraph Graph)
//{
//    WeightType TotalWeight;
//    int ECount, NextEdge;
//    SetType VSet; /* 顶点数组 */
//    Edge ESet;    /* 边数组 */
//
//    InitializeVSet(VSet, Graph->Nv); /* 初始化顶点并查集 */
//    ESet = (Edge)malloc(sizeof(struct ENode)*Graph->Ne);
//    InitializeESet(Graph, ESet); /* 初始化边的最小堆 */
//    TotalWeight = 0; /* 初始化权重和     */
//    ECount = 0;      /* 初始化收录的边数 */
//
//    while (ECount < Graph->Nv - 1) {  /* 当收集的边不足以构成树时 */
//        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
//        for (int i = 0; i<Graph->Ne; i++)
//            if (CheckCycle(VSet, ESet[i].V1, ESet[i].V2) == true) {
//                printf("%d--%d\n", ESet[i].V1, ESet[i].V2);
//                TotalWeight += ESet[i].Weight; /* 累计权重 */
//                ECount++; /* 生成树中边数加1 */
//            }
//    }
//    if (ECount < Graph->Nv - 1)
//        TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */
//    return TotalWeight;
//}

int main()
{
    MGraph Graph = BuildGraph();
    printf("Prim算法构造最小生成树:\n");
    int totalweightP = Prim(Graph);
    printf("总权值%d\n", totalweightP);
//    printf("\nKruskal算法构造最小生成树:\n");
//    int totalweightK = Kruskal(Graph);
//    printf("总权值%d\n", totalweightK);
    system("pause");
}

