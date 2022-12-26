//
// Created by 86199 on 2022/11/17.
//

#include "loadfile.h"
#include "call.h"
#include "sort.h"
#include <stdio.h>
# include <stdlib.h>
#include <time.h>
#include <string.h>

void fun(int choice) {
	meau();
	int **store;
	store = (int **) malloc(20*sizeof(int *));
	for (int i = 0; i < 20; i++) {
		*(store+i) = (int *)malloc(sizeof(int));
	}
	struct Track *tracks;
	struct track *structtrack;
	if (choice == 1) {
		printf("请输入你要执行的程序，按0退出\n");
		int function;
		scanf("%d", &function);
		while (function != 0) {
			switch (function) {
				case 0 :
					return;
				case 1:
					functionOne();
					break;
				case 2:
					store = functionTwo("file.txt");
					meau();
					break;
				case 3 :
					tracks = functionThree("file.txt");
					meau();
					break;
				case 4 :
					store = functionFour("file.txt");
					meau();
					break;
				case 5 :
					structtrack=functionFive("file.txt");
					meau();
				case 6 :
					store=functionSix("Datafile.txt",0);
					meau();
					break;
				case 7 :
					tracks = functionSeven("Datafile.txt",0);
					meau();
					break;
				case 8 :
					store = functionEight("Datafile.txt",0);
					meau();
				case 9 :
					structtrack = functionNine("Datafile.txt",0);
					meau();
					break;
				case 10 :
					functionTen("Datafile.txt",0);
					meau();
					break;
				case 11 :
					functionEleven("Datafile.txt",0);
					meau();
					break;
				case 12 :
					functionTwelve("Datafile.txt",0);
					meau();
					break;
				case 13 :
					functionThirteen("Datafile.txt",0);
					meau();
					break;
				case 14 :
					functionFourteen();
					meau();
					break;
					default :
						printf("你输入的功能不正确，请再次输入功能顺序 0-14\n");
					meau();
					break;
			}
		}
	} else if (choice == 2) {
		printf("请输入你想要存储文件的位置：\n");
		char path[100];
		scanf("%s",path);
		printf("请输入你想要保存文件的名称：\n");
		char filename[100];
		scanf("%s",filename);
		printf("请输入你要记录数据的行数：\n");
		int number;
		scanf("%d",&number);
		printf("请输入你要执行的程序,按0退出\n");
		meau();
		int function;
		scanf("%d",&function);
		switch (function) {
			case 1:
				call(filename,number);
				meau();
				break;
				case 2 :
					store = functionTwo("file.txt");
				meau();
				break;
				case 3 :
					tracks = functionThree("file.txt");
				meau();
				break;
				case 4 :
					store = functionFour("file.txt");
				meau();
				break;
				case 5 :
					structtrack = functionFive("file.txt");
				meau();
					break;
					case 6 :
						store = functionSix(filename,number);
				meau();
				break;
				case 7 :
					tracks = functionSeven(filename,number);
				meau();
				break;
				case 8 :
					store = functionSix(filename,number);
				meau();
				break;
				case 9 :
					structtrack = functionNine(filename,number);
				meau();
				break;
				case 10 :
					functionTen(filename,number);
				meau();
				break;
				case 11 :
					functionEleven(filename,number);
				meau();
				break;
				case 12 :
					functionTwelve(filename,number);
				meau();
				break;
			case 13:
				functionThirteen(filename, number);
				meau();
				break;
				case 14 :
					functionFourteen();
				meau();
				break;
			default :
				printf("你输入的功能不正确，请再次输入功能顺序 0-14\n");
				meau();
				break;

		}

	}
}

void meau() {
	FILE *fp;
	fp = fopen("meau.txt", "r");
	char sentence[100];
	while (!feof(fp)) {
		fgets(sentence, 100, fp);
		puts(sentence);
	}
}

void functionOne() {
	srand((unsigned int) time(NULL));
	int number = rand() % 20 + 1;
	char *filename = "default.txt";
	call(filename, number);
}

int **functionTwo(char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	int n = fscanf(fp, "%d", &n);
	int trcak[n][3];
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d %d", &trcak[i][0], &trcak[i][1], &trcak[i][2]);
	}
	int **tracks;
	tracks = (int **) malloc(n*sizeof (int *));
	for (int i = 0; i < n; i++) {
		*(tracks+i) = (int *) malloc(3*sizeof(int));
	}
	fclose(fp);
	return tracks;
}

struct Track * functionThree(char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	int n;
	fscanf(fp, "%d", &n);
	struct Track *track;
	track = (struct Track *) malloc(sizeof(struct Track));
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d %d", &track[i].first, &track[i].second, &track[i].third);
	}
	fclose(fp);
	return track;
}

int **functionFour(char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	int n;
	fscanf(fp, "%d", &n);
	int **track;
	track = (int **) malloc(sizeof(*track) * n);
	for (int i = 0; i < n; i++) {
		track[i] = (int *) malloc(sizeof(int) * 3);
	}
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d %d", ((track + i) + 0), ((track + i) + 1), ((track + i) + 2));
	}
	fclose(fp);
	return track;
}

trackNode functionFive(char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	int n;
	fscanf(fp, "%d", &n);
	trackNode head = NULL;
	trackNode temp = (trackNode) malloc(sizeof(track));
	fscanf(fp, "%d %d %d", &temp->first, &temp->second, &temp->third);
	temp->next = head->next;
	head->next = temp;
	trackNode ini;
	ini = temp;
	for (int i = 1; i < n; i++) {
		trackNode temp;
		temp = (trackNode) malloc(sizeof(track));
		fscanf(fp, "%d %d %d", &temp->first, &temp->second, &temp->third);
		temp->next = ini->next;
		ini->next = temp;
		ini = temp;
	}
	return head;
}

int **functionSix(char *filename,int number) {
	srand((unsigned int) time(NULL));
	if (number==0) {
		number = rand() % 20 + 1;
}
	call(filename, number);
	int **track;
	track = functionTwo(filename);
	return track;
}

struct Track *functionSeven(char *filename,int number) {
	srand((unsigned int) time(NULL));
	if (number==0) {
		number = rand() % 20 + 1;
	}
	call(filename, number);
	struct Track *track1;
	track1 = functionThree(filename);
	return track1;
}

int **functionEight(char *filename,int number) {
	srand((unsigned int) time(NULL));
	if (number==0) {
		number = rand() % 20 + 1;
	}
	call(filename, number);
	int **track;
	track = functionFour(filename);
	return track;
}

struct track *functionNine(char*filename,int number) {
	srand((unsigned int) time(NULL));
	if (number==0) {
		number = rand() % 20 + 1;
	}
	call(filename, number);
	struct track *track1;
	track1 = functionFive(filename);
	return track1;
}

void functionTen(char *filename,int number) {
	int **track;
	track = functionSix(filename,number);
	FILE *fp = fopen(filename,"r");
	int n;
	fscanf(fp,"%d",&n);
	sort_1(track,n);
}

void functionEleven(char *filename,int number) {
	struct Track *track;
	track = functionSeven(filename,number);
	FILE *fp = fopen(filename,"r");
	int n;
	fscanf(fp,"%d",&n);
	sort_2(track,n);
}

void functionTwelve(char *filename,int number) {
	int **track;
	track = functionEight(filename,number);
	FILE *fp = fopen(filename,"r");
	int n;
	fscanf(fp,"%d",&n);
	sort_3(track,n);
}

void functionThirteen(char *filename,int number) {
	trackNode trackNode1;
	trackNode1 = functionNine(filename,number);
	sort_4(trackNode1);
}
