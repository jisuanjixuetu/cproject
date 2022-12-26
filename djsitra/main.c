#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define MAXINT 10000
typedef struct{//��ʾ���㣬�������ƺ�Ȩ��
    char data;
    int weight;
}vertex;

typedef struct{//��ʾ���㼯�ϣ�������������Ͷ������
    vertex arr[MAXSIZE];
    int size;
}VertexSet;
int get_index(VertexSet a, char b)//�������붥������ƣ��õ��ö����������е��±�
{
    int i = 0;
    for(i = 0; i < a.size; i++)
    {
        if(a.arr[i].data == b)return i;
    }
    return -1;
}

void Dijkstra(VertexSet* S, VertexSet T, int G[MAXSIZE][MAXSIZE])
{
    int m,n,i,j;
    for(i = 0; i < MAXSIZE; i++)
    {
        for(j = 0; j < MAXSIZE; j++)
        {
            G[i][j] = MAXINT;//��ʼ���ڽ����
        }
    }

    T.size = 0;
    S->size = 0;
    int visited[MAXSIZE] = {0};
    printf("�����붥�����ͻ�����Ŀ:>");
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++)
    {
        printf("������ÿһ������:>");
        getchar();
        scanf("%c",&T.arr[i].data);
        T.arr[i].weight = MAXINT;//��ʼ���Լ��ϣ�ȨֵΪ�����Լ��������
        T.size++;
    }
    char a,b;
    int q;
    for(i = 0; i < n; i++)
    {
        printf("������ÿһ�����Լ��ߵ�Ȩֵ:>");
        getchar();
        scanf("%c%c%d",&a,&b,&q);
        G[get_index(T,a)][get_index(T,b)] = q;//��������ı��Լ�Ȩֵ����ά�����
    }
    char input;
    printf("��������ĸ����㿪ʼѰ�����·��:>");
    getchar();
    scanf("%c",&input);
    S->arr[0].data = input;//�Ӽ����з����һ��ֵ������������Ŀ�ʼ����
    S->arr[0].weight = 0;//����ȨֵΪ0
    S->size++;//�Ӽ�����Ԫ�ظ���+��
    visited[get_index(T, input)] = 1;//��Ǹö���Ϊ�ѷ���
    int temp_index = get_index(T,input);//�õ���������±꣬�൱�ڶ�ά����ĺ�����
    while(S->size < T.size )
    {
        int temp_min = MAXINT;
        for(i = 0;i < T.size; i++)
        {//���£Լ����У�ͨ���Ӽ����ж�����ת���������������·��
            if(T.arr[i].weight >= G[temp_index][i]+S->arr[S->size-1].weight && !visited[i])
            {
                T.arr[i].weight = G[temp_index][i]+S->arr[S->size-1].weight;
            }
            if(!visited[i] && temp_min >= T.arr[i].weight)
            {
                temp_min = T.arr[i].weight;//�ҵ����º�ģԼ����У���С��Ȩֵ���Լ����������е��±�
                j = i;//�±�
            }
        }
        temp_index = j;//�ҵ����·��������´�ѭ�������������Ϊ��ת����������������·��
        visited[temp_index] = 1;
        //ѭ��һ�ΣӼ������һ��Ԫ�أ��Ӽ���Ԫ�ظ���+��
        S->arr[S->size].weight = temp_min;
        S->arr[S->size].data = T.arr[temp_index].data;
        S->size++;
    }
}
void Print(VertexSet S)
{
    int i;
    for(i = 1; i < S.size; i++)
    {
        printf("%c->%c,���·��Ϊ:%d\n",S.arr[0].data,S.arr[i].data,S.arr[i].weight);
    }
}

int main()
{
    int G[MAXSIZE][MAXSIZE];//���ڽ��������ʾ������
    VertexSet T,S;//�Ӽ��ϱ�ʾ��ָ�����������������������·���ļ��ϣ��Լ��ϱ�ʾ��ǰָ�����㵽��������·������
    Dijkstra(&S,T,G);
    Print(S);

    return 0;
}