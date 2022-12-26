//
// Created by 86199 on 2022/10/19.
//

#include "data.h"

#ifndef LAB3_FUN_H
#define LAB3_FUN_H
void check(int argc,char*argv[],int choice);
void check1(int number);
void check2(int number,char *argv[]);
void check3(int number,char *argv[]);
void choice1(int number,char*path);
void choice2(int number,char *path);
void choice11(int number,char *path);
void choice22(int number,char *path);
void readInput(int argc,char *argv[]);
int randomInt(int max,int min);
extern struct configinfo CONF;

#endif //LAB3_FUN_H
