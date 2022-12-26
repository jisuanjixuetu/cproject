//输入为不重复的关键字，插入同理
//可由插入删除的顺序变化来改变哈希表
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define NULL 0
typedef int KeyType;//起别名，方便辨别
typedef struct{
	KeyType key;
	char value;
}Table;

int Haxi(KeyType key,int length)//利用除留余数法构造哈希函数
{
	int i,p,flag;
	for(p=length;p>=2;p--)//不超过表长的最大素数
	{
		for(i=2,flag=1;i<=p/2&&flag;i++)//通过不断的除来判断
		{
			if(p%i==0)
				flag=0;//不是则终止此循环
		}
		if(flag==1)
			break;//是的话终止循环
	}
	return key%p;//哈希地址
}

void Datatable(Table **ST,int n,int length)//储存输入的数据
{
	int i;
	(*ST)=(Table*)malloc(length*sizeof(Table));//动态分配内存的起始地址,和表长大小一样，为了后面插入方便
	printf("\n 请输入 %d 个数据: ",n);
	for(i=0;i<n;i++)
	{
		printf("\n第%d个:  (键 空格 值)",i+1);
		fflush(stdin);/*清除输入缓冲区*/
		scanf("%d %c",&((*ST)[i].key),&((*ST)[i].value));
	}
}

void Haxitable(Table **HAXI,Table *ST,int n,int length)//建立哈希表
{
	int i,j;
	(*HAXI)=(Table*)malloc(length*sizeof(Table));
	for(i=0;i<length;i++)
	{
		(*HAXI)[i].key=NULL;//初始化
		(*HAXI)[i].value=0;
	}
	for(i=0;i<n;i++)
	{
		j=Haxi(ST[i].key,length);//获得哈希地址
		while((*HAXI)[j].key!=NULL)//利用线性探测再散列解决冲突
			j=(j+1)%length;
		(*HAXI)[j].key=ST[i].key;//将数据放入哈希表
		(*HAXI)[j].value=ST[i].value;
	}
//	for(i=0;i<n;i++)
//		printf("数据库第%d个是%d\n",i,ST[i].key);//验证思路
	printf("\n哈希表制作完成\n");
}

void Show(Table *HAXI,int length)
{
	int i;
	printf("\n          ****************哈希表**************\n");
	printf("键:       *****");
	for(i=0;i<length;i++)
		printf("%6d",HAXI[i].key);
	printf("\n");
	printf("值:       *****");
	for(i=0;i<length;i++)
		printf("%6c",HAXI[i].value);
	printf("\n");
	printf("地址:     *****");
	for(i=0;i<length;i++)
		printf("%6d",i);
	printf("\n");
}
int Search(Table *HAXI,KeyType key,int length)//查找方法
{
	int i;
	i=Haxi(key,length);//哈希函数获得位置
	while(HAXI[i].key!=0&&HAXI[i].key!=key)
	{
		i=(i+1)%length;//利用构造时解决冲突的方法解决冲突
	}
	if(HAXI[i].key==0)
		return -1;
	else
		return i;
}

void Insert(Table **ST,KeyType key,int n,char value)//插入方法
{

	(*ST)[n].key=key;//直接在当前数据表后添加数据
	(*ST)[n].value=value;
}

int Delete(KeyType key,Table **ST,int n)//删除方法
{
	int i;
	for(i=0;i<n;i++)
	{
		if((*ST)[i].key==key)//找到需要删除的关键字
		{
			for(i;i<n-1;i++)
			{
				(*ST)[i].key=(*ST)[i+1].key;//数组的删除，需要移动
				(*ST)[i].value=(*ST)[i+1].value;
			}
			(*ST)[n-1].key=0;//让最后一个数据为0
			(*ST)[n-1].value=0;
			break;//跳出循环
		}
		if((*ST)[i].key!=key&&i==n-1)
			return -1;
	}
	return 1;
}

void main()
{
	Table *ST,*HAXI;
	KeyType key;
	int n,length;
	int number,i;
	char value;
	printf("欢迎进行哈希表的制作，请进行选择:\n");
	while(1)
	{
		printf("\n1  建立哈希表\n");
		printf("2  显示哈希表\n");
		printf("3  查找元素\n");
		printf("4  插入元素\n");
		printf("5  删除元素\n");
		printf("6  退出\n");
		printf("请输入你的选择：");
		scanf("%d",&number);
		switch(number)
		{
			case 1:
				do
				{
					printf("\n 请输入关键字个数和表长（个数,表长 且<=）：");
					scanf("%d,%d",&n,&length);
				}
				while(n>length);
				Datatable(&ST,n,length);
				Haxitable(&HAXI,ST,n,length);
				break;
			case 2:
				Show(HAXI,length);
				break;
			case 3:
				printf("请输入想要查找的关键字：");
				scanf("%d",&key);
				if(Search(HAXI,key,length)==-1)
					printf("未查询到");
				else
					printf("查找成功！位置是%d值为%c",Search(HAXI,key,length),HAXI[Search(HAXI,key,length)].value);
				break;
			case 4:
				if(n>=length)//判断是否满
					printf("哈希表已满，不可插入！");
				else
				{
					printf("请输入想要插入的关键字和值：");
					scanf("%d %c",&key,&value);
					Insert(&ST,key,n,value);
					n++;//数据需要加一再建立哈希表
					Haxitable(&HAXI,ST,n,length);
					printf("插入成功！当前有%d个数据,表长为%d ",n,length);
				}
				break;
			case 5:
				if(n==0)//判断是否满
					printf("哈希表为空，不可删除！");
				else
				{
					printf("请输入想要删除的关键字：");
					scanf("%d",&key);
					if(Delete(key,&ST,n)==-1)//没有找到则删除失败
						printf("删除失败");
					else
					{
						n--;
						Haxitable(&HAXI,ST,n,length);
						printf("删除成功！当前有%d个数据,表长为%d ",n,length);
					}
				}
				break;
			case 6:
				printf("谢谢使用！");
				exit(0);
			default :
				printf("输入错误\n");
		}
	}

}

