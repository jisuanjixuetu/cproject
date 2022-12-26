#include <stdio.h>
#include <malloc.h>

#define INFINITY 999999
#define MAX_VERTEX_NUM 20
#define VRType int
#define InfoType int
#define VertexType char
typedef enum{DG,DN,UDG,UGN}GraphKind;
typedef struct ArcCell{
VRType adj;
InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
VertexType vexs[MAX_VERTEX_NUM];
AdjMatrix  arcs;
int vexnum;
int arcnum;
GraphKind kind;
}MGraph;

int LocateVex(MGraph*G,VertexType point){
for(int i;i<G->vexnum;i++)
{
    if (G -> vexs[i]== point)
        return i;
}
}

void CreatDG(MGraph * G){
VertexType original,terminal;
int i,j,k;
    printf("please enter the number of point and the number of the arc:");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for( i = 0;i < G -> vexnum; i++){
        printf("enter the point :");
        scanf("%c",&(G->vexs[i]));
    }
    printf("please enter point:");
    for ( i = 0; i < G -> vexnum; i++)
        for ( j = 0; j < G -> vexnum; j++) {
            G->arcs[i][j].adj = INFINITY;
            G -> arcs[i][j].info = NULL;
}
    for(k = 0;k<G -> vexnum; k++){
        printf("please enter the original and terminal:");
        scanf("%c %c",&original,&terminal);
        i = LocateVex(G,original);
        j = LocateVex(G,terminal);
        G -> arcs[i][j].adj = 1;
        G -> arcs[i][j].info =(InfoType*)malloc(sizeof (InfoType));
    }
    printf("Well done\n");
}

void CreatDN(MGraph*G){
    VertexType original,terminal;
    VRType weight;
    int i,j,k;
    printf("please enter the number of point and the number of the arc:");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
for (i = 0; i < G -> vexnum; i++) {
printf("please enter the point :");
    scanf("%c",&(G->vexs[i]));
}
for(i = 0; i < G -> vexnum; i++)
    for (j = 0; j < G -> vexnum; j++) {
        G -> arcs[i][j].adj =INFINITY;
        G -> arcs[i][j].info = NULL;
    }
for(k = 0; k < G -> arcnum; k++){
    printf("please enter the original and terminal weight for the arc:");
    scanf("%c %c %d",&original,&terminal,&weight);
    i = LocateVex(G,original);
    j = LocateVex(G,terminal);
    G -> arcs[i][j].adj = 1;
    G -> arcs[i][j].info = (InfoType*) malloc(sizeof (InfoType));
    *(G-> arcs[i][j].info) = weight;
}
    printf("well done\n");
}

void CreatUDG(MGraph*G){
    int i,j,k;
    VertexType original,terminal;
    printf("please enter the number of the point and the number of the arc:");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for(i = 0;i<G->vexnum;i++)
        for (j = 0; j < G -> vexnum; j++) {
            G->arcs[i][j].adj = INFINITY;
            G -> arcs[i][j].info = NULL;
        }

    for (i = 0; i < G -> vexnum; i++) {
        printf("please enter the point:");
        scanf("%c",&(G->vexs[i]));
    }
    for(k = 0;k < G -> vexnum; k++){
        printf("please enter the original and the terminal of each arc:");
        scanf("%c %c",&original,&terminal);
        i = LocateVex(G,original);
        j = LocateVex(G,terminal);
        G->arcs[i][j].adj = 1;
        G->arcs[i][j].adj = 1;
        G -> arcs[i][j].info = (InfoType*) malloc(sizeof (InfoType));
    }
    printf("well done\n");
}

void CreatUDN(MGraph*G){
    int i,j,k;
    VertexType original,terminal;
    InfoType weight;
    printf("please enter the number of point and the number of the arc:");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for(i = 0;i<G->vexnum;i++){
        printf("please enter the point:");
        scanf("%c",&(G->vexs[i]));
    }
    for (i = 0; i < G -> vexnum; i++) {
        for (j = 0; j < G -> vexnum; j++) {
            printf("please enter the original and the terminal weight for the arc:");
            scanf("%c %c %d",&original,&terminal,&weight);
            i = LocateVex(G,original);
            j = LocateVex(G,terminal);
            G->arcs[i][j].adj = 1;
            G -> arcs[j][i].adj = 1;
            G->arcs[i][j].info = (InfoType*) malloc(sizeof (InfoType));
            G-> arcs[j][i].info= (InfoType*)malloc(sizeof(InfoType));
            *(G -> arcs[i][j].info) = weight;
            *(G-> arcs[j][i].info) = weight;
        }
    }
    printf("well done\n");
}

void CreatGraph(MGraph*G){
    int kind;
    printf("1.DG,2.UDG,3.DN,4.UDN");
    scanf("%d",&kind);
    switch (kind) {
        case 1:
            CreatDG(G);
            break;
            case 2 :
                CreatUDG(G);
            break;
            case 3 :
                CreatUDG(G);
            break;
            case 4 :
                CreatUDN(G);
            break;
            default :
                printf("Error\n");
    }
}
int main() {
MGraph G;
    CreatGraph(&G);
}
