#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct EdgeNode
{   int adjvex;
	struct EdgeNode *next;
	int weight;
}EdgeNode;
typedef struct VertexNode
{	int data;
	EdgeNode *firstedge;
}VertexNode;
typedef struct
{	VertexNode adjlist[20];
	int n,e;
}GraphAdjlist;
int visited[10];

void create(GraphAdjlist *G)
{	int i,j,k;
	EdgeNode *e;
	printf("please input the number of the vertex and the arc\n");
	scanf("%d %d",&G->n,&G->e);
	getchar();
	printf("please input the vertex\n");
	for(i=0;i<G->n;i++)
	{   scanf("%d",&G->adjlist[i].data);
		G->adjlist[i].firstedge=NULL;
		getchar();
	}
	for(k=0;k<G->e;k++)
	{   printf("please enter the vertex on the side of the %d arc\n",k+1);
		scanf("%d %d",&i,&j);
		getchar();
		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=e;

//		e=(EdgeNode *)malloc(sizeof(EdgeNode));
//		e->adjvex=i;
//		e->next=G->adjlist[j].firstedge;
//		G->adjlist[j].firstedge=e;
	 }
	printf("\n");
}
void DFS(GraphAdjlist *G,int i)
{	EdgeNode *p;
	visited[i]=1;
	printf("%d ",G->adjlist[i].data);
	p=G->adjlist[i].firstedge;
	while(p!=NULL)
	{	if(visited[p->adjvex]==0)
		  DFS(G,p->adjvex);
		p=p->next;
	}
}
void DFSTraverse(GraphAdjlist *G)
{	int i;
	for(i=0;i<G->n;i++)
	  visited[i]=0;
	for(i=0;i<G->n;i++)
	  if(visited[i]==0)
	    DFS(G,i);
}
void BFS(GraphAdjlist *G,int v)
{	EdgeNode *p;
	int queue[max],front=0,rear=0;//??????????в??????
	int w,i;
	for(i=0;i<G->n;i++)//???????????
	    visited[i]=0;
	printf("%2d",G->adjlist[v].data);
	visited[v]=1;
	rear=(rear+1)%max;
	queue[rear]=v;
	while(front!=rear)
	{	front=(front+1)%max;
		w=queue[front];
		p=G->adjlist[w].firstedge;
		while(p!=NULL)
		{	if(visited[p->adjvex]==0)
			{	printf("%2d",G->adjlist[p->adjvex].data);
				visited[p->adjvex]=1;
				rear=(rear+1)%max;
				queue[rear]=p->adjvex;
			}
			p=p->next;
		}
	}
	printf("\n");
}
int main()
{	GraphAdjlist G;
	create(&G);
	printf("the DFS is:\n");
	DFSTraverse(&G);
	printf("\n the BFS is:\n");
	BFS(&G,0);
    system("pause");
	return 0;
}