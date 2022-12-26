#include <stdio.h>
#include <rpcproxy.h>
#include <stdbool.h>

#define MaxVertexSize 100//the Max Size of the tree is 100
#define INFINITY 600000
boolean visited[MaxVertexSize] = {false};
typedef struct Enode {
	int v1, v2;
	int weight;
} Enode, *PtrToEnode;

typedef struct Gnode {
	int numOfVertex;
	int numOfEdge;
	int graph[MaxVertexSize][MaxVertexSize];
} Gnode, *PtrToGnode;

PtrToGnode CreatGraph(int VertexNumber) {
	int v, m;
	PtrToGnode Graph;
	Graph = (PtrToGnode) malloc(sizeof(Gnode));
	Graph->numOfVertex = VertexNumber;
	Graph->numOfEdge = 0;
	for (v = 0; v < Graph->numOfVertex; v++) {
		for (m = 0; m < Graph->numOfVertex; m++) {
			Graph->graph[v][m] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(PtrToGnode Graph, PtrToEnode E) {
	Graph->graph[E->v1][E->v2] = E->weight;
	Graph->graph[E->v2][E->v1] = E->weight;
}

PtrToGnode BuildGraph() {
	PtrToGnode Graph;
	PtrToEnode Edge;
	printf("please enter the number of the vertex:\n");
	scanf("%d", &(Graph->numOfVertex));
	getchar();
	Graph = CreatGraph(Graph->numOfVertex);
	printf("please enter the number of the edge:\n");
	scanf("%d", &(Graph->numOfEdge));
	getchar();
	if (Graph->numOfEdge != 0) {
		Edge = (PtrToEnode) malloc(sizeof(Enode));
		for (int i = 0; i < Graph->numOfEdge; i++) {
			printf("please enter the vertex and the vertail and the weight of the %d Edge:\n", i+1);
			scanf("%d %d %d", &Edge->v1, &Edge->v2, &Edge->weight);
			getchar();
			InsertEdge(Graph, Edge);
		}
	}
	return Graph;
}


int FindMinDist(PtrToGnode Graph, int dist[]) {
	int MinVretex;
	int MinDist = INFINITY;
	for (int i = 0; i < Graph->numOfVertex; i++) {
		if (dist[i] != 0 && dist[i] < MinDist) {
			MinDist = dist[i];
			MinVretex = i;
		}
	}
	if (MinDist < INFINITY) {
		return MinVretex;
	} else {
		return -1;
	}
}

int Prim(PtrToGnode Graph) {
	int dist[MaxVertexSize];
	int TotalWeight;
	int Parent[MaxVertexSize];
	int v, w;
	int VertexCount;
	PtrToEnode Edge;
	for (v = 0; v < Graph->numOfVertex; v++) {
		dist[v] = Graph->graph[0][v];
		Parent[v] = 0;
	}
	TotalWeight = 0;
	VertexCount = 0;
	dist[0] = 0;
	VertexCount++;
	Parent[0] = -1;
	while (1) {
		v = FindMinDist(Graph, dist);
		if (v == -1)
			break;
		TotalWeight += dist[v];
		dist[v] = 0;
		VertexCount++;
		for (w = 0; w < Graph->numOfVertex; w++) {
			if (dist[w] != 0 && Graph->graph[v][w] < INFINITY) {
				if (Graph->graph[v][w] < dist[w]) {
					dist[w] = Graph->graph[v][w];
					Parent[w] = v;
				}
			}
		}
		printf("%d--%d\n", Parent[v]+1, v+1);
	}
	if (VertexCount < Graph->numOfVertex)
		return -1;
	return TotalWeight;

}

//void InitializeVset(int s[],int n){
//	int x;
//	for (x = 0; x < n; x++) {
//	    s[x] = -1;
//	}
//}
//
//void Union(int s[],int root1,int root2){
//	if(s[root2]<s[root1]){
//		s[root2]+=s[root1];
//		s[root1] = root2;
//	} else{
//		s[root1]+=s[root2];
//		s[root2]=root1;
//	}
//}
//
//int Find(int s[],int x){
//	if(s[x]<0){
//		return x;
//	}
//	else {
//	    s[x] = Find(s,s[x]);
//		return s[x];
//	}
//}
//boolean CheckCycle(int VSet,int V1,int V2){
//	int root1, root2;
//	root1 = Find(VSet,V1);
//	root2 = Find(VSet,V2);
//	if (root1 == root2) {
//	    return false;
//	}
//	else {
//		Union(VSet,root1,root2);
//		return true;
//	}
//}
//
//int compare(const void *a,const void *b){
//	return (((const struct Enode*)a)->weight-((const struct Enode*)b)->weight);
//}
//
//void InitializeESet(PtrToGnode Graph,PtrToEnode Eset){
//	int v,w;
//	int Ecount;
//	Ecount = 0;
//	for (v = 0; v < Graph->numOfVertex;v++) {
//		for(w = v+1;w<Graph -> numOfVertex; w++){
//			Eset[Ecount].v1 = v;
//			Eset[Ecount].v2 = w;
//			Eset[Ecount++].weight = Graph->graph[v][w];
//		}
//}
//	qsort(Eset,Graph->numOfVertex,sizeof (struct Enode),compare);
//}
int main() {
		PtrToGnode MyGraph;
		MyGraph = BuildGraph();
		printf("prim to build the tree:\n");
		int TotalWeight = Prim(MyGraph);
		printf("the total weight is %d\n", TotalWeight);
	}