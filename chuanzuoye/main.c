#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXSIZE 225
#define SIZE 20
int strEmpty(char *chara);
int strCompare(char *chara,char*charas);
int strLength(char *chara);
char *strAssign(char*s);//copy s to t
char *concat(char *chara,char *charas);//copycat
char *subString(char *mother,int pos,int len);//substring
void *NiZhi(char*s,char*t,int i,int j);
char *Merge(char*s,char*t);
int inde(char *mother,char*child);
char*replaces(char *s,char*before,char*after);
int main() {
    setbuf(stdout,NULL);
    char *chara;
    chara = (char*)malloc(SIZE*sizeof(char));
    char *charas;
    charas = (char*)malloc(SIZE*sizeof(char));
    printf("please enter onr string\n");
    scanf("%s",chara);
    printf("chara length:%d\n", strLength(chara));
    charas = strAssign(chara);//copy chara to charas;
    printf("%s\n",charas);
    printf("%d\n", strEmpty(chara));//is empty
    char test1[SIZE];
    char test2[SIZE];
    printf("please enter two strings\n");
    scanf("%s",test1);
    scanf("%s",test2);
    printf("bijiaojieguo:%d\n",strCompare(test1,test2));//is equal?
    char *merge;//zhaodaocunzaiyusbucunzaityut
    merge = Merge(test1,test2);
    printf("%s\n",merge);
    char*T;
    T = concat(chara,charas);
    printf("T wei:%s\n",T);
    char *substring;
    int len = 3;
    int pos = 1;
    substring = subString(chara,pos,len);
    printf("zichuhan:%s\n",substring);
    printf("please enter three strings you want to replace\n");
    char before[SIZE];
    char after[SIZE];
    char PLACE[MAXSIZE];
    scanf("%s",before);
    scanf("%s",after);
    scanf("%s",PLACE);
    char*replace;
    replace = replaces(PLACE,before,after);
    printf("after replacing:%s\n",replace);
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
    int chara1;
    chara1 = strEmpty(chara);//is empty?
    int charas2;
    charas2 = strEmpty(charas);//is empty?
    int que;//prior equal after
    int i;
    int count;
    count = 0;
    int flag;//label the daxiao
    flag = 0;
    if(chara1!=0&&charas2!=0)
    {
        for(i = 0;i<strLength(chara);i++)
        {
            if(chara[i]>charas[i])
            {
                flag = 1;
                break;
            }
            else if(chara[i]<charas[i]){
                flag = -1;
                break;
            }
        }
    }
    if(flag == 0)
        que = 0;
    else if(flag == 1)
        que = 1;
    else
        que = -1;
    return que;
}
int strLength(char*chara){
    int length = 0;
    while(chara[length]!='\0')
    {
        length++;
    }
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
    child = (char*)malloc(sizeof(char)*(len+1));
    for(i = pos-1,j = 0;i<pos+len-1;i++,j++)
        child[j] = mother[i];
    child[i] = '\0';
    return child;
}
int inde(char *mother,char*child){
    int i=0;//for the place
    int j;
    j = 1;
    while(i<strLength(mother)&&j<strLength(child)){
        if(mother[i-1]==child[j-1])//if equal
        {
            i++;
            j++;
        }
        else{
            i = i-j+2;//if not
        }
    }
    if(j==strLength(child))
        return i-strLength(child)+1;//return the place
    else
        return -1;
}

char *strAssign(char*s)
{
    char *t;
    t = (char*)malloc((strlen(s)+1)*sizeof(char));
    int i;
    for(i = 0;i<strlen(t);i++)
        t[i] = s[i];
    t[i] = '\0';
    return t;
}
void*NiZhi(char*s,char*t,int i,int j)
{
    t[j] = s[i];
    if(i<strLength(s))
        NiZhi(s,t,i-1,j+1);
    else
        t[strLength(s)] = '\0';
}
char*Merge(char*s,char*t){
    char *r;
    r = (char*)malloc((strLength(s)+strLength(t))*sizeof(char));
    int i,j;
    int count;
    count = 0;
    int flag;
    int k;
    flag = 1;//if it is in the s or t;
    for(i = 0;i<strLength(s);i++)
    {
        for(j = 0;j<strLength(t);j++)
        {
            if(s[i]!=t[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==0)
        {
            if(count == 0)
                r[count] = s[i];
            else
            {
                for(k = 0;k<strLength(r);k++)
                {
                    if(s[i]==r[k])
                        break;
                }
                if(k==strLength(r))
                    r[count] = s[i];
            }
            count++;
        }
    }
    return r;
}

char*replaces(char*s,char*before,char*after){
    int indexs;//for the index of s;
    indexs = inde(s,before);
    int i;
    int j;
    char *newword;//for the word that insert
    newword = (char*)malloc(sizeof(char)*MAXSIZE);
    if(indexs != -1)
    {
        for(i = 0;i<indexs-1;i++)
        {
            newword[i] = s[i];
        }
        for(i = indexs,j = 0;i<indexs+strLength(after);i++,j++)
            newword[i] = after[j];
        for(i = indexs+ strLength(after),j = strLength(before)+indexs-1;i<(strLength(s)-strLength(before)+strLength(after));i++,j++)
            newword[i] = s[j];
    }
    return newword;
}