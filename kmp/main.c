#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void getNext(char t[], int next[]){
    next[0] = 0;
    next[1] = 1;
    for(int i = 1, j = 0; i < strlen(t); i++){
        while (j > 0 && t[i] != t[j]){
            //000120
            j = next[j-1];
        }
        if(t[i] == t[j]){
            j++;
        }
        next[i+1] = j+1;
    }
}


int KMP(char *s, char *t) {
    int next[16];
    getNext(t, next);
    for(int i = 1, j = 1; i < strlen(s); i++){
        while(s[i-1] != t[j-1] && j>1) {
            j = next[j];
        }
        if(s[i-1] == t[j-1]){
            j++;
        }
        if(strlen(t) == j)
            return i-j;
        if(strlen(s) == i)
            return false;
    }
}


int main(){
    char t[11] = "ADABBADADA";
    char s[22] = "ADBADABBAABADABBADADA";
    int next[10];
    getNext(t, next);
    for(int i = 0;i<10;i++)
        printf("%d\n",next[i]);
    int index = KMP(s, t);
    if(index){
        printf("right,the index is:%d\n", index+1);
    }
    else
        printf("no right string\n");
    return 0;
}

