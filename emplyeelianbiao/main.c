#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Lnode {
    char name[50];  // name
    char label[50]; // label
    int number;    // number
    struct Lnode *next;
}LNode, *LinkList;

void push(LinkList head); // insert
void pop(LinkList head);  // delete
void file(LinkList head); //creat the file

int leng(LinkList head);//length

int main(void) {
    FILE *fp;
    fp = fopen("employee.txt", "r"); // open the file;
    if (fp == NULL)
        printf("error");
    LinkList head;
    head = (LinkList) malloc(sizeof(LNode));
    head->next = NULL;
    while (!feof(fp)) {
        LinkList p; // store the data;
        p = (LinkList) malloc(sizeof(LNode));
        p->next = NULL;
        fscanf(fp, "%s%s%d", p->name, p->label, &p->number);
        p->next = head->next;
        head->next = p;
    }
    fclose(fp);
    printf("out company please enter 1\n");
    printf("in company please enter 2\n");
    int choice; // input the choice
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            pop(head);// insert
            break;
        case 2:
            push(head); // delete
            break;
        default:
            break;
    }
    return 0;
}

void push(LinkList head) {
    int length;
    length = leng(head);
    printf("please enter the employee\n");
    LinkList p, q;
    p = (LinkList) malloc(sizeof(LNode));
    p->next = NULL;
    q = head;
    printf("please enter the number\n");
    scanf("%d", &p->number);
    printf("please enter the name\n");
    scanf("%s", p->name);
    printf("please enter the label\n");
    scanf("%s", p->label);
    int i;//the number;
    printf("the place you want to insert\n");
    scanf("%d", &i);
    int j;
    if (i < 1 || i > length + 1)//unleagal
        printf("enlegal");
    else {
        for (j = 0; j < i-1 ; j++)
            q = q->next;
            p->next = q->next;
            q->next = p;
    }
    file(head);
}

void pop(LinkList head) {
    char sname[50];
    printf("please enter the name\n");
    scanf("%s", sname);
    LinkList p; // node to the current
    LinkList q; // node to the prior
    q = head;
    p = head->next;
    while (p) {
        if (strcmp(p->name,sname) == 0)
            break;
        else{
            p = p->next;
            q = q->next;
        }

    }
    if(!p)
    printf("no one call this name\n");
    else{
    	q->next = p->next;
    	free(p);
	}
	file(head);
}

void file(LinkList head) {
    FILE *fp;
    fp = fopen("employee.txt", "w"); // open the file;
    LinkList p;
    p = head->next;
    while (p) {
        fprintf(fp, "%s %s %d\n", p->name, p->label, p->number);
        p = p->next;
    }
    fclose(fp);
}

int leng(LinkList head) {
    LinkList p;
    p = head->next;
    int i;
    i = 0;
    while(p) {
        p = p->next;
        i++;
    }
    return i;
}


