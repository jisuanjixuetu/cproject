//
// Created by 86199 on 2022/11/17.
//

#include <stdio.h>
#include "loadfile.h"

void printShuzu(int *track[3],int n){
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < 3; j++) {
	 	    printf("%d\t",track[i][j]);
	 	}
		 printf("\n");
	}
}
void printStruct(struct Track *track,int n){
	for(int i = 0;i<n;i++){
		printf("%d\t%d\t%d\n",track[i].first,track[i].second,track[i].third);
	}
}
void printZhizhen(int ** track, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t",track[i][j]);
		}
		printf("\n");
	}
}
void printlianbiao(struct track*track){
	struct track *temp;
	temp = track ->next;
	while(temp){
		printf("%d\t%d\t%d\n",temp->first,temp -> second,track->third);
		temp = temp -> next;
	}
}