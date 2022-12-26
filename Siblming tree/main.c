/*-------------------
 |��-�����ֵܱ�﷨ |
 -------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef BASE
#define BASE
#define OVERFLOW -2
#define maxSize 40

#endif

#define TElemType char
typedef struct CSNode{
	TElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;



/*-------------------
 |6.59 ���T�����б� |
 -------------------*/
void TreePrintEdge(CSTree T) {
	CSNode *p;
	for (p=T->firstchild; p; p=p->nextsibling) {
		printf("(%c,%c)\n", T->data, p->data); //���T�ĺ���
		TreePrintEdge(p); //���p�ĺ���
	}
}

/*-------------------------
 |6.60 ͳ��Ҷ�ӽ��ĸ��� |
 -------------------------*/
int TreeLeafCnt(CSTree T) {
	// ����Ҷ�ӽ��-->û�к���
	int ret=0;
	CSNode *p;
	if (!T) return 0;
	else if (!T->firstchild) return 1;
	else {
		for (p=T->firstchild; p; p=p->nextsibling) ret += TreeLeafCnt(p);
		return ret;
	}
}


/*-------------------------
 |6.61 �����Ķ�           |
 -------------------------*/
int TreeDegree(CSTree T) {
	// ���ĺ�����
	int max=-1;
	int cnt=0;
	CSNode *child;
	if (!T) return -1; //����
	else if (!T->firstchild) return 0; //ֻ��һ������㣬��Ϊ0
	else {
		for (cnt=0,child=T->firstchild; child; child=child->nextsibling) cnt++; //���Լ��Ķ�
		max = cnt; //��ǰ�����ֵ
		for (child=T->firstchild; child; child=child->nextsibling) {
			cnt = TreeDegree(child);
			if (cnt>max) max=cnt;
		}
		return max;
	}
}

/*-------------------------
 |6.62 ���������         |
 -------------------------*/
int TreeDepth(CSTree T) {
	int h1,h2;
	if (!T) return 0;
	else {
		h1 = TreeDepth(T->firstchild)+1; //T���ӵ����+1
		h2 = TreeDepth(T->nextsibling); //T�ֵܵ����
		return h1>h2 ? h1 : h2;
	}
}

/*-----------------------------------------
 |6.68 �������+ÿ�����Ķ�-->����CSTree |
 -----------------------------------------*/
CSTree CreateCSTreeByLevelDegree(char *levelstr, int *num) {
	int cnt,i,parent;
	CSNode *p;
	CSNode *tmp[maxSize];

	//�ȴ������
	for (i=0; i < strlen(levelstr); ++i) {
		p = (CSNode *)malloc(sizeof(CSNode)); if (!p) exit(OVERFLOW);
		p->data = levelstr[i];p->firstchild=p->nextsibling=NULL;
		tmp[i]=p;
	}
	//����
	parent=0; //���ӵİְ�
	cnt=0; //����������ʾ�Ѿ����˼�������
	i=1; //������㣬Ϊ�����Ұְ�
	while (i<strlen(levelstr)) {
		if (num[parent]==0 || cnt==num[parent]) { //�������û�к��� || parent�ĺ����Ѿ�������
			cnt=0; //��������0
			parent++; //λ��һλ
			continue;
		}
		//��������к��ӣ�i��parent�ĺ��ӣ�
		cnt++;
		if (cnt==1) { //i��parent�ĵ�һ������
			tmp[parent]->firstchild = tmp[i];
		} else { //���ǵ�һ������
			tmp[i-1]->nextsibling = tmp[i]; //����ǰ����ֵ�
		}

		i++;
	}

	return tmp[0];
}


int main() {
/*6.58��������
RABCDEFGHI
3 2 0 1 0 0 3 0 0 0
*/
	CSTree CST;
	char levelstr[50]; //��α���������
	int num[50]; //ÿ�����Ķ�
	int i,cnt;

	scanf("%s", levelstr);
	for (i=0; i<strlen(levelstr); i++) scanf("%d", &num[i]);
	CST = CreateCSTreeByLevelDegree(levelstr, num);

	TreePrintEdge(CST); // 6.59

	cnt = TreeLeafCnt(CST); //6.60 Ҷ�ӽ�����
	printf("TreeLeafCnt��%d\n", cnt);

	cnt = TreeDegree(CST); //6.61 ���Ķ�
	printf("TreeDegree��%d\n", cnt);

	cnt = TreeDepth(CST); //6.62 �������
	printf("TreeDepth��%d\n", cnt);

	return 0;
}

