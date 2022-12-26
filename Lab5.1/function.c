#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"function.h"
void wordStatistics1(char* p)
{
    FILE *fp1;
    if ((fp1 = fopen(p, "r")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
    char a[1000] = {0};
    int isblank=0;
    int wordnum = 0;
    while(fgets(a,1000,fp1)){
        int n = strlen(a);
        for(int i = 0;i<n;i++){
            char c = a[i];
            if(c ==' '||c=='\t'){
                if(isblank==0) wordnum++;
                    isblank = 1;
            }
            else if(c!='\n'&&c!='\r'){
                isblank = 0;
            }
        }
        if(isblank == 0) wordnum++;
        isblank = 1;
    }
  printf("The number of words is:%d\n",wordnum);
}

void othersStatistics1( char* p)
{
    FILE *fp1;
    if ((fp1 = fopen(p, "r")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
    int num = 0;
    int blank = 0;
    int letter = 0;
    int others = 0;
    char a[1000]={0};
    while(fgets(a,1000,fp1)){
        int n = strlen(a);
        for(int i = 0;i<n;i++){
            char c = a[i];
            if(c==' '||c=='\t'){
                blank++;
            }
            else if(c>'0'&&c<'9'){
                num++;
            }
            else if(c>'a'&&c<'z'||c>'A'&&c<'Z'){
                letter++;
            }
            else others++;
        }
    }
    
    printf("The number of blank is:%d\n",blank);
    printf("The number of number is:%d\n",num);
    printf("The number of letters is:%d\n",letter);
    printf("The number of other character is:%d\n",others);
}
void wordStatistics2(char*p)
{
    FILE *fp1;
    if ((fp1 = fopen(p, "r")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
    char a[1000] = {0};
    int isblank=0;
    int wordnum = 0;
    while(fgets(a,1000,fp1)){
        int n = strlen(a);
        for(int i = 0;i<n;i++){
            char c = a[i];
            if(c ==' '||c=='\t'){
                if(isblank==0) wordnum++;
                    isblank = 1;
            }
            else if(c!='\n'&&c!='\r'){
                isblank = 0;
            }
        }
        if(isblank == 0) wordnum++;
        isblank = 1;
    }
    FILE *fp2;
    if ((fp2 = fopen("result.txt", "w")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
  fprintf(fp2,"words %d\n",wordnum);
}
void othersStatistics2(char*p)
{
    FILE *fp1;
    if ((fp1 = fopen(p, "r")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
    int num = 0;
    int blank = 0;
    int letter = 0;
    int others = 0;
    char a[1000]={0};
    while(fgets(a,1000,fp1)){
        int n = strlen(a);
        for(int i = 0;i<n;i++){
            char c = a[i];
            if(c==' '||c=='\t'){
                blank++;
            }
            else if(c>'0'&&c<'9'){
                num++;
            }
            else if(c>'a'&&c<'z'||c>'A'&&c<'Z'){
                letter++;
            }
            else others++;
        }
    }
    FILE *fp2;
    if ((fp2 = fopen("result.txt", "a")) == NULL)
    {
        printf(" File open error!\n");
        exit(0);
    }
    fprintf(fp2,"blank %d\n",blank);
    fprintf(fp2,"number %d\n",num);
    fprintf(fp2,"letters %d\n",letter);
    fprintf(fp2,"others %d\n",others);
}