//
// Created by 86199 on 2022/10/9.
//

#ifndef EDITOR_LINE_EDITOR_H
#define EDITOR_LINE_EDITOR_H
typedef struct Stack{
    char chara[100];
    int base;
    int top;
}stack;
void push(stack*stack1,char ch);
void pop(stack*stack1);
void clear(stack*stack1);
#endif //EDITOR_LINE_EDITOR_H
