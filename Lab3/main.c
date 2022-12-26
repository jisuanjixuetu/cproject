#include <stdio.h>
#include "run.h"



int main(int argc,char*argv[]) {
    printf("What function do you want to run,erwei shuzu qing an 1 or jiegouti qinganer 2");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        run(argc,argv,choice);
    else if(choice==2)
        run(argc,argv,choice);
    return 0;
}
