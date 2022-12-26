#include <stdio.h>
#define MAXSIZE 10
#define INFINITY 66566
typedef int ElementType;
typedef struct vertex{
	ElementType data;
	int weight;
}vertex;

typedef struct Graph{
	vertex G[MAXSIZE];
	int size;
}Graph;

int get_index(Graph MyGraph,ElementType vertex) {
	for (int i = 0; i < MyGraph.size; i++) {
		if (MyGraph.G[i].data == vertex)
			return i;
		else
			return -1;
	}
}
void dijistra(Graph*T,Graph S,int G[MAXSIZE][MAXSIZE]){
	for (int i = 0; i < MyGraph.size; i++) {

	}
}
int main() {
	int graph[MAXSIZE][MAXSIZE];
	Graph T,S;
	printf("Hello, World!\n");
	return 0;
}
