//
// Created by 86199 on 2022/10/9.
//

#include <stdio.h>
#include <string.h>
#include "eigthqueen.h"
int OK(int i,int j,int a[]){
    int i1 = i;//lie
    int j1 = j;//hang
    int ok = 1;
    //check the hang if it can hold the queen
    if(j>=0&&ok)
    {
        for(int k = 0;k<strlen(a);k++)
        {
            if(j==a[k])
            {
                ok = 0;
                break;
            }
        }
    }
    if(j>=0&&ok){

    }

}
void queen(int j,int a[]){
    static method = 0;//method for the queen
    if(j>=queens){
        method++;
        printf("method = %d",method);
    }
    for(int i = 0;i<queens;i++){
        if(OK(i,j,a)){
            a[j] = i;
            queen(j+1,a);
        }
    }
}