#include <stdio.h>
#include "main.h"

int main(int argc,char *argv[]) {
    printf("����������Ҫ�Ĺ���ģʽ :\n");
    printf("�������Ҫ��Ĭģʽ������: 1.\n");
    printf("�������Ҫ����ģʽ������ :2.\n");
    int choice;
    scanf("%d",&choice);
    run(argc,argv,choice);
    return 0;
}
