#include <stdio.h>
#define MAXSIZE 5
typedef struct {
	int key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
	int length;
}SqList;
void InitList(SqList * list){
	for (int i = 1;i<=MAXSIZE;i++){
		printf("please enter the %d key\n",i);
		scanf("%d",&(list->r[i].key));
		getchar();
	}
}
//void SelectSort(SqList * list){
//	for (int i = 1; i < MAXSIZE; i++) {
//		RedType temp;
//		temp.key = list-> r[i].key;
//		int index;
//		index = i;
//	    for (int j = i+1; j <= MAXSIZE; j++) {
//	        if (temp.key>list -> r[j].key) {
//				index = j;
//				temp.key = list -> r[j].key;
//}
//	    }
//		list -> r[index].key = list -> r[i].key;
//		list -> r[i].key = temp.key;
//	}
//}

//void HeapAdjust(SqList * list,int s,int m){
//	RedType temp;
//	temp.key = list -> r[s].key;
//	for(int i = 2*s;i<=m;i++){
//		if(i<m&&list -> r[i].key <list->r[i+1].key)
//			i++;
//		if(temp.key >= list->r[i].key)
//			break;
//		list->r[s].key = list->r[i].key;
//		s = i;
//	}
//	list->r[s].key = temp.key;
//}
//
//void HeapSort(SqList*list){
//	for (int i = list->length/2;i>0;i--){
//		HeapAdjust(list,i,list->length);
//	}
//	for (int i = list -> length ; i > 1; i--) {
//		RedType temp;
//		temp.key = list -> r[i].key;
//		list->r[i].key = list -> r[1].key;
//		list->r[1].key = temp.key;
//		HeapAdjust(list,1,i-1);
//	}
//}
void HeadAdjust(SqList * list,int k,int len){
	list -> r[0].key = list->r[k].key;
	for(int i = 2*k;i<=len; i*=2){
		if(i<len&&list -> r[i].key <list -> r[i+1].key)
			i++;
		if(list->r[0].key>=list -> r[i].key)
			break;
		else{
			list->r[k].key = list->r[i].key;
			k = i;
		}
	}
	list->r[k].key = list->r[0].key;
}
void BuildMaxHeap(SqList * list,int len){
	for (int i = len/2;i>0;i--) {
		HeadAdjust(list,i,len);
	}
}
void HeapSort(SqList * list,int len){
	BuildMaxHeap(list,len);
	for(int i = len;i>1;i--){
		int temp = list -> r[i].key;
		list -> r[i].key = list->r[1].key;
		list -> r[1].key = temp;
		HeadAdjust(list,1,i-1);
	}
}
int main() {
	SqList list;
	InitList(&list);
//	SelectSort(&list);
	//HeapSort(&list);
	HeapSort(&list,MAXSIZE);
	for (int i = 1;i<=MAXSIZE;i++){
		printf("%d\n",list.r[i].key);
	}
	return 0;
}
