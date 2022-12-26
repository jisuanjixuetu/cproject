#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EQ(a,b) ((a)==(b))
#define LT(a, b) ((a) < (b))
#define LQ(a,b) ((a)<=(b))

#define N 10

struct ElemType{
	int key;
	int others;
};

typedef struct ElemType TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InitBiTree(BiTree T){
	T = NULL;
}
bool SearchBST(BiTree T,int key,BiTree f,BiTree p){
	if(!T)
	{
		p = f;
		return false;
	} else if(EQ(key,T->data.key)){
		p = T;
		return true;
	}
	else if (LT(key, T -> data.key)) {
		return SearchBST(T->lchild,key,T,p);
	} else
		return SearchBST(T -> rchild, key, T, p);
}
bool InsertBST(BiTree T,struct ElemType e){
	BiTree p,s;
	if(!SearchBST(T,e.key,NULL,p)){
		s = (BiTree) malloc(sizeof (BiTree));
		s->data = e;
		s ->lchild = s ->rchild = NULL;
		if(!p){
			T = s;
		} else if(LT(e.key,p->data.key))
			p->lchild = s;
		else
			p->rchild = s;
		return true;
	} else
		return false;
}

bool Delete(BiTree p){
	BiTree q,s;
	if(!p->rchild){
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (!p->lchild){
		q = p;
		p = p -> rchild;
		free(q);
	} else
	{
		q = p;
		s = p->lchild;
		while (s->rchild){
			q = s;
			s = s -> rchild;
		}
		p->data = s->data;
		if(q!=p){
			q->rchild = s->lchild;
		} else{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return true;
}

bool DeleteBST(BiTree T,int key){
	if(!T){
		return false;
	}
	else {
	    if(EQ(key,T->data.key)){
			return Delete(T);
		}
		else if(LT(key,T -> data.key))
			return DeleteBST(T->lchild,key);
		else
			return DeleteBST(T -> rchild, key);
	}
}
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		printf("(%d,%d)",T-> data.key,T->data.others);
		InOrderTraverse(T->rchild);
	}
}
int main(){
	BiTree Btree = NULL;
	BiTree f,t;
	int i,p;
	TElemType elem[N];
	for (i = 0; i < N; i++) {
		printf("请输入第%d个key值和数据：\n",i+1);
		scanf("%d %d",&elem[i].key,&elem[i].others);
		getchar();
	}
	InitBiTree(Btree);
	for (i = 0; i < N; i++) {
		InsertBST(Btree,elem[i]);
	}
	InOrderTraverse(Btree);
	printf("请输入你要查找的值：");
	int search;
	scanf("%d",&search);

	p = SearchBST(Btree,search,NULL,f);
	if(p){
		printf("表中存在这个值\n");
		DeleteBST(Btree,search);
		printf("删除此值后\n");
		InOrderTraverse(Btree);
	}

}