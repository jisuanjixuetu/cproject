#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 225
#define SIZE 20
int strEmpty(char *chara);
int strCompare(char *chara,char*charas);
int strLength(char *chara);
void clearString(char *chara);
char *concat(char *chara,char *charas);//copycat
char *subString(char *mother,int pos,int len);//substring
void getNext(char *test,int *next);
int main() {
    char *chara;
    chara = (char*)malloc(SIZE*sizeof(char));
    char *charas;
    //charas = (char*)malloc(SIZE*sizeof(char));
    scanf("%s",chara);
    charas = chara;
    printf("%s\n",charas);
    printf("%d\n", strEmpty(charas));//is empty
    printf("%d\n",strCompare(chara,charas));//is equal?
    printf("%d\n", strLength(chara));
    char*T;
    T = concat(chara,charas);
    char *substring;
    int len = 3;
    int pos = 1;
    substring = subString(chara,pos,len);
    printf("%s\n",substring);
    printf("%s\n",T);
    clearString(chara);
    return 0;
}
int strEmpty(char *chara){
    int i;
    i = (int)strlen(chara);
    if(i == 0)
        return 0;
    else
        return 1;
}
int strCompare(char*chara,char*charas){
    int chara1 = strEmpty(chara);//is empty?
    int charas2 = strEmpty(charas);//is empty?
    int que;//prior equal after
    if(chara1!=0&&charas2!=0)
    {
        if(strcmp(chara,charas)==0)
            que = 0;
        else if(strcmp(chara,charas)>0)
            que = 1;
        else
            que = -1;
    }
    else
        que = -2;
    return que;
}
int strLength(char*chara){
    int length;
    length = (int)strlen(chara);
    return length;
}
void clearString(char *chara){
    free(chara);
}
char *concat(char*chara,char*charas){
    char*T;
    T = (char*)malloc(sizeof(char)*225);
    int i;//for the first string
    int j;//for thr second string
    if(strLength((chara)+ strLength(charas))<MAXSIZE){
        for(i = 0;i< strLength(chara);i++)
            T[i] = *(chara+i);
        for(i = strLength(chara),j = 0;i<(strLength(chara)+strLength(charas));i++,j++)
            T[i] = *(charas+j);
    }
    else if(strLength(chara)<MAXSIZE)
    {
        for(i = 0;i< strLength(chara);i++)
            T[i] = *(chara+i);
        for(i = strLength(chara),j = 0;i<MAXSIZE;i++,j++)
            T[i] = *(charas+j);
    }
    else
        for(i = 0;i<MAXSIZE;i++)
            T[i] = *(chara+i);
        T[i] = '\0';
    return T;
}
char *subString(char *mother,int pos,int len){
    if(pos<1||pos> strLength(mother)||len<0||len> strLength(mother)-pos+1)
        printf("error\n");
    int i,j;
    char *child;
    child = (char*)malloc(sizeof(char)*20);
    for(i = pos-1,j = 0;i<pos+len-1;i++,j++)
        child[j] = mother[i];
    child[j] = '\0';
    return child;
}
void getNext(char *t,int *next){
    next[0] = 0;
    int i;
    int j;
    for(i = 0,j = 0;i< strLength(t);i++){
        while(j>0&&(t[i] != t[j]))
            j = next[j-1];

    }
}