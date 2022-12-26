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
��������:
ChangeWorkingDirectory
��������:
���ĵ�ǰ����Ŀ¼
��������:
��
����ֵ:
��
**********************************************/
void ChangeWorkingDirectory()
{
    char* cwd, buf[256];
    //��ȡ��ǰ����Ŀ¼����ӡ
    if ((cwd = getcwd(buf, sizeof(buf))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }
    printf("original work directory : %s\n", cwd);
    //����Ϊ��Ŀ¼
    if (chdir("..") == -1)
    {
        perror("chdir");
        exit(1);
    }
    //������Ŀ¼Output
    mkdir("Output");
    //����Ϊ��Ŀ¼Output
    if (chdir("Output/") == -1)
    {
        perror("chdir");
        exit(1);
    }
    //��ȡ��ǰ����Ŀ¼����ӡ
    if ((cwd = getcwd(buf, sizeof(buf))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }
    printf("work directory changed to: %s\n", cwd);
}

/***********************************************
��������:
RandomInt
��������:
����һ���涨��Χ�ڵ��������
��������:
���ͱ����������������
���ͱ����������������
����ֵ:
���ɵ��������
**********************************************/
int RandomInt(int max, int min)
{
    srand(time(NULL));//���������
    return rand() % (max - min) + min;
}

/***********************************************
��������:
ifFileName
��������:
���û�������ļ����Ϸ��Խ����ж�
��������:
�ַ���ָ�����͵��ļ���
����ֵ:
���Ϸ�������δָ�����ļ�·�����򷵻�0��
�����ڲ��Ϸ��ַ����򷵻�1������׺��".txt"���򷵻�2��
�������ַ�'/'��������ָ�����ļ�·��������3
**********************************************/
int ifFileName(/*const*/ char* filename)
{
    //��ȡ��ǰ����·�������ڵ���
    char* cwd, buff[256];
    if ((cwd = getcwd(buff, sizeof(buff))) == NULL)
    {
        perror("getcwd");
        exit(1);
    }

    int cnt;

    //�ж��Ƿ��зǷ��ַ���':'��'*'��'?'��'\"'��'<'��'>'��'|'
    for (cnt = 0; filename[cnt] != '\0'; cnt++)
    {
        if (filename[cnt] == ';' || filename[cnt] == '*' || filename[cnt] == '?' || filename[cnt] == '|'
            || filename[cnt] == '<' || filename[cnt] == '>' || filename[cnt] == '\"')
        {
            strcmp(info.filename, filename);
            return 1;
        }
    }

    //�ж��Ƿ���.txt��׺
    if (filename[cnt - 1] == 't' && filename[cnt - 2] == 'x' && filename[cnt - 3] == 't' && filename[cnt - 4] == '.');
    else
    {
        return 2;
    }

    //�ж��Ƿ����ַ�'/'�����Ƿ�ָ���ļ�·��������ǣ������Ƿ������ӦĿ¼��û�����𼶽���
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
                        mkdir(path);//������Ŀ¼
                    }
                }
            }
            chdir(path);//���ĵ�ǰ����Ŀ¼
            //��ȡ��ǰ����·�������ڵ���
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
��������:
turn_int
��������:
��char������ת��Ϊint��
��������:
����ָ�룬���ڴ洢ת�����int�ͱ���
�ַ���ָ�룬����洢�ı���ת��Ϊint�ͱ���
����ֵ:
���ܳɹ�ת��Ϊ���֣�����0��
�����ܣ��򷵻�1
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
            //�Ϸ����ж�
            return 1;
        }
    }
    return 0;
}

/***********************************************
��������:
GenerateDataFiles_2dArr
��������:
�����û�ָ������������ݣ��Զ�ά�������ʽ�洢������Ļ�������д����Ӧ�ļ�
��������:
���ͱ��������ڴ洢�û���������������ݵĸ���
�ַ���ָ�룬���ڴ洢�������ݵĴ洢�ļ���
**********************************************/
void GenerateDataFiles_2dArr(int DataNum_int, const char* filename)
{
    int** shu = NULL;
    int i, j;
    srand(time(NULL));//���������
    FILE* fp;

    //���ļ�
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("Can't open this file!\n");
        exit(1);
    }

    //�����û������붯̬�����������ڴ�ռ䣬�Զ�ά����ķ�ʽʹ�øÿռ�
    shu = (int**)malloc(DataNum_int * sizeof(int*));
    if (shu == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
    }
    for (i = 0; i < DataNum_int; i++)
    {
        shu[i] = (int*)malloc(3 * sizeof(int));
        if (shu[i] == NULL)
        {
            printf("�ڴ����ʧ�ܣ�\n");
        }
    }

    //����Ҫ��������������ݲ������ά������
    for (i = 0; i < DataNum_int; i++)
    {
        //��֤�������ظ�����
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

    //����ά�����е�������ݰ��ո�ʽҪ��д����Ӧ�ļ���
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

    //����Ļ������ɵ����ݼ�¼
    fprintf(stdout, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d,", shu[i][j]);
        }
        printf("%d\n", shu[i][j]);
    }

    //�ͷŶ�̬������ڴ�ռ�
    {
        for (i = 0; i < DataNum_int; i++)
        {
            free(shu[i]);
        }
        free(shu);
    }

    //�ر��ļ�
    if (fclose(fp) == EOF)
    {
        printf("Can't close this file!\n");
        exit(1);
    }
}

/***********************************************
��������:
GenerateDataFiles_StructArr
��������:
�����û�ָ������������ݣ��Խṹ���������ʽ�洢������Ļ�������д����Ӧ�ļ�
��������:
���ͱ��������ڴ洢�û���������������ݵĸ���
�ַ���ָ�룬���ڴ洢�������ݵĴ洢�ļ���
**********************************************/
void GenerateDataFiles_StructArr(int DataNum_int, const char* filename)
{
    DATAITEM* data = NULL;
    int i;
    srand(time(NULL));//���������
    FILE* fp;

    //���ļ�
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("Can't open this file!\n");
        exit(1);
    }

    //�����û������붯̬�����������ڴ�ռ䣬�Խṹ������ķ�ʽʹ�øÿռ�
    data = (DATAITEM*)malloc(DataNum_int * sizeof(DATAITEM));
    if (data == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
    }

    //�����������
    for (i = 0; i < DataNum_int; i++)
    {
        //��֤�������ظ�����
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

    //���������д��Ĭ���ļ���
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

    //����Ļ������ɵ����ݼ�¼
    fprintf(stdout, "%d\n", DataNum_int);
    for (i = 0; i < DataNum_int; i++)
    {
        printf("%d,", data[i].item1);
        printf("%d,", data[i].item2);
        printf("%d\n", data[i].item3);
    }

    //�ͷŶ�̬������ڴ�ռ�
    free(data);

    //�ر��ļ�
    if (fclose(fp) == EOF)
    {
        printf("Can't close this file!\n");
        exit(1);
    }
}

/***********************************************
��������:
scandata
��������:
��ȡָ�������ļ��е����ݲ�������Ӧ�Ľṹ�������
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