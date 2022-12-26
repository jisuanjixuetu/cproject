#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
#define VertexType char
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
        scanf("%c",&(G->vertices[i].data));
        getchar();
        G->vertices[i].firstarc = NULL;
    }
    printf("Please enter the vertex and vertail for each of the arc:\n");
    for(k = 1;k<=G->arcnum;k++){
        printf("Please enter the %d arc vertail:",k);
        scanf("%c\n",&vertail);
        printf("Please enter the %d arc vertex:",k);
        scanf("%c\n",&vertex);
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
    printf("the graph has %d vertexs:", G->vexnum);
    for (i = 0; i < G->vexnum; i++) {
        printf("%c", G->vertices[i].data);
    }
    printf("th graph has %d arcs£º", G->arcnum);
    for (i = 0; i < G->vexnum; i++) {
        printf("%c ->", G->vertices[i].data);
        temp = G->vertices[i].firstarc;
        while (temp) {
            printf("%c ", G->vertices[temp->adjvex].data);
            temp = temp->nextarc;
        }
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
    PrintGraph(&G);
    printf("\n");
    return 0;
}
