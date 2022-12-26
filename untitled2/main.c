#include<stdio.h>
int main(void){
    FILE*fp;
    fp = fopen("employee.txt","w");
    char name[20];
    char label[20];
    int num;
    scanf("%d",&num);
    scanf("%s",name);
    fprintf(fp,"%d %s",num,name);
    fclose(fp);
    return 0;
}