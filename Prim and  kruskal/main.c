#include<stdio.h>
#include<stdlib.h>
#include <rpcproxy.h>
#include <stdbool.h>

/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef int DataType;        /* ����洢������������Ϊ���� */
boolean Visited[MaxVertexNum] = { false };
/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
    DataType Data[MaxVertexNum];      /* �涥������� */
    /* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */



MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӾ��� */
    /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
    for (V = 0; V<Graph->Nv; V++)
        for (W = 0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    /* ����� <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* ��������ͼ����Ҫ�����<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    printf("�����붥�������\n");
    scanf("%d", &Nv);   /* ���붥����� */
    getchar();
    Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */
    printf("�����������\n");
    scanf("%d", &(Graph->Ne));
    getchar();/* ������� */
    if (Graph->Ne != 0)
    { /* ����б� */
        E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
        /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (i = 0; i<Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{ /* ����δ����¼������dist��С�� */
    Vertex MinV, V;
    WeightType MinDist = INFINITY;

    for (V = 0; V<Graph->Nv; V++) {
        if (dist[V] != 0 && dist[V]<MinDist) {
            /* ��Vδ����¼����dist[V]��С */
            MinDist = dist[V]; /* ������С���� */
            MinV = V; /* ���¶�Ӧ���� */
        }
    }
    if (MinDist < INFINITY) /* ���ҵ���Сdist */
        return MinV; /* ���ض�Ӧ�Ķ����±� */
    else return -1;  /* �������Ķ��㲻���ڣ�����-1��Ϊ��� */
}

int Prim(MGraph Graph)
{
    WeightType dist[MaxVertexNum], TotalWeight;
    Vertex parent[MaxVertexNum], V, W;
    int VCount;
    Edge E;

    /* ��ʼ����Ĭ�ϳ�ʼ���±���0 */
    for (V = 0; V<Graph->Nv; V++) {
        /* ���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪINFINITY */
        dist[V] = Graph->G[0][V];
        parent[V] = 0; /* ���Ҷ������ж���ĸ���㶼�ǳ�ʼ��0 */
    }
    TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
    VCount = 0;      /* ��ʼ����¼�Ķ����� */

    /* ����ʼ��0��¼��MST */
    dist[0] = 0;
    VCount++;
    parent[0] = -1; /* ��ǰ������0 */

    while (1) {
        V = FindMinDist(Graph, dist);
        /* V = δ����¼������dist��С�� */
        if (V == -1) /* ��������V������ */
            break;   /* �㷨���� */

        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for (W = 0; W<Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
            if (dist[W] != 0 && Graph->G[V][W]<INFINITY) {
                /* ��W��V���ڽӵ㲢��δ����¼ */
                if (Graph->G[V][W] < dist[W]) {
                    /* ����¼Vʹ��dist[W]��С */
                    dist[W] = Graph->G[V][W]; /* ����dist[W] */
                    parent[W] = V; /* ������ */
                }
            }
        printf("%d--%d\n", parent[V], V);
    } /* while����*/
    if (VCount < Graph->Nv) /* MST���յĶ��㲻��|V|�� */
        TotalWeight = -1;
    return TotalWeight;   /* �㷨ִ����ϣ�������СȨ�غͻ������ */
}

///*-------------------- ���㲢�鼯���� --------------------*/
//typedef Vertex ElementType; /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
//typedef Vertex SetName;     /* Ĭ���ø������±���Ϊ�������� */
//typedef ElementType SetType[MaxVertexNum]; /* ���輯��Ԫ���±��0��ʼ */
//
//void InitializeVSet(SetType S, int N)
//{ /* ��ʼ�����鼯 */
//    ElementType X;
//
//    for (X = 0; X<N; X++) S[X] = -1;
//}
//
//void Union(SetType S, SetName Root1, SetName Root2)
//{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
//    /* ��֤С���ϲ���󼯺� */
//    if (S[Root2] < S[Root1]) { /* �������2�Ƚϴ� */
//        S[Root2] += S[Root1];     /* ����1���뼯��2  */
//        S[Root1] = Root2;
//    }
//    else {                         /* �������1�Ƚϴ� */
//        S[Root1] += S[Root2];     /* ����2���뼯��1  */
//        S[Root2] = Root1;
//    }
//}
//
//SetName Find(SetType S, ElementType X)
//{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
//    if (S[X] < 0) /* �ҵ����ϵĸ� */
//        return X;
//    else
//        return S[X] = Find(S, S[X]); /* ·��ѹ�� */
//}
//
//boolean CheckCycle(SetType VSet, Vertex V1, Vertex V2)
//{ /* �������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɻ�· */
//    Vertex Root1, Root2;
//
//    Root1 = Find(VSet, V1); /* �õ�V1��������ͨ������ */
//    Root2 = Find(VSet, V2); /* �õ�V2��������ͨ������ */
//
//    if (Root1 == Root2) /* ��V1��V2�Ѿ���ͨ����ñ߲���Ҫ */
//        return false;
//    else { /* ����ñ߿��Ա��ռ���ͬʱ��V1��V2����ͬһ��ͨ�� */
//        Union(VSet, Root1, Root2);
//        return true;
//    }
//}
//
//int compare(const void *a, const void *b)
//{ /* �Ƚ����������ǽ������� */
//    return (((const struct ENode*)a)->Weight - ((const struct ENode*)b)->Weight);
//}
//
//void InitializeESet(MGraph Graph, Edge ESet)
//{ /* ��ͼ�ıߴ�������ESet�����ҳ�ʼ��Ϊ��С�� */
//    Vertex V, W;
//    int ECount;
//
//    /* ��ͼ�ıߴ�������ESet */
//    ECount = 0;
//    for (V = 0; V<Graph->Nv; V++)
//        for (W = V + 1; W<Graph->Nv; W++) {
//            ESet[ECount].V1 = V;
//            ESet[ECount].V2 = W;
//            ESet[ECount++].Weight = Graph->G[V][W];
//        }
//    /* ��ͼ�ı����� */
//    qsort(ESet, Graph->Ne, sizeof(struct ENode), compare);
//}
//
//int Kruskal(MGraph Graph)
//{
//    WeightType TotalWeight;
//    int ECount, NextEdge;
//    SetType VSet; /* �������� */
//    Edge ESet;    /* ������ */
//
//    InitializeVSet(VSet, Graph->Nv); /* ��ʼ�����㲢�鼯 */
//    ESet = (Edge)malloc(sizeof(struct ENode)*Graph->Ne);
//    InitializeESet(Graph, ESet); /* ��ʼ���ߵ���С�� */
//    TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
//    ECount = 0;      /* ��ʼ����¼�ı��� */
//
//    while (ECount < Graph->Nv - 1) {  /* ���ռ��ı߲����Թ�����ʱ */
//        /* ����ñߵļ��벻���ɻ�·�������˽�㲻����ͬһ��ͨ�� */
//        for (int i = 0; i<Graph->Ne; i++)
//            if (CheckCycle(VSet, ESet[i].V1, ESet[i].V2) == true) {
//                printf("%d--%d\n", ESet[i].V1, ESet[i].V2);
//                TotalWeight += ESet[i].Weight; /* �ۼ�Ȩ�� */
//                ECount++; /* �������б�����1 */
//            }
//    }
//    if (ECount < Graph->Nv - 1)
//        TotalWeight = -1; /* ���ô����ǣ���ʾ������������ */
//    return TotalWeight;
//}

int main()
{
    MGraph Graph = BuildGraph();
    printf("Prim�㷨������С������:\n");
    int totalweightP = Prim(Graph);
    printf("��Ȩֵ%d\n", totalweightP);
//    printf("\nKruskal�㷨������С������:\n");
//    int totalweightK = Kruskal(Graph);
//    printf("��Ȩֵ%d\n", totalweightK);
    system("pause");
}

