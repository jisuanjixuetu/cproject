#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
#define VertexType int
int rudu[MaxSize];
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
}ALGraph;

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
		rudu[i] = 0;
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
		rudu[j]++;
		temp->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = temp;//touchafa
	}
}

void PrintGraph(const ALGraph*G) {
	int i;
	ArcNode *temp = NULL;
	printf("the graph has %d vertexs:", G->vexnum);
	for (i = 0; i < G->vexnum; i++) {
		printf("%d", G->vertices[i].data);
	}
	printf("th graph has %d arcs:", G->arcnum);
	for (i = 0; i < G->vexnum; i++) {
		printf("%d %d-> ", G->vertices[i].data,rudu[i]);
		temp = G->vertices[i].firstarc;
		while (temp) {
			printf("%d %d ", G->vertices[temp->adjvex].data,rudu[temp -> adjvex]);
			temp = temp->nextarc;
		}
	}
	printf("\n");
}

void TopologicalSort(ALGraph *G){
	struct topo{
		int ver[MaxSize];
		int front;
		int rear;
	}topo;
	int count = 0;
	topo.rear = topo.front = 0;
	for(int i = 0;i<G->vexnum;i++){
		if(rudu[i]==0){
			topo.ver[topo.rear++] = i;
		}
		while (topo.rear>topo.front){
//			printf("%d",G-> vertices[topo.rear].data);
			count++;
			topo.front++;
			ArcNode *temp;
			temp = G->vertices[topo.rear].firstarc;
			while (temp) {
			    rudu[temp->adjvex]--;
				if(rudu[temp->adjvex]==0){
					topo.ver[topo.rear++] = temp->adjvex;
				}
				temp = temp->nextarc;
			}
		}
		}
	if(count<G->vexnum)
		printf("error");
	else
	{
		for (int j = 0;j<G -> vexnum; j++) {
			printf("%d\n",G->vertices[topo.ver[j]]);
		}
	}
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
//	PrintGraph(&G);
	printf("\n");
	return 0;
}
