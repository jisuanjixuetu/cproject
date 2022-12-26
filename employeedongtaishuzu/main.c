#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INCRESE 5
#define INITE_SIZE 40

typedef struct slist{
    char **name;//name
    int *number;//number
    char **label;//label
    int length;
    int size;
}node,*Slist;

typedef struct employ{
    char name[100];
    int number;
    char label[100];
}Em,*employee;//employee

void employee_information(employee e);//input the information
void Insert(Slist q);//inemployed
void Delete(Slist q);//outemployed
int find(char *sname,Slist q);//locate
void relocate(Slist q,int i); //replace
void search(Slist q);//slearch fot the employee
void input_file(Slist q);

int main()
{
    Slist Employee;//company employee list
    Employee = (Slist)malloc(sizeof(node));//attribute space
    Employee->size = INITE_SIZE;
    Employee->name = (char**)malloc(INITE_SIZE*sizeof(char*));//开辟行空间
    int i;
    for(i = 0;i<(Employee->size);i++)
        Employee->name[i] = (char*)malloc(sizeof(char)*INITE_SIZE);
    Employee->label = (char**)malloc(INITE_SIZE*sizeof(char*));
    for(i = 0;i<(Employee->size);i++)
        Employee->label[i] = (char*)malloc(sizeof(char)*INITE_SIZE);
    Employee->length = 0;
    Employee->number = (int*)malloc(INITE_SIZE*sizeof(int));
    FILE*fp;//文件指针；
    fp = fopen("employee.txt","r");//打开文件
    int m;
    m = 0;
    if(!fp)
        printf("error\n");
    while(!feof(fp))
    {

        fscanf(fp,"%s%s%d",Employee->name[m],Employee->label[m],&(Employee->number[m]));
        m++;
        Employee->length++;
    }
    printf("%s\n",Employee->name[0]);
    fclose(fp);
    printf("if you want to insert please enter 1\n");
    printf("if you want to delete,please enter 2\n");
    printf("if you want to search someone,please enter 3\n");
    int choice;//input the choice
    printf("please input int:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            Insert(Employee);
            break;
        case 2:
            Delete(Employee);
            break;
        case 3:
            search(Employee);
            break;
    }
    int s;
    for(s = 0;s<Employee->length;s++)
        free(Employee->name[s]);
    free(Employee->name);
    for(s = 0;s<Employee->length;s++)
        free(Employee->label[s]);
    free(Employee->label);
    free(Employee->number);
    return 0;
}

void employee_information(employee e){
    printf("please enter the information of the employee\n");
    printf("please enter the number\n");
    scanf("%d",&(e->number));
    printf("please enter the name\n");
    scanf("%s",e->name);
    printf("please enter the label\n");
    scanf("%s",e->label);

}

void Insert(Slist q)
{
    employee e;
    e = (employee)malloc(sizeof(Em));
    employee_information(e);//transfer the e;
    int *newbaseNumber;//new base
    char** newbaseName;//new base
    char** newbaseLabel;//new base
    if(q->length>=q->size)//expand
    {
        int m;
        newbaseNumber = (int*)realloc(q->number, sizeof(int) * (q->size + INCRESE));
        newbaseName = (char**)realloc(q->name, sizeof(char*) * (q->size + INCRESE));//new space
        for(m = q->size;m<q->size+INCRESE;m++)
            newbaseName[m] = (char*)malloc(sizeof(char)*INITE_SIZE);
        newbaseLabel = (char**)realloc(q->label,sizeof(char*)*(q->size+INCRESE));//new space foe label
        for(m = q->size;m<q->size+INCRESE;m++)
            newbaseLabel[m] = (char*)malloc(sizeof(char)*INITE_SIZE);
        q->name = newbaseName;
        q->number = newbaseNumber;
        q->label = newbaseLabel;
        q->size += INCRESE;
    }
    printf("please enter the place\n");
    int i;
    scanf("%d",&i);
    if(i<1||i>q->length+1)
        printf("it is unleagel\n");
    else{
        int j;
        for (j = q->length; j >= i; j--)
        {
            q->number[j] =q->number[j - 1];
            q->label[j] = q->label[j - 1];
            q->name[j] = q->name[j - 1];
        }
        q->number[i-1] = e->number;
        q->label[i-1] = e->label;
        q->name[i-1] = e->name;
        q->length++;
    }
    input_file(q);
}

void Delete(Slist q)
{
    printf("the person want to out\n");
    char sname[40];
    scanf("%s",sname);
    int i;
    i = find(sname,q);
    if(i!=-1)
    {
        relocate(q,i);
        q->length--;
        input_file(q);
    }

}

int find(char *sname,Slist q)
{
    int i;// circle
    for(i = 0;i<q->length;i++)
    {
        if(strcmp(sname,q->name[i])==0)
            break;
    }
    if(i==q->length)
    {
        printf("no one\n");
        i = -1;
    }
    return i;
}

void relocate(Slist q,int i){
    int j;
    for(j = i;j<q->length-1;j++)
    {
        q->name[j]=q->name[j+1];
        q->label[j]=q->label[j+1];
        q->number[j]=q->number[j+1];
    }
    q->name[q->length-1] = NULL;
    q->label[q->length-1] = NULL;
    q->number[q->length-1] = 0;
    q->length--;
}

void search(Slist q)
{
    char name[40];
    scanf("%s",name);
    int i;
    int flag;
    flag = 0;
    for(i = 0;i<q->length;i++)
    {
        if(strcmp(name,q->name[i])==0)
        {
            printf("name:	%s",name);
            printf("label:	%s",*(q->label+i));
            printf("number:	%d\n",*(q->number+i));
            flag = 1;
            break;
        }
        else
            flag = 0;
    }
    if(flag==0)
        printf("no one\n");
}

void input_file(Slist q){
    int i;
    FILE *fp;
    fp = fopen("employee.txt","w");
    for(i = 0;i<q->length;i++)
    {
        fprintf(fp,"%s %s %d\n",*(q->name+i),*(q->label+i),*(q->number+i));
    }
    fclose(fp);
}
