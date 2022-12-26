//
// Created by 86199 on 2022/11/17.
//

#include <intrin.h>
#include "loadfile.h"
#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int compare1(const void *e1,const void *e2) {
	int *a = *(int **)e1;
	int *b = *(int **)e2;
	return a[2]-b[2];
}

int compare2(const void *e1,const void *e2){
	return ((struct Track*)e1)->third-((struct Track*)e2)->third;
}

void sort_1(int **track,int n) {
	clock_t start,finish;
	start = clock();
	qsort(track[3],n,sizeof (track[3]),compare1);
	finish = clock();
	double totalTime = (double)((finish-start)/CLOCKS_PER_SEC);
	printf("%d",totalTime);

}

void sort_2(struct Track *track,int n) {
	clock_t start,finish;
	start = clock();
	qsort(track, n, sizeof(track[0]),compare2);
	finish = clock();
	double totalTime = (double)((finish-start)/CLOCKS_PER_SEC);
	printf("%d",totalTime);
}

void sort_3(int **track,int n) {
	clock_t start,finish;
	start = clock();
	qsort(track, n, sizeof(track[0]),compare1);
	finish = clock();
	double totalTime = (double)((finish-start)/CLOCKS_PER_SEC);
	printf("%d",totalTime);
}

void sort_4(struct track *track) {
	clock_t start,finish;
	start = clock();
	struct track *p1, *p2, *temp, *prep1, *prep2;
	for (p1 = track->next->next, prep1 = track->next; p1 != NULL; p1 = p1->next, prep1 = prep1->next) {
		temp = p1;
		for (p2 = track->next, prep2 = track; p2 != p1; p2 = p2->next, prep2 = prep2->next) {
			if (p2->third > p1->third) {
				p1 = p1->next;
				prep1->next = temp->next;
				prep2->next = temp;
				temp->next = p2;
			}
		}
	}
	finish = clock();
	double totalTime = (double)((finish-start)/CLOCKS_PER_SEC);
	printf("%d",totalTime);
}