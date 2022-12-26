#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void menu();
int get_file_list(const char *path, char **filename);//得到文件名
void case1(char*argv[]);//输入1
void case2();//输入2
void HTML(char*HTMLname[]);

int main(int argc,char *argv[])
{
    clock_t start_time,end_time;
    start_time = clock();//开始时间
    int n;
    menu();//菜单
    scanf("%d",&n);
    while(n!=0)
    {
        switch(n){
            case 1:
                case1(argv);//输入1
                break;
            case 2:
                case2();
                break;
            default:
                break;
        }
    }
    end_time = clock();//开始时间
    printf("%lf",(double)(end_time-start_time)/CLOCKS_PER_SEC);
    return 0;

}

void menu(){
    printf("对单个英文文档进行处理请按1\n");
    printf("对多个英文文档进行处理请按2\n");
    printf("退出请按0\n");
}
int get_file_list(const char *path, char **filename) {
    char cmd[150] = "";
    FILE *fptr;
    strcat(cmd, "dir ");
    strcat(cmd, path);
    strcat(cmd, " /s /b > a.log");
    printf("%s",cmd);
    system(cmd);
    fptr = fopen("a.log", "r+");
    if (fptr == NULL) {
        printf("path '/s' is not exit/n", path);
    }
    int count;
    count = 0;//记录多少文件
    char temp[100] = ""; int i = 0;
    while (fgets(temp, 100, fptr) != NULL) {
        strcpy(filename[i], strrchr(temp, '\\') + 1);
        filename[i][strlen(filename[i]) - 1] = 0;
        i++;
        count++;
    }
    fclose(fptr);
    return count;
}

void case1(char*argv[])
{
    char str[100] = "Lab5_1.exe";
    strcat(str," ");//加空格
    strcat(str,argv[1]);//加第二个参数
    strcat(str," ");//加空格
    strcat(str,argv[2]);//加第三个参数
    system(str);//运行，相当于命令行
    char task2[100] = "lab5task2.exe";
    strcat(task2," ");
    strcat(task2,"result.txt");
    strcat(task2," ");
    strcat(task2,argv[3]);
    system(task2);
    menu();
}

void case2()
{
    char path[100] = "C:\\Users\\86199\\Desktop\\Lab5\\files";
    char filename[100][100]; //存放文件名
    char *pfn[100];
    int i;
    for(i = 0; i < 100; i++)
    {
        filename[i][0] = 0;
        pfn[i] = filename[i];
    }
    int k;
    int count;
    count = get_file_list(path, pfn);//读取文件夹并返回文件个数
    char*htmlname[count];//网页名
    char*htmlpathname[count];//网页路径名
    char pathname[100] = "C:\\Users\\86199\\Desktop\\Lab5\\";//文件路径
    for (k = 0; k < count; k++) {
        printf("请输入文件保存的名称\n");
        scanf("%s",htmlname[k]);
        system("Lab5.1.exe filename[k] result.txt");//调用程序1
        system("Lab5.exe result.txt htmlname[k]");//生成HTML文件
        strcat(pathname,htmlname[k]);
        strcpy(htmlpathname[k],pathname);
    }
    HTML(htmlpathname);

}

void HTML(char*HTMLname[])
{
    FILE*fp;
    fp = fopen("TotalHTML.HTML","w");
    fprintf(fp,"<!DOCTYPE html>\n");
    fprintf(fp,"<html>\n");
    fprintf(fp,"\n");
    fprintf(fp,"<body>\n");
    fprintf(fp,"	<table>\n");
    fprintf(fp,"		<tr>\n");
    fprintf(fp,"			<td>%s</td>\n",HTMLname[0]);
    fprintf(fp,"			<td>%d</td>\n",HTMLname[1]);
    fprintf(fp,"			<td>%d</td>\n",HTMLname[2]);
    fprintf(fp,"			<td>%d</td>\n",HTMLname[3]);
    fprintf(fp,"		</tr>\n");
    fprintf(fp,"	</table>\n");
    fprintf(fp,"</body>\n");
    fprintf(fp,"\n");
    fprintf(fp,"</html>\n");
    fclose(fp);
    //char wwww[100]="C:\\Program Files\\Mozilla Firefox\\firefox.exe C:\\Users\\86199\\Dev.c\\";
    //strcat(wwww,"TotalHTML.HTML");
    system("TotalHTML.HTML");
    //WinExec(wwww);//打开网页
}