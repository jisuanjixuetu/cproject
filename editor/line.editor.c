//
// Created by 86199 on 2022/10/9.
//

#include <stdio.h>
#include "line.editor.h"
void push(stack *stack1,char ch){
    if(stack1->top!=30)
    {
        stack1->chara[stack1->top] = ch;
        stack1->top++;
    }
    else{
        printf("overflow\n");
    }
}
void pop(stack *stack1){
    if(stack1->top!=stack1->base)
    {
        stack1->top--;
    }
    else
    {
        printf("lowflow\n");
    }
}
void clear(stack*stack1){
    stack1->top = 0;
}