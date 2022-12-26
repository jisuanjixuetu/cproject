//����Ϊ���ظ��Ĺؼ��֣�����ͬ��
//���ɲ���ɾ����˳��仯���ı��ϣ��
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define NULL 0
typedef int KeyType;//�������������
typedef struct{
	KeyType key;
	char value;
}Table;

int Haxi(KeyType key,int length)//���ó��������������ϣ����
{
	int i,p,flag;
	for(p=length;p>=2;p--)//�����������������
	{
		for(i=2,flag=1;i<=p/2&&flag;i++)//ͨ�����ϵĳ����ж�
		{
			if(p%i==0)
				flag=0;//��������ֹ��ѭ��
		}
		if(flag==1)
			break;//�ǵĻ���ֹѭ��
	}
	return key%p;//��ϣ��ַ
}

void Datatable(Table **ST,int n,int length)//�������������
{
	int i;
	(*ST)=(Table*)malloc(length*sizeof(Table));//��̬�����ڴ����ʼ��ַ,�ͱ���Сһ����Ϊ�˺�����뷽��
	printf("\n ������ %d ������: ",n);
	for(i=0;i<n;i++)
	{
		printf("\n��%d��:  (�� �ո� ֵ)",i+1);
		fflush(stdin);/*������뻺����*/
		scanf("%d %c",&((*ST)[i].key),&((*ST)[i].value));
	}
}

void Haxitable(Table **HAXI,Table *ST,int n,int length)//������ϣ��
{
	int i,j;
	(*HAXI)=(Table*)malloc(length*sizeof(Table));
	for(i=0;i<length;i++)
	{
		(*HAXI)[i].key=NULL;//��ʼ��
		(*HAXI)[i].value=0;
	}
	for(i=0;i<n;i++)
	{
		j=Haxi(ST[i].key,length);//��ù�ϣ��ַ
		while((*HAXI)[j].key!=NULL)//��������̽����ɢ�н����ͻ
			j=(j+1)%length;
		(*HAXI)[j].key=ST[i].key;//�����ݷ����ϣ��
		(*HAXI)[j].value=ST[i].value;
	}
//	for(i=0;i<n;i++)
//		printf("���ݿ��%d����%d\n",i,ST[i].key);//��֤˼·
	printf("\n��ϣ���������\n");
}

void Show(Table *HAXI,int length)
{
	int i;
	printf("\n          ****************��ϣ��**************\n");
	printf("��:       *****");
	for(i=0;i<length;i++)
		printf("%6d",HAXI[i].key);
	printf("\n");
	printf("ֵ:       *****");
	for(i=0;i<length;i++)
		printf("%6c",HAXI[i].value);
	printf("\n");
	printf("��ַ:     *****");
	for(i=0;i<length;i++)
		printf("%6d",i);
	printf("\n");
}
int Search(Table *HAXI,KeyType key,int length)//���ҷ���
{
	int i;
	i=Haxi(key,length);//��ϣ�������λ��
	while(HAXI[i].key!=0&&HAXI[i].key!=key)
	{
		i=(i+1)%length;//���ù���ʱ�����ͻ�ķ��������ͻ
	}
	if(HAXI[i].key==0)
		return -1;
	else
		return i;
}

void Insert(Table **ST,KeyType key,int n,char value)//���뷽��
{

	(*ST)[n].key=key;//ֱ���ڵ�ǰ���ݱ���������
	(*ST)[n].value=value;
}

int Delete(KeyType key,Table **ST,int n)//ɾ������
{
	int i;
	for(i=0;i<n;i++)
	{
		if((*ST)[i].key==key)//�ҵ���Ҫɾ���Ĺؼ���
		{
			for(i;i<n-1;i++)
			{
				(*ST)[i].key=(*ST)[i+1].key;//�����ɾ������Ҫ�ƶ�
				(*ST)[i].value=(*ST)[i+1].value;
			}
			(*ST)[n-1].key=0;//�����һ������Ϊ0
			(*ST)[n-1].value=0;
			break;//����ѭ��
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
	printf("��ӭ���й�ϣ��������������ѡ��:\n");
	while(1)
	{
		printf("\n1  ������ϣ��\n");
		printf("2  ��ʾ��ϣ��\n");
		printf("3  ����Ԫ��\n");
		printf("4  ����Ԫ��\n");
		printf("5  ɾ��Ԫ��\n");
		printf("6  �˳�\n");
		printf("���������ѡ��");
		scanf("%d",&number);
		switch(number)
		{
			case 1:
				do
				{
					printf("\n ������ؼ��ָ����ͱ�������,�� ��<=����");
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
				printf("��������Ҫ���ҵĹؼ��֣�");
				scanf("%d",&key);
				if(Search(HAXI,key,length)==-1)
					printf("δ��ѯ��");
				else
					printf("���ҳɹ���λ����%dֵΪ%c",Search(HAXI,key,length),HAXI[Search(HAXI,key,length)].value);
				break;
			case 4:
				if(n>=length)//�ж��Ƿ���
					printf("��ϣ�����������ɲ��룡");
				else
				{
					printf("��������Ҫ����Ĺؼ��ֺ�ֵ��");
					scanf("%d %c",&key,&value);
					Insert(&ST,key,n,value);
					n++;//������Ҫ��һ�ٽ�����ϣ��
					Haxitable(&HAXI,ST,n,length);
					printf("����ɹ�����ǰ��%d������,��Ϊ%d ",n,length);
				}
				break;
			case 5:
				if(n==0)//�ж��Ƿ���
					printf("��ϣ��Ϊ�գ�����ɾ����");
				else
				{
					printf("��������Ҫɾ���Ĺؼ��֣�");
					scanf("%d",&key);
					if(Delete(key,&ST,n)==-1)//û���ҵ���ɾ��ʧ��
						printf("ɾ��ʧ��");
					else
					{
						n--;
						Haxitable(&HAXI,ST,n,length);
						printf("ɾ���ɹ�����ǰ��%d������,��Ϊ%d ",n,length);
					}
				}
				break;
			case 6:
				printf("ллʹ�ã�");
				exit(0);
			default :
				printf("�������\n");
		}
	}

}

