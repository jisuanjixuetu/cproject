#include <stdio.h>
#include <string.h>

struct stack{
    char character[5];
    int top;
    int base;
}stacks;
char charstore[100];
struct stack Stack[8];
void store(struct stack stacks[]);
void print(int i,char number[]);

int main() {
    setbuf(stdout,NULL);
    store(Stack);//store the alpha for each number
    printf("please enter some numbers\n");
    char number[100];//user input the numbers
    scanf("%s",number);
    print(0,number);//output
    return 0;
}
void store(struct stack stacks[]){
    int i;
    char alpha[26] = "abcdefghigklmnopqrstuvwxyz";//store the alpha for each key
    for(int j = 0;j<8;j++)
    {
        stacks[j].base = 0;
        stacks[j].top = 0;
    }//initialize each key
    for(i = 0;i<15;i++){
        stacks[i/3].character[i%3] = alpha[i];//allocate each alpha for each key
        stacks[i/3].top++;
    }
    for(i = 15;i<19;i++)
    {
        stacks[5].character[(i+1)%4] =alpha[i];
        stacks[5].top++;
    }
    for(i = 19;i<22;i++)
    {
        stacks[6].character[(i-1)%3] =alpha[i];
        stacks[6].top++;
    }
    for(i = 22;i<26;i++)
    {
        stacks[7].character[(i-2)%4] =alpha[i];
        stacks[7].top++;
    }
}
void print(int i,char number[]) {
    if (number[i] != 1) {
        int k = 0;
        for (k = 0; k < Stack[number[i]-'0'-2].top; k++) {
            charstore[i] = Stack[number[i]-'0'-2].character[k];
            if (i == strlen(number) - 1) {
                for (int j = 0; j < strlen(number); j++)
                    printf("%c", charstore[j]);
                printf("\n");
                continue;
            } else
                print(i + 1, number);
        }
    }
}