#include <stdio.h>
#include "line.editor.h"

int main() {
    stack stack1;
    char ch;
    while((ch = getchar())!='\n')
    {
        switch(ch){
            case'#':
                pop(&stack1);
                break;
            case'@':
                clear(&stack1);
                break;
            default:
                push(&stack1,ch);
                break;
        }
    }
    if(stack1.top!=stack1.base){
        for(int i  = 0;i<stack1.top;i++)
            printf("%c",stack1.chara[i]);}
    else{
            printf("please enter a character\n");
        }
    return 0;
}
