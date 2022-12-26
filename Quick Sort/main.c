#include <stdio.h>
#define MAXSIZE 5
typedef struct{
	int key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
	int length;
}SqList;
void InitList(SqList * list){
	for (int i = 0; i < MAXSIZE; i++) {
		printf("please enter the key word for the %d element\n",i+1);
		scanf("%d",&(list->r[i+1].key));
		getchar();
	}
	list->length = MAXSIZE;
}
//void BubbleSort(SqList * list){
//	for (int i = 1; i < MAXSIZE; i++) {
//	    for (int j = i; j < MAXSIZE; j++) {
//	        if(list -> r[j].key >list -> r[j+1].key){
//				int temp = list -> r[j].key;
//				list -> r[j].key = list -> r[j+1].key;
//				list -> r[j+1].key = temp;
//			}
//	    }
//	}
//}
int Partition(SqList * list,int low,int high){
	list->r[0].key = list-> r[low].key;
	int pivotKey = list->r[low].key;
	while (low<high) {
		while ((low<high)&&(list->r[high].key>=pivotKey)) {
			high--;
}
		list -> r[low].key = list -> r[high].key;
		while ((low < high) && (list -> r[low].key <= pivotKey)) {
		    low++;
		}
		list -> r[high].key = list -> r[low].key;
}
	list -> r[low].key = list->r[0].key;
	return low;
}

void QSort(SqList*list,int low,int high) {
	if (low < high) {
		int pivotLoc = Partition(list, low, high);
		QSort(list, low, pivotLoc - 1);
		QSort(list, pivotLoc + 1, high);
	}
}
int main() {
	SqList list;
	InitList(&list);
//	BubbleSort(&list);
	QSort(&list,1,MAXSIZE);
	for(int i = 1;i<=MAXSIZE;i++){
		printf("%d\n",list.r[i].key);
	}
	return 0;
}
