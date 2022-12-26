//
// Created by 86199 on 2022/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "loadfile.h"

void run(int argc,char *argv[],int choice){
    if(choice==1)
    {
        fun(choice);
    }
    else if(choice ==2)
    {
        fun(choice);
    } else
        printf("the command you input is nor correct.\n");
}