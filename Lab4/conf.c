//
// Created by 86199 on 2022/11/24.
//

#include <stdio.h>
#include <string.h>
#include "conf.h"
void functionFourteen(){
	printf("ʵ�����е������ļ�����\n");
	printf("�ļ�����·��:C:/ClionProject/Lab3\n");
	printf("�ļ����� default.txt\n");
	printf("������ɼ�¼���ݵ���������� 20\n");
	printf("������ɼ�¼���ݵ���С������ 1\n");
	printf("ǰ����������ɵ��������ֵ�� 100\n");
	printf("ǰ����������ɵ�������Сֵ�� 1\n");
	printf("������������ɵ��������ֵ�� 200\n");
	printf("������������ɵ��������ֵ�� 50");
	printf("��������Ҫ�ı�������ļ������ݵ�����\n");
	printf("����Դ����¼�������ѡ�� :\n"
		   "path filename maximumLine minimumLine maxvalue12 minvalue12 maxvalue3 minvalue3\n");
	FILE *fp = fopen("conf.ini","r");
	char inipath[100];
	fscanf(fp,"%s",inipath);
	char inifilename[100];
	fscanf(fp,"%s",inifilename);
	int inimaxline;
	fscanf(fp,"%d",&inimaxline);
	int iniminline;
	fscanf(fp, "%s", iniminline);
	int inimaxvalue12;
	fscanf(fp,"%d",&inimaxvalue12);
	int iniminvalue12;
	fscanf(fp, "%d", & iniminvalue12);
	int inimaxvalue3;
	fscanf(fp,"%d",&inimaxvalue3);
	int iniminvalue3;
	fscanf(fp, "%d", & iniminvalue3);
	fclose(fp);
	char change[100];
	scanf("%s",change);
	if(strcmp(change,"path")==0){
		printf("����������Ҫ�����ļ���·����\n");
		char path[100];
		scanf("%s",path);
		strcpy(inipath,path);
	}
	else if (strcmp(change, "filename")) {
		printf("��������Ҫ������ļ�����\n");
		char filename[100];
		scanf("%s",filename);
		strcpy(inifilename,filename);
	}
	else if(strcmp(change,"maximumLine")==0){
		int maximum_line;
		printf("��������Ҫ����ļ�¼���ݵ�����У�\n");
		scanf("%d",&maximum_line);
		getchar();
		inimaxline = maximum_line;
	}
	else if (strcmp(change, "minimumLine")==0){
		int minimum_line;
		printf("��������Ҫ�����¼���ݵ���С�У�\n");
		scanf("%d",&minimum_line);
		getchar();
		iniminline = minimum_line;
	}
	else if(strcmp(change,"maxvalue12")==0){
		int maxvalue12;
		printf("��������Ҫ���ɵ�ǰ������¼���ݵ����ֵ��\n");
		scanf("%d",&maxvalue12);
		getchar();
		inimaxvalue12 = maxvalue12;
	}
	else if (strcmp(change, "minvalue12")==0){
		int minvalue12;
		printf("��������Ҫ���ɵ�ǰ������¼���ݵ���Сֵ��\n");
		scanf("%d", & minvalue12);
		getchar();
		iniminvalue12 = minvalue12;
	}
	else if (strcmp(change, "maxvalue3")==0){
		int maxvalue3;
		printf("��������Ҫ���ɵļ�¼���ݵ�����ֵ�����ֵ��\n");
		scanf("%d",&maxvalue3);
		getchar();
		iniminvalue3 = maxvalue3;
	}
	else if (strcmp(change, "minvalue3")==0){
		int minvalue3;
		printf("��������Ҫ������������ݵĵ�����ֵ����Сֵ��\n");
		scanf("%d", & minvalue3);
		getchar();
		iniminvalue3 = minvalue3;
	}
	FILE*pf = fopen("conf.ini","w");
	fprintf(pf, "%s\n",inipath);
	fprintf(fp,"%s\n",inifilename);
	fprintf(fp,"%d\n",inimaxline);
	fprintf(fp, "%d\n",iniminline);
	fprintf(fp, "%d\n",inimaxvalue12);
	fprintf(fp, "%d\n",iniminvalue12);
	fprintf(fp, "%d\n",inimaxvalue3);
	fprintf(fp, "%d\n",iniminvalue3);
	fclose(fp);
}