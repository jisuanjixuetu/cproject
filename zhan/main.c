#include<stdio.h>
typedef struct zhan{
    int stack[30];
    int top1;
    int top2;
}dustack;
typedef struct Stacks{
    int num[30];
    int base;
    int top;
}stacks;
void push(int i,int x,dustack *stack1);
void pop(int i,int x,stacks *stack1)
void conversion(dustack*stack2);
int main(void){
    dustack stack1;
    stacks stack2;
    stack2.base = 0;
    stack2.top = 0;
    stack1.top2 = 30;
    stack1.top1 = 0;
}
void push(int i,int x,dustack *stack1){
    if(stack1->top1 == stack1->top2-1)
        printf("shangyi\n");
    else if(i == 1){
        stack1->stack[stack1->top1];
        stack1->top1++;
    }
    else{
        stack1->stack[stack1->top2];
        stack1->top2--;
    }
}
void pop(int i,int x,dustack *stack1){
    if(i==1){
        if(stack1->top1==0)
            printf("xiayi\n");
        else
        {
            int t;
            t = stack1->stack[stack1->top1-1];
            stack1->top1--;
        }
    }
    else{
        if(stack1->top2 == 30)
            printf("xiayi\n");
        else{
            int t;
            t = stack1->stack[stack1->top2-1];
            stack1->top2++;
        }
    }
}
//void conversion(dustack *stack2){
//    int num;
//    scanf("%d",&num);
//    while(num!=0){
//        push(stack2,num%8);
//        num = num/8;
}
//}