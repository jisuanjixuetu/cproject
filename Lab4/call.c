//
// Created by 86199 on 2022/11/17.
//
#include<string.h>
#include<stdlib.h>
#include "call.h"
void call(char *filename,int number){
    if(strcmp(filename,"datafile.txt")==0)
    {
        system("Lab3.exe");
    }
    else{
        system("Lab3.exe number filename");
    }
}