#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

int *B;
void Merge(int A[],int low,int high,int mid){
	int i,j,k;
	for(k = low; k <= high; k++){
		B[k] = A[k];
	}
	for (i = low,j = mid+1,k =i; i <= mid&&j<=high; k++) {
		if(B[i]<=B[j])
			A[k]=B[i++];
		else
			A[k] = B[j++];
	}
	while (i <= mid) {
		A[k++] = B[i++];
	}
	while (j<=high) {
	    A[k++]=B[j++];
	}
}
void MergeSort(int A[],int low ,int high){
	if(low<high){
		int mid = (low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
}
int main() {
	printf("Hello, World!\n");
	return 0;
}
