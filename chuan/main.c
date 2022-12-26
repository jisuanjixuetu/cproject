#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 225
#define SIZE 20
int strEmpty(char *chara);
int strCompare(char *chara,char*charas);
int strLength(char *chara);
void clearString(char *chara);
char *concat(char *chara,char *charas);//copycat
char *subString(char *mother,int pos,int len);//substring
int index(char *motehr,char*child,int pos);//the simple
int dex(char *mother,char *child,int pos);
//int KMP(char *s,char *t);
//int *getNext(char *t);
char *strAssign(char*s);//copy s to t
int lengthen(char *chara);
void *NiZhi(char*s,char*t,int i,int j);
char *Merge(char*s,char*t);
int *getIndex(char *s,char*r);
void replace(char*s,char t,char v);
void insert(char *s,char*t,int pos);
int main() {
    char *chara;
    chara = (char*)malloc(SIZE*sizeof(char));
    char *charas;
    //charas = (char*)malloc(SIZE*sizeof(char));
    printf("please enter some chars\n");
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
    char*mother;
    char*child;
    mother = (char*)malloc(sizeof(char)*20);
    child = (char*)malloc(sizeof(char)*10);
    scanf("%s",mother);
    scanf("%s",child);
    int i;
    int poss;
    poss = 3;
    i = index(mother,child,poss);
    printf("%d\n",i);
    int j;
    j = index(mother,child,poss);
    printf("%d\n",j);
//    int s;//for teh kmp;
//    s = KMP(mother,child);
//    printf("%d",s);
//    clearString(chara);
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
    	for(i = 0;i<strlen(chara);i++)
    	{
    		if(chara[i]>charas[i])
    		{
    			flag = 1;
    			break;
			}
    		else{
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
    child = (char*)malloc(sizeof(char)*(len+1));
    for(i = pos-1,j = 0;i<pos+len-1;i++,j++)
        child[j] = mother[i];
    child[i] = '\0';
    return child;
}
int index(char *mother,char*child,int pos){
    int i;//for the place
    i = pos;
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
        return false;
}
int dex(char*mother,char*child,int pos){
    int length1;
    length1= strLength(mother);
    int length2;
    length2 = strLength(child);
    int i;
    i = pos;
    int k,j;
    while(i<length1-length2+1)
    {
        if(mother[i-1] != child[0])//chongxin check the new node
            i++;
        else if(mother[i+length2-1]!=child[length2-1])//tail is not peak
            i++;
        else{
            k = 1;//for the child;
            j = 0;//for the mother;
            while(j<length2&&mother[i+j] == child[k])//check the character in the middle
            {
                i++;
                k++;
            }
            if(j == length2)
                return i;
            else
                i++;	//renew
        }
        return 0;
    }
}
//int *getNext(char *t){
//    int  *next;
//    next = (int*)malloc(sizeof(int)*20);
//    next[0] = 0;
//    for(int i = 0,j = 0;i< strLength(t);i++){
//        while(j>0&&t[i]!=t[j])//if they are not the same,huanjuhuashuojiushitamem meiyoushouweixiangtongde1yuansu
//        {
//            j = next[j-1];//kenengqianyigehuixiangtong,zebijiaohoumianjige
//        }
//        if(t[i]==t[j])//ruguoxiangtong,ze j++
//            j++;
//        next[i] = j;//ba j fezhigeinext[i]
//    }
//    return next;
//}
//int KMP(char*s,char*t)
//{
//    int *next;
//    next = getNext(t);
//    for(int i = 0,j = 0;i< strLength(s);i++)
//    {
//        while(j>0&&s[i]!=t[j])//if they are not the same,then t huishuo zhi next[j-1]ge yuansuweizhi
//            j = next[j-1];
//        if(s[i]==t[j])
//            j++;//if they are the same then j++
//        if(j == strLength(t))
//            return i-j+2;//fanhui weizhi
//        else if(i == strLength(s))
//            return false;
//    }
//}
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
int lengthen(char*chara){
	int count;
	count = 0;
	int i;
	while(chara[i]!='\0')
	{
		count++;
        i++;
	}
	return count;
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
int *getIndex(char *s,char *r)
{
	int i;//for s
	int j;//for r
	int index[strLength(r)];
	for(j = 0;i<strLength(r);i++)
	{
		for(i = 0;j<strLength(s);i++)
		{
			if(r[j]==s[i])
			break;
		}
	}
	index[j] = i;
	return index;
}
void replace(char*s,char t,char v){
    int i;//for the s
    for(i = 0;i< strLength(s);i++)
    {
        if(s[i]==t)
            s[i] = v;
    }
}
void replaces(char*s,char*before,char*after){
    int indexs;//for the index of s;
    indexs = index(s,before,0);
    int i;
    int j;
    char *newword;//for the word that insert
    newword = (char*)malloc(sizeof(char)*(strLength(s)+strLength(after)));
    if(indexs != false)
    {
        for(i = 0;i<indexs-1;i++)
        {
            newword[i] = s[i];
        }
        for(i = indexs,j = 0;i<indexs+strLength(after);i++,j++)
            newword[i] = after[j];
        for(i = indexs+ strLength(after),j = strLength(before)+indexs-1;i<(strLength(s)-strLength(before)+strLength(after));i++)
            newword[i] = s[j];
    }
    s = newword;
}
