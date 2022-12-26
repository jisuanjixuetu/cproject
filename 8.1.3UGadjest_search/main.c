#include <stdio.h>
#include <stdlib.h>
#include <rpcproxy.h>
#include <stdbool.h>

#define MaxSize 20
#define VertexType int
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

boolean visited[MaxSize];
int Locate_vex(ALGraph*G,VertexType vex){
    for(int i = 0;i<G->vexnum;i++){
        if(G->vertices[i].data==vex)
            return i;
    }
}

void CreatGraph(ALGraph*G){
    ArcNode *temp = NULL;
    ArcNode *temp1 = NULL;
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
        printf("Please enter the %d arc vertail:",k);
        scanf("%d",&vertail);
        getchar();
        printf("Please enter the %d arc vertex:",k);
        scanf("%d",&vertex);
        getchar();
        i = Locate_vex(G,vertail);
        j = Locate_vex(G,vertex);
        temp = (ArcNode*) malloc(sizeof (ArcNode));
        temp->adjvex = j;
        temp->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = temp;//touchafa
        temp1 = (ArcNode * ) malloc(sizeof(ArcNode));
        temp1->adjvex = i;
        temp1->nextarc = G-> vertices[j].firstarc;
        G-> vertices[j].firstarc = temp1;
    }
}
boolean path_search(ALGraph *G,int a,int b,int k){
    ArcNode *p;
    if(a==b&&k==0)
        return true;
    else if(k==0)
        return false;
    else{
        for(p=G -> vertices[a].firstarc; p!=NULL;p=p -> nextarc){
            int s = p->adjvex;
            if(path_search(G,s,b,k-1))
                return true;
        }
    }
}
void PrintGraph(const ALGraph*G) {
    int i;
    ArcNode *temp = NULL;
    printf("the graph has %d vertexs:", G->vexnum);
    for (i = 0; i < G->vexnum; i++) {
        printf("%d", G->vertices[i].data);
    }
    printf("the graph has %d arcs:", G->arcnum);
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
int main() {
    setbuf(stdout,0);
    ALGraph G;
    printf("Direct graph store structure:\n");
    printf("Please enter the number of the vertexs:");
    scanf("%d",&G.vexnum);
    printf("Please enter the number of the arcs:");
    scanf("%d",&G.arcnum);
    CreatGraph(&G);
    printf("please enter the vertail and the vertex and the length of the path :\n");
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3) {
		for(int s = 0;s<MaxSize;s++){
			visited[s] = false;
		}
		int i = Locate_vex(&G, a);
		int j = Locate_vex(&G, b);
		//PrintGraph(&G);
		if (path_search(&G, i, j, c))
			printf("exist\n");
		else
			printf("unexsit\n");
		printf("\n");
	}
    return 0;
}
