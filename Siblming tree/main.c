/*-------------------
 |树-孩子兄弟表达法 |
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
 |6.59 输出T的所有边 |
 -------------------*/
void TreePrintEdge(CSTree T) {
	CSNode *p;
	for (p=T->firstchild; p; p=p->nextsibling) {
		printf("(%c,%c)\n", T->data, p->data); //输出T的孩子
		TreePrintEdge(p); //输出p的孩子
	}
}

/*-------------------------
 |6.60 统计叶子结点的个数 |
 -------------------------*/
int TreeLeafCnt(CSTree T) {
	// 树的叶子结点-->没有孩子
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
 |6.61 求树的度           |
 -------------------------*/
int TreeDegree(CSTree T) {
	// 最大的孩子数
	int max=-1;
	int cnt=0;
	CSNode *child;
	if (!T) return -1; //空树
	else if (!T->firstchild) return 0; //只有一个根结点，度为0
	else {
		for (cnt=0,child=T->firstchild; child; child=child->nextsibling) cnt++; //求自己的度
		max = cnt; //当前的最大值
		for (child=T->firstchild; child; child=child->nextsibling) {
			cnt = TreeDegree(child);
			if (cnt>max) max=cnt;
		}
		return max;
	}
}

/*-------------------------
 |6.62 求树的深度         |
 -------------------------*/
int TreeDepth(CSTree T) {
	int h1,h2;
	if (!T) return 0;
	else {
		h1 = TreeDepth(T->firstchild)+1; //T孩子的深度+1
		h2 = TreeDepth(T->nextsibling); //T兄弟的深度
		return h1>h2 ? h1 : h2;
	}
}

/*-----------------------------------------
 |6.68 层次序列+每个结点的度-->构造CSTree |
 -----------------------------------------*/
CSTree CreateCSTreeByLevelDegree(char *levelstr, int *num) {
	int cnt,i,parent;
	CSNode *p;
	CSNode *tmp[maxSize];

	//先创建结点
	for (i=0; i < strlen(levelstr); ++i) {
		p = (CSNode *)malloc(sizeof(CSNode)); if (!p) exit(OVERFLOW);
		p->data = levelstr[i];p->firstchild=p->nextsibling=NULL;
		tmp[i]=p;
	}
	//连接
	parent=0; //孩子的爸爸
	cnt=0; //计数器：表示已经找了几个孩子
	i=1; //遍历结点，为他们找爸爸
	while (i<strlen(levelstr)) {
		if (num[parent]==0 || cnt==num[parent]) { //这个父亲没有孩子 || parent的孩子已经找完了
			cnt=0; //计数器归0
			parent++; //位移一位
			continue;
		}
		//这个父亲有孩子（i是parent的孩子）
		cnt++;
		if (cnt==1) { //i是parent的第一个孩子
			tmp[parent]->firstchild = tmp[i];
		} else { //不是第一个孩子
			tmp[i-1]->nextsibling = tmp[i]; //它是前面的兄弟
		}

		i++;
	}

	return tmp[0];
}


int main() {
/*6.58测试数据
RABCDEFGHI
3 2 0 1 0 0 3 0 0 0
*/
	CSTree CST;
	char levelstr[50]; //层次遍历的序列
	int num[50]; //每个结点的度
	int i,cnt;

	scanf("%s", levelstr);
	for (i=0; i<strlen(levelstr); i++) scanf("%d", &num[i]);
	CST = CreateCSTreeByLevelDegree(levelstr, num);

	TreePrintEdge(CST); // 6.59

	cnt = TreeLeafCnt(CST); //6.60 叶子结点个数
	printf("TreeLeafCnt：%d\n", cnt);

	cnt = TreeDegree(CST); //6.61 树的度
	printf("TreeDegree：%d\n", cnt);

	cnt = TreeDepth(CST); //6.62 树的深度
	printf("TreeDepth：%d\n", cnt);

	return 0;
}

