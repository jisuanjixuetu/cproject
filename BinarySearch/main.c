#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef int Element;
typedef struct sstable{
	Element *elem;
	int length;
}sstable;
#define EQ(a,b) ((a)==(b))
#define LT(a, b)((a) < (b))
#define MT(a,b) ((a)>(b))

int Binary_search(sstable ST,Element key);
int search(sstable ST,Element key);
int main() {
	sstable ST;
	ST.length= 10;
	ST.elem = (Element*)malloc((10+1)*sizeof(Element));
	printf("please enter the table you want to search\n");
	for (int i = 0; i < 10;i++) {
		scanf("%d",&ST.elem[i+1]);
		getchar();
}
	printf("please enter the key you want to search\n");
	int key;
	scanf("%d",&key);
	ST.elem[0] = key;
//	int location = Binary_search(ST,key);
//	printf("%d\n",location);
	int location = search(ST,key);
	printf("%d\n",location);

	return 0;
}

//int Binary_search(sstable ST, Element key){
//	int low = 1;
//	int high = ST.length;
//	while (low<=high){
//		int mid = (low+high)/2;
//		if(EQ(ST.elem[mid],key))
//			return mid;
//		else if (LT(ST.elem[mid], key))
//			low = mid+1;
//		else
//			high = mid - 1;
//	}
//	return 0;
//}
int search(sstable ST,int key){
	for(int i = ST.length;i>=0;i--){
		if(EQ(ST.elem[i],key))
		{
			return i;
		}
	}
	return 0;
}
