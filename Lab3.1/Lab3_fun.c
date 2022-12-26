//
// Created by 86199 on 2022/11/9.
//

#include "Lab3_fun.h"
/** This file is part of the Mingw32 package.
unistd.h maps (roughly) to io.h
*/
#ifndef _UNISTD_H
#define _UNISTD_H
#include <io.h>
#include <process.h>
#endif /* _UNISTD_H */

#include<direct.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<direct.h>
#include<string.h>
#include"Lab3.data.h"

CONF info;
const char* output = "Default.txt";

/***********************************************
函数名称:
ChangeWorkingDirectory
功能描述:
更改当前工作目录
函数参数:
无
返回值:
无
**********************************************/
void ChangeWorkingDirectory()
{
    char* cwd, buf[256];
    //获取当前工作目录并打印
    if ((cwd = getcwd(buf, sizeof(buf))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }
    printf("original work directory : %s\n", cwd);
    //更改为父目录
    if (chdir("..") == -1)
    {
        perror("chdir");
        exit(1);
    }
    //创建子目录Output
    mkdir("Output");
    //更改为子目录Output
    if (chdir("Output/") == -1)
    {
        perror("chdir");
        exit(1);
    }
    //获取当前工作目录并打印
    if ((cwd = getcwd(buf, sizeof(buf))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }
    printf("work directory changed to: %s\n", cwd);
}

/***********************************************
函数名称:
RandomInt
功能描述:
生成一个规定范围内的随机整数
函数参数:
整型变量：随机数的上限
整型变量：随机数的下限
返回值:
生成的随机整数
**********************************************/
int RandomInt(int max, int min)
{
    srand(time(NULL));//随机数种子
    return rand() % (max - min) + min;
}

/***********************************************
函数名称:
ifFileName
功能描述:
对用户输入的文件名合法性进行判断
函数参数:
字符型指针类型的文件名
返回值:
若合法且输入未指定了文件路径，则返回0，
若存在不合法字符，则返回1；若后缀非".txt"，则返回2；
若含有字符'/'，即输入指定了文件路径，返回3
**********************************************/
int ifFileName(/*const*/ char* filename)
{
    //获取当前工作路径，用于调试
    char* cwd, buff[256];
    if ((cwd = getcwd(buff, sizeof(buff))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }

    int cnt;

    //判断是否含有非法字符：':'、'*'、'?'、'\"'、'<'、'>'、'|'
    for (cnt = 0; filename[cnt] != '\0'; cnt++)
    {
        if (filename[cnt] == ';' || filename[cnt] == '*' || filename[cnt] == '?' || filename[cnt] == '|'
            || filename[cnt] == '<' || filename[cnt] == '>' || filename[cnt] == '\"')
        {
            strcmp(info.filename, filename);
            return 1;
        }
    }

    //判断是否有.txt后缀
    if (filename[cnt - 1] == 't' && filename[cnt - 2] == 'x' && filename[cnt - 3] == 't' && filename[cnt - 4] == '.');
    else
    {
        return 2;
    }

    //判断是否含有字符'/'，即是否指定文件路径，如果是，则检查是否存在相应目录，没有则逐级建立
    for (cnt = 0; filename[cnt] != '\0'; cnt++)
    {
        if (filename[cnt] == '/')
        {
            char path[1000];
            char* tag;
            for (tag = filename; *tag; tag++)
            {
                if (*tag == '/')
                {
                    char buf[1000];
                    strcpy(buf, filename);
                    buf[strlen(filename) - strlen(tag) + 1] = NULL;
                    strcpy(path, buf);
                    if (access(path, 6) == -1)
                    {
                        mkdir(path);//创建子目录
                    }
                }
            }
            chdir(path);//更改当前工作目录
            //获取当前工作路径，用于调试
            if ((cwd = getcwd(buff, sizeof(buff))) == NULL)
            {
                perror("getcwd");
                exit(1);
            }
            return 3;
        }
    }
    return 0;
}

/***********************************************
函数名称:
turn_int
功能描述:
将char型整数转换为int型
函数参数:
整形指针，用于存储转换后的int型变量
字符型指针，将其存储的变量转换为int型变量
返回值:
若能成功转换为数字，返回0，
若不能，则返回1
**********************************************/
int turn_int(int* pn, char* str)
{
    *pn = 0;
    while (1)
    {
        if (*str >= '0' && *str <= '9')
        {
            *pn *= 10;
            *pn += (*str - '0');
            str++;
        }
        else
        {
            if (*str == 0)
            {
                return 0;
            }
            //合法性判断
            return 1;
        }
    }
    return 0;
}

/***********************************************
函数名称:
GenerateDataFiles_2dArr
功能描述:
按照用户指令生成随机数据，以二维数组的形式存储，向屏幕输出，并写入相应文件
函数参数:
整型变量，用于存储用户所需生成随机数据的个数
字符型指针，用于存储生成数据的存储文件名
**********************************************/
void GenerateDataFiles_2dArr(int DataNum_int, const char* filename)
{
    int** shu = NULL;
    int i, j;
    srand(time(NULL));//随机数种子
    FILE* fp;

    //打开文件
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("Can't open this file!\n");
        exit(1);
    }

    //根据用户的输入动态申请适量的内存空间，以二维数组的方式使用该空间
    shu = (int**)malloc(DataNum_int * sizeof(int*));
    if (shu == NULL)
    {
        printf("内存分配失败！\n");
    }
    for (i = 0; i < DataNum_int; i++)
    {
        shu[i] = (int*)malloc(3 * sizeof(int));
        if (shu[i] == NULL)
        {
            printf("内存分配失败！\n");
        }
    }

    //生成要求条数的随机数据并存入二维数组中
    for (i = 0; i < DataNum_int; i++)
    {
        //保证不生成重复数据
        while (1)
        {
            shu[i][0] = rand() % (info.maxvalue1 - info.minvalue1) + info.minvalue1;
            shu[i][1] = rand() % (info.maxvalue1 - info.minvalue1) + info.minvalue1;
            if (shu[i][1] != shu[i][2])
            {
                break;
            }
        }
        shu[i][2] = rand() % (info.maxvalue2 - info.minvalue2) + info.minvalue2;
    }

    //将二维数组中的随机数据按照格式要求写入相应文件中
    fprintf(fp, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        for (j = 0; j < 2; j++)
        {
            fprintf(fp, "%d", shu[i][j]);
            fputs(",", fp);
        }
        fprintf(fp, "%d", shu[i][j]);
        fputs("\n", fp);
    }

    //向屏幕输出生成的数据记录
    fprintf(stdout, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d,", shu[i][j]);
        }
        printf("%d\n", shu[i][j]);
    }

    //释放动态分配的内存空间
    {
        for (i = 0; i < DataNum_int; i++)
        {
            free(shu[i]);
        }
        free(shu);
    }

    //关闭文件
    if (fclose(fp) == EOF)
    {
        printf("Can't close this file!\n");
        exit(1);
    }
}

/***********************************************
函数名称:
GenerateDataFiles_StructArr
功能描述:
按照用户指令生成随机数据，以结构体数组的形式存储，向屏幕输出，并写入相应文件
函数参数:
整型变量，用于存储用户所需生成随机数据的个数
字符型指针，用于存储生成数据的存储文件名
**********************************************/
void GenerateDataFiles_StructArr(int DataNum_int, const char* filename)
{
    DATAITEM* data = NULL;
    int i;
    srand(time(NULL));//随机数种子
    FILE* fp;

    //打开文件
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("Can't open this file!\n");
        exit(1);
    }

    //根据用户的输入动态申请适量的内存空间，以结构体数组的方式使用该空间
    data = (DATAITEM*)malloc(DataNum_int * sizeof(DATAITEM));
    if (data == NULL)
    {
        printf("内存分配失败！\n");
    }

    //生成随机数据
    for (i = 0; i < DataNum_int; i++)
    {
        //保证不生成重复数据
        while (1)
        {
            data[i].item1 = rand() % (info.maxvalue1 - info.minvalue1) + info.minvalue1;
            data[i].item2 = rand() % (info.maxvalue1 - info.minvalue1) + info.minvalue1;
            if (data[i].item1 != data[i].item2)
            {
                break;
            }
        }
        data[i].item3 = rand() % (info.maxvalue2 - info.minvalue2) + info.minvalue2;
    }

    //将随机数据写入默认文件名
    fprintf(fp, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        fprintf(fp, "%d", data[i].item1);
        fputs(",", fp);
        fprintf(fp, "%d", data[i].item2);
        fputs(",", fp);
        fprintf(fp, "%d", data[i].item3);
        fputs("\n", fp);
    }

    //向屏幕输出生成的数据记录
    fprintf(stdout, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        printf("%d,", data[i].item1);
        printf("%d,", data[i].item2);
        printf("%d\n", data[i].item3);
    }

    //释放动态分配的内存空间
    free(data);

    //关闭文件
    if (fclose(fp) == EOF)
    {
        printf("Can't close this file!\n");
        exit(1);
    }
}

/***********************************************
函数名称:
scandata
功能描述:
读取指定配置文件中的内容并存入相应的结构体变量中
**********************************************/
void scandata()
{

    int n = 0;
    char ch[10], cha;
    FILE* fp;

    if ((fp = fopen("tmpfile.ini.txt", "r")) == NULL)
    {
        printf("1:Can't open this file!\n");
        exit(1);
    }

    fscanf(fp, "%s", info.filesavepath);
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", info.filename);
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.number = n;
    n = 0;
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.maxvalue1 = n;
    n = 0;
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.minvalue1 = n;
    n = 0;
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.maxvalue2 = n;
    n = 0;
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.minvalue2 = n;
    n = 0;
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.recordcount1 = n;
    n = 0;
    while (cha = fgetc(fp), cha != '\n');
    fscanf(fp, "%s", ch);
    turn_int(&n, ch);
    info.recordcount2 = n;

    if (fclose(fp) == EOF)
    {
        printf("Can't close this file!\n");
        exit(1);
    }
}