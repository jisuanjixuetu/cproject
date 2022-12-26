//
// Created by 86199 on 2022/10/19.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "data.h"
#include "fun.h"
#include<string.h>

struct configinfo CONF;

void check(int argc, char*argv[],int choice) {
    FILE *fp;
    fp = fopen("conf.ini", "r");
    fscanf(fp, "%s", CONF.filesavepath);
    fscanf(fp, "%s", CONF.filename);
    fscanf(fp, "%d", &(CONF.maxvalue1));
    fscanf(fp, "%d", &(CONF.minvalue1));
    fscanf(fp, "%d", &(CONF.maxvalue2));
    fscanf(fp, "%d", &(CONF.minvalue2));
    fscanf(fp, "%d", &(CONF.recordcount1));
    fscanf(fp, "%d", &(CONF.recordcount2));
    if (argc == 1) {
        check1(choice);
    }
    if (argc == 2) {
        check2(choice,argv);
    }
    if(argc == 3){
        check3(choice,argv);
    }
}
void check1(int choice) {
    char *path = "default.txt";
    printf("please enter the numbers of information you want to record\n");
    int number;//record numbers;
    scanf("%d", &CONF.number);
    if (CONF.number > CONF.recordcount1 || CONF.number < CONF.recordcount2) {
        printf("it is not illeagal");
        scanf("%d", &number);
    } else {
        printf("Do you want to record the random numbers\n");
        printf("If you want,please enter 1,or enter 0");
        int random;
        scanf("%d", &random);
        if (random == 1) {
            if (choice == 1) {
                choice1(CONF.number,path);
            } else if (choice == 2) {
                choice2(CONF.number,path);
            }
        }else if (random == 0) {
                printf("please enter the number in each line the first number and the second number is between %d and %d"
                       "and the third number id between %d and %d", CONF.minvalue1, CONF.maxvalue1, CONF.minvalue2,
                       CONF.maxvalue2);
                if(choice==1) {
                    choice11(CONF.number,path);
                } else if(choice == 2)
                    choice22(CONF.number,path);
            }
        }
    }

    void choice1(int number,char *path) {
        int **store;
        store = (int **) malloc(number * sizeof(int *));
        for (int i = 0; i < number; i++) {
            store[i] = (int *) malloc(3 * sizeof(int));
        }
        srand((unsigned int) time(NULL));
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < 3; j++) {
                if (j < 2)
                    store[i][j] = rand() % CONF.maxvalue1 + CONF.minvalue1;
                else
                    store[i][j] = rand() % CONF.maxvalue2 + CONF.minvalue2;
            }
        }
        FILE *fp;
        if(strcmp(path,"default.txt") == 0)
            fp = fopen("default.txt", "w");
        else
            fp = fopen(path,"w");
        fprintf(fp,"%d\n",number);
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < 3; j++) {
                fprintf(fp, "%d ", store[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }

void choice2(int number,char *path){
    DATAITEM dataitem[number];
    srand((unsigned int) time(NULL));
    for (int i = 0; i < number; i++) {
        dataitem[i].item1 = rand() % CONF.maxvalue1 + CONF.minvalue1;
        dataitem[i].item2 = rand() % CONF.maxvalue1 + CONF.minvalue1;
        dataitem[i].item3 = rand() % CONF.maxvalue2 + CONF.minvalue2;
    }
    FILE *fp;
    if(strcmp(path,"default.txt") == 0)
        fp = fopen("default.txt", "w");
    else
        fp = fopen(path,"w");
    fprintf(fp, "%d",number);
    for (int i = 0; i < number; i++) {
        fprintf(fp,"%d %d %d\n",dataitem[i].item1,dataitem[i].item2,dataitem[i].item3);
    }
    fclose(fp);
}
void choice11(int number,char *path){
    int **store;
    store = (int **) malloc(number * sizeof(int *));
    for (int i = 0; i < number; i++) {
        store[i] = (int *) malloc(3 * sizeof(int));
    }
    srand((unsigned int) time(NULL));
    for (int i = 0; i < number; i++) {
        scanf("%d %d %d",&store[i][0],&store[i][1],&store[i][2]);
        }
    FILE *fp;
    if(strcmp(path,"default.txt") == 0)
        fp = fopen("default.txt", "w");
    else
        fp = fopen(path,"w");
    fprintf(fp, "%d",number);
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(fp, "%d ", store[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void choice22(int number,char *path){
    DATAITEM dataitem[number];
    for (int i = 0; i < number; i++) {
        scanf("%d %d %d",&dataitem[i].item1,&dataitem[i].item2,&dataitem[i].item3);
    }
    FILE *fp;
    if(strcmp(path,"default.txt") == 0)
        fp = fopen("default.txt", "w");
    else
        fp = fopen(path,"w");
    fprintf(fp, "%d",number);
    for (int i = 0; i < number; i++) {
        fprintf(fp,"%d %d %d\n",dataitem[i].item1,dataitem[i].item2,dataitem[i].item3);
    }
    fclose(fp);
}

void check2(int choice,char*argv[]){
    if('0'<argv[1][0]&&argv[1][0]<'9'){
        char *path = "default.txt";
        CONF.number = atoi(argv[1]);
        if (CONF.number > CONF.recordcount1 || CONF.number < CONF.recordcount2) {
            printf("it is not illeagal");
        }
        else {
            printf("Do you want to record the random numbers\n");
            printf("If you want,please enter 1,or enter 0");
            int random;
            scanf("%d", &random);
            if (random == 1) {
                if (choice == 1) {
                    choice1(CONF.number,path);
                } else if (choice == 2) {
                    choice2(CONF.number,path);
                }
            }else if (random == 0) {
                printf("please enter the number in each line the first number and the second number is between %d and %d"
                       "and the third number id between %d and %d", CONF.minvalue1, CONF.maxvalue1, CONF.minvalue2,
                       CONF.maxvalue2);
                if(choice==1) {
                    choice11(CONF.number,path);
                } else if(choice == 2)
                    choice22(CONF.number,path);
            }
        }

    } else{
        char *path = argv[1];
        printf("please enter the numbers of information you want to record\n");
        int number;//record numbers;
        scanf("%d", &number);
        if (number > CONF.recordcount1 || number < CONF.recordcount2) {
            printf("it is not illeagal");
            scanf("%d", &number);
        }
        else{
            printf("Do you want to record the random numbers\n");
            printf("If you want,please enter 1,or enter 0");
            int random;
            scanf("%d", &random);
            if (random == 1) {
                if (choice == 1) {
                    choice1(number,path);
                } else if (choice == 2) {
                    choice2(number,path);
                }
            }else if (random == 0) {
                printf("please enter the number in each line the first number and the second number is between %d and %d"
                       "and the third number id between %d and %d", CONF.minvalue1, CONF.maxvalue1, CONF.minvalue2,
                       CONF.maxvalue2);
                if(choice==1) {
                    choice11(number,path);
                } else if(choice == 2)
                    choice22(number,path);
            }
        }
    }
}
void check3(int choice,char *argv[]){
    if('0'<argv[1][0]&&argv[1][0]<'9'){
        char *path = argv[2];
        int number = atoi(argv[1]);
        if (number > CONF.recordcount1 || number < CONF.recordcount2) {
            printf("it is not illeagal");
        }
        else {
            printf("Do you want to record the random numbers\n");
            printf("If you want,please enter 1,or enter 0");
            int random;
            scanf("%d", &random);
            if (random == 1) {
                if (choice == 1) {
                    choice1(number,path);
                } else if (choice == 2) {
                    choice2(number,path);
                }
            }else if (random == 0) {
                printf("please enter the number in each line the first number and the second number is between %d and %d"
                       "and the third number id between %d and %d", CONF.minvalue1, CONF.maxvalue1, CONF.minvalue2,
                       CONF.maxvalue2);
                if(choice==1) {
                    choice11(number,path);
                } else if(choice == 2)
                    choice22(number,path);
            }
        }

    } else{
        char *path = argv[1];
        printf("please enter the numbers of information you want to record\n");
        int number = atoi(argv[2]);//record numbers;
            printf("Do you want to record the random numbers\n");
            printf("If you want,please enter 1,or enter 0");
            int random;
            scanf("%d", &random);
            if (random == 1) {
                if (choice == 1) {
                    choice1(number,path);
                } else if (choice == 2) {
                    choice2(number,path);
                }
            }else if (random == 0) {
                printf("please enter the number in each line the first number and the second number is between %d and %d"
                       "and the third number id between %d and %d", CONF.minvalue1, CONF.maxvalue1, CONF.minvalue2,
                       CONF.maxvalue2);
                if(choice==1) {
                    choice11(number,path);
                } else if(choice == 2)
                    choice22(number,path);
            }
        }
    }

void readInput(int argc,char *argv[]){
    if(argc == 2){
        if(!('0'<=argv[1][0]&&argv[1][0]<='9')){
            for(int i = 0;i<strlen(argv[1]); ++i){
                if(argv[1][i] == ':','*','?','<','>','|')
                    printf("int is illegal,please input the right path\n");
            }
        }
    }
    if (argc == 3) {
        if(!('0'<=argv[1][0]&&argv[1][0]<='9')){
            for(int i = 0;i<strlen(argv[1]); ++i){
                if(argv[1][i] == ':','*','?','<','>','|')
                    printf("int is illegal,please input the right path\n");
            }
        } else if(!('0'<=argv[2][0]&&argv[2][0]<='9')){
            for(int i = 0;i<strlen(argv[2]); ++i){
                if(argv[2][i] == ':','*','?','<','>','|')
                    printf("int is illegal,please input the right path\n");
            }
        }
    }
}
int randomInt(int max,int min){
    srand((unsigned int) time(NULL));
    return rand()%(max-min)+min;
}