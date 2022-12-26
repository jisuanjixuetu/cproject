#include <stdio.h>
#define MAXSIZE 5
typedef struct{
	int key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
	int length;
}SqList;
void InitQList(SqList *list){
	for (int i = 0; i < MAXSIZE; i++) {
	    printf("please enter the key word for the %d element\n",i+1);
		scanf("%d",&(list->r[i+1].key));
		getchar();
	}
	list->length = MAXSIZE;
}
//void StraightInsertSort(SqList * list){
//	for(int i = 2;i<=list->length;i++){
//		int j;
//		if((list->r[i].key)<(list->r[i-1].key)){
//			list->r[0].key = list->r[i].key;
//			list->r[i].key = list->r[i-1].key;
//			for(j = i-2;(list->r[0].key<list->r[j].key);j--){
//				list->r[j+1].key = list->r[j].key;
//			}
//			list->r[j+1].key = list->r[0].key;
//		}
//	}
//}

//void BInsertSort(SqList * list){
//	for(int i = 2;i<=list->length;i++){
//		list->r[0].key=list->r[i].key;
//		int low = 1;
//		int high = i-1;
//		while (low<=high){
//			int middle = (low+high)/2;
//			if(list->r[0].key<list->r[middle].key)
//				high = middle-1;
//			else
//				low = middle+1;
//		}
//		for (int j = i-1;j>=high+1;j--)
//			list -> r[j+1].key = list -> r[j].key;
//		list->r[high+1].key = list->r[0].key;
//	}
//}

void ShellInsert(SqList * list,int dk){
	for(int i = dk+1;i<=list->length; i++){
		if(list -> r[i].key<list -> r[i-dk].key){
			list->r[0].key = list->r[i].key;
			int j;
			for (j = i-dk; j > 0&&(list->r[0].key<list->r[j].key); j-=dk)
				list->r[j+dk].key = list->r[j].key;
			list->r[j+dk].key = list->r[0].key;
		}
	}
}

void shellSort(SqList *list,int dlta[],int t){
	for (int i = 0; i < t; i++) {
		ShellInsert(list,dlta[i]);
}
}
int main() {
	SqList list;
	InitQList(&list);
//	StraightInsertSort(&list);
	//BInsertSort(&list);
	int dlta[3] = {5,3,1};
	shellSort(&list,dlta,3);
	for (int i = 1;i<=MAXSIZE;i++){
		printf("%d\n",list.r[i].key);
	}
	return 0;
}
