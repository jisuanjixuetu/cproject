#include<stdio.h>
#include <windows.h>

void HTMLS(char *filename, char **character, int num[20]);

int main(int argc,char*argv[])
{
    FILE*file;
    file = fopen(argv[1],"r");
    char **character;
    character = (char**)malloc(sizeof(char*)*10);
    int i;
    for(i = 0;i<10;i++)
        character[i] = (char*)malloc(sizeof(char)*20);
    int num[20];//读取文件中的数字
    int count;
    for(count = 0;count<5;count++){
        fscanf(file,"%s %d",character[count],&num[count]);
    }
    fclose(file);
    HTMLS(argv[2],character,num);
    int n;
    printf("直接打开网页请输入0，不直接打开请输入1\n");
    scanf("%d",&n);
    if(n==0){
        system(argv[2]);//直接打开html文件
    }
    else
        printf("C:\\Users\\86199\\Dev.c\\%s",argv[2]);//返回路径
    return 0;
}
void HTMLS(char *filename,char**character,int *num)
{
    FILE*fp;
    fp = fopen(filename,"w");//创建文件
    fprintf(fp,"<!DOCTYPE html>\n");
    fprintf(fp,"<html>\n");
    fprintf(fp,"\n");
    fprintf(fp,"<body>\n");
    fprintf(fp,"	<table>\n");
    fprintf(fp,"		<tr>\n");
    fprintf(fp,"			<th>%s</th>\n",character[0]);
    fprintf(fp,"			<th>%s</th>\n",character[1]);
    fprintf(fp,"			<th>%s</th>\n",character[2]);
    fprintf(fp,"			<th>%s</th>\n",character[3]);
    fprintf(fp,"			<th>%s</th>\n",character[4]);
    fprintf(fp,"		</tr>\n");
    fprintf(fp,"		<tr>\n");
    fprintf(fp,"			<td>%d</td>\n",num[0]);
    fprintf(fp,"			<td>%d</td>\n",num[1]);
    fprintf(fp,"			<td>%d</td>\n",num[2]);
    fprintf(fp,"			<td>%d</td>\n",num[3]);
    fprintf(fp,"			<td>%d</td>\n",num[4]);
    fprintf(fp,"		</tr>\n");
    fprintf(fp,"	</table>\n");
    fprintf(fp,"</body>\n");
    fprintf(fp,"\n");
    fprintf(fp,"</html>\n");
    fclose(fp);
}
