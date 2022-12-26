//
// Created by 86199 on 2022/11/9.
//

#include "Lab3.run.h"
#include<stdio.h>
#include<string.h>
#include"Lab3_fun.h"
#include"Lab3.data.h"

extern CONF info;


void run(int argc, char* argv[])
{
    scandata();

    char filepath[100];
    strcpy(filepath, info.filesavepath);
    strcat(filepath, "/");
    strcat(filepath, info.filename);

    ifFileName(filepath);

    GenerateDataFiles_2dArr(info.number, info.filename);

}