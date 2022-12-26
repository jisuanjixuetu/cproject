//
// Created by 86199 on 2022/10/5.
//

#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Check(int argc,char *argv[])
{
    int n;
    if(argc==1)//如果就一个参数
    {
        printf("please enter the number you want to input\n");
        scanf("%d",&n);//自定义多少行
        char name[100]="output.txt";//输入文件名称
        Creat(n,name);//创建文件
    }
    else if(argc == 2)//如果参数为2
        printf("Too few,Error\n");
    else if(argc == 3)
    {
        Ilegal(argv);
    }
    else if(argc>=4)//如果参数大于3
        printf("Too more,Error\n");

}
void Creat(int n,char *fileName)
{
    int num[n][3];
    int i;
    int j;
    srand((unsigned int)time(NULL));
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<3;j++)
            num[i][j]=rand()%100;
    }
    FILE *fp;
    fp = fopen(fileName,"w");//创建文件
    fprintf(fp,"%d",n);//读取个数
    for(i = 0;i<n;i++)
        fprintf(fp,"%d,%d,%d\n",num[i][0],num[i][1],num[i][2]);//读取每行
    fclose(fp);
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<3;j++)
            fprintf(stdout,"%d ",num[i][j]);//在屏上输出
        fprintf(stdout,"\n");
    }//打印
}

void Ilegal(char*argv[]){

    if(argv[1][0]>='0'&&argv[1][0]<='9'&&argv[2][0]>='0'&&argv[2][0]<='9')//如果两个参数全是数字
        printf("You enter two number\n");
    else if(argv[1][0]>='a'&&argv[1][0]<='z'&&argv[2][0]>='a'&&argv[2][0]<='z')//如果参数全是字符串
        printf("You enter two strings\n");
    else if(argv[1][0]>='0'&&argv[1][0]<='9'&&argv[2][0]>='a'&&argv[2][0]<='z')//如果第一个参数是数字，第二个参数是字符串
    {
        int n;
        n = (int)(*argv[1]-'0');//转化为实际数字
        Creat(n,argv[2]);//创建
    }
    else if(argv[1][0]>='a'&&argv[1][0]<='z'&&argv[2][0]>='0'&&argv[2][0]<='9')//如果第一个参数是字符串，如果第二个参数是数字1
    {
        int n;
        n = (int)(*argv[2]-'0');//转化为实际数字
        Creat(n,argv[1]);//创建
    }
}