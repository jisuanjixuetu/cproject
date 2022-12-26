//
// Created by 86199 on 2022/11/24.
//

#include <stdio.h>
#include <string.h>
#include "conf.h"
void functionFourteen(){
	printf("实验三中的配置文件如下\n");
	printf("文件保存路径:C:/ClionProject/Lab3\n");
	printf("文件名是 default.txt\n");
	printf("随机生成记录数据的最大行数是 20\n");
	printf("随机生成记录数据的最小行数是 1\n");
	printf("前两个随机生成的数的最大值是 100\n");
	printf("前两个随机生成的数的最小值是 1\n");
	printf("第三个随机生成的数的最大值是 200\n");
	printf("第三个随机生成的数的最大值是 50");
	printf("请输入你要改变的配置文件的数据的名称\n");
	printf("你可以从以下几个方面选择 :\n"
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
		printf("请输入你想要保存文件的路径：\n");
		char path[100];
		scanf("%s",path);
		strcpy(inipath,path);
	}
	else if (strcmp(change, "filename")) {
		printf("请输入你要保存的文件名：\n");
		char filename[100];
		scanf("%s",filename);
		strcpy(inifilename,filename);
	}
	else if(strcmp(change,"maximumLine")==0){
		int maximum_line;
		printf("请输入你要保存的记录数据的最大行：\n");
		scanf("%d",&maximum_line);
		getchar();
		inimaxline = maximum_line;
	}
	else if (strcmp(change, "minimumLine")==0){
		int minimum_line;
		printf("请输入你要保存记录数据的最小行：\n");
		scanf("%d",&minimum_line);
		getchar();
		iniminline = minimum_line;
	}
	else if(strcmp(change,"maxvalue12")==0){
		int maxvalue12;
		printf("请输入你要生成的前两个记录数据的最大值：\n");
		scanf("%d",&maxvalue12);
		getchar();
		inimaxvalue12 = maxvalue12;
	}
	else if (strcmp(change, "minvalue12")==0){
		int minvalue12;
		printf("请输入你要生成的前两个记录数据的最小值：\n");
		scanf("%d", & minvalue12);
		getchar();
		iniminvalue12 = minvalue12;
	}
	else if (strcmp(change, "maxvalue3")==0){
		int maxvalue3;
		printf("请输入你要生成的记录数据第三个值的最大值：\n");
		scanf("%d",&maxvalue3);
		getchar();
		iniminvalue3 = maxvalue3;
	}
	else if (strcmp(change, "minvalue3")==0){
		int minvalue3;
		printf("请输入你要保存的生成数据的第三个值的最小值：\n");
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