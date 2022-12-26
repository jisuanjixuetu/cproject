#include <stdio.h>
#include "main.h"

int main(int argc,char *argv[]) {
    printf("请输入你想要的工作模式 :\n");
    printf("如果你想要静默模式请输入: 1.\n");
    printf("如果你想要交互模式请输入 :2.\n");
    int choice;
    scanf("%d",&choice);
    run(argc,argv,choice);
    return 0;
}
