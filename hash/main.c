#include<stdio.h>
#include<stdlib.h>
#define NUM 5
typedef struct HashList
{
	int num;			//表内当前的数据个数
	char *data;			//保存数据的数组
}HashList;

//hash表的初始化
HashList *initList()
{
	HashList *list = (HashList *)malloc(sizeof(char)*NUM);
	list->num = 0;
	list->data = (char*)malloc(sizeof(char)*NUM);
	for(int i = 0;i < NUM;i++)
	{
		list->data[i] = 0;		//将表内元素初始化为0
	}
	return list;
}

//获取位置的下标
int hash(int data)
{
	return data % NUM;
}

//放入哈希表
void put(HashList *list,char data)
{
	int index = hash(data);		//获取下标
	if(list->data[index] != 0)
	{
		int count = 1;			//计数，便于解决冲突
		while(list->data[index] != 0)
		{
			index = hash(hash(data) + count);	//解决冲突，如果下标位置有数据，则下标+1，直至下标位置上没有数据
			count++;
		}
	}
	list->data[index] = data;
}

int main()
{
	HashList *list = initList();
	char str[10];
	scanf("%s",str);
	int i;
	for(i = 0;str[i] != '\0';i++)
	{
		put(list,str[i]);
	}
	int j = 0;
	while(j<i)
	{
		printf("%c\n",list->data[j++]);
	}
}


