#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <rpcproxy.h>

#define MaxSize 20
#define VertexType int
boolean visited[MaxSize];
typedef struct ArcNode{
    int adjvex;//the node that locate in the tail
    struct ArcNode*nextarc;//a pointer to the next vex
}ArcNode;//the information for the node

typedef struct Vnode{
    VertexType data;
    ArcNode *firstarc;//point to the vertect that related it first
}Vnode,AdjList[MaxSize];//the first node for the graph

typedef struct ALGraph{
    AdjList vertices;
    int vexnum;//the number for the vex
    int arcnum;//the number for the arc
    int kind;
}ALGraph;

struct queue{
    int front;
    int tail;
    int adjest[MaxSize];
}Queue;
int Locate_vex(ALGraph*G,VertexType vex){
    for(int i = 0;i<G->vexnum;i++){
        if(G->vertices[i].data==vex)
            return i;
    }
}

void CreatGraph(ALGraph*G){
    ArcNode *temp = NULL;
    VertexType vertex;//tou
    VertexType vertail;//wei
    int i,j,k;
    printf("Please enter the name of vertex of the graph:");
    for(i = 0;i<G->vexnum;i++){
        scanf("%d",&(G->vertices[i].data));
        getchar();
        G->vertices[i].firstarc = NULL;
    }
    printf("Please enter the vertex and vertail for each of the arc:\n");
    for(k = 1;k<=G->arcnum;k++){
        printf("Please enter the %d arc vertail:\n",k);
        scanf("%d",&vertail);
        getchar();
        printf("Please enter the %d arc vertex:\n",k);
        scanf("%d",&vertex);
        getchar();
        i = Locate_vex(G,vertail);
        j = Locate_vex(G,vertex);
        temp = (ArcNode*) malloc(sizeof (ArcNode));
        temp->adjvex = j;
        temp->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = temp;//touchafa
    }
}

void PrintGraph(const ALGraph*G) {
    int i;
    ArcNode *temp = NULL;
    //printf("the graph has %d vertexs:", G->vexnum);
    for (i = 0; i < G->vexnum; i++) {
        printf("%d", G->vertices[i].data);
    }
    //printf("the graph has %d arcs:", G->arcnum);
    for (i = 0; i < G->vexnum; i++) {
        printf("%d ->", G->vertices[i].data);
        temp = G->vertices[i].firstarc;
        while (temp) {
            printf("%d ", G->vertices[temp->adjvex].data);
            temp = temp->nextarc;
        }
        printf("\n");
    }
    printf("\n");
}

boolean DFS_Find_path(ALGraph *G,int i,int k){
    ArcNode *p;
    if(i==k)
        return true;
    else{
        visited[i]=true;
        for (p = G -> vertices[i].firstarc; p!=NULL;p = p -> nextarc){
            int j = p->adjvex;
            if(!visited[j] && DFS_Find_path(G,j,k))
                return true;
        }
    }
    return false;
}

//boolean BFS_Find_Path(ALGraph*G,int i,int j){
//    visited[i] = true;
//    Queue.front = 0;
//    Queue.tail = 0;
//    Queue.adjest[Queue.tail++] = i;
//    while(Queue.tail!=Queue.front){
//        int a = Queue.adjest[Queue.front++];
//        ArcNode *p = G -> vertices[a].firstarc;
//        while (p){
//            if(p ->adjvex==j)
//                return true;
//            else{
//                if(!visited[p->adjvex]){
//                    visited[p -> adjvex] = true;
//                    Queue.adjest[Queue.tail++]=p->adjvex;
//                }
//            }
//            p = p->nextarc;
//        }
//    }
//    return false;
//}
int main() {
    setbuf(stdout,0);
    ALGraph G;
    printf("Direct graph store structure:\n");
    printf("Please enter the number of the vertexs:");
    scanf("%d",&G.vexnum);
    printf("Please enter the number of the arcs:");
    scanf("%d",&G.arcnum);
    CreatGraph(&G);
    PrintGraph(&G);
    printf("\n");
    printf("please enter the vertail and the vertex:\n");
    int i,k;
    while(scanf("%d %d",&i,&k)==2) {
		for (int s = 0; s < MaxSize;s++) {
			visited[s]=false;
}
		int a = Locate_vex(&G, i);
		int b = Locate_vex(&G, k);
//		if (BFS_Find_Path(&G, a, b))
//			printf("exist\n");
//		else
//			printf("unexisted\n");
		if (DFS_Find_path(&G, a, b))
			printf("exist\n");
		else
			printf("unexisted\n");
		}
    return 0;
}