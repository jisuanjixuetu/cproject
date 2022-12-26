#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct hashTable{
	int key;
	char value[10];
}hashTable;
hashTable table1[11];
hashTable table2[11];
int Hash(int key){
	return key%11;
}

int Keys(char *s){
	return ((int)s[0]*2+(int)s[1]*3+(int)s[2]*4);
}
void dataStore(int n){
	printf("please enter %d data.\n",n);
	for (int i = 0; i < n; i++) {
		printf("please enter value of the %d data\n",i+1);
		scanf("%s",table1[i].value);
		int key = Keys(table1[i].value);
		table1[i].key = key;
	}
}

void setHash(int n){
	int i,j;
	for (i = 0; i < 11; i++) {
		table2[i].key = -1;
	}
	for(i = 0;i<n;i++){
		j = Hash(table1[i].key);
		while (table2[j].key!=-1)
			j = (j+1)%11;
		table2[j].key = table1[i].key;
		strcpy(table2[j].value,table1[i].value);
	}
}
void Show()
{
	int i;
	printf("\n          ****************hashTable**************\n");
	printf("key:       *****");
	for(i=0;i<11;i++)
		printf("%6d",table2[i].key);
	printf("\n");
	printf("value:       *****");
	for(i=0;i<11;i++)
		printf("%6s",table2[i].value);
	printf("\n");
	printf("address:     *****");
	for(i=0;i<11;i++)
		printf("%6d",i);
	printf("\n");
}
int search(int key){
	int i;
	i = Hash(key);
	while (table2[i].key!=-1&&table2[i].key!=key){
		i = (i+1)%11;
	}
	if (table2[i].key == -1) {
		return -1;
}
	else {
	    return i;
	}
}
int main() {
	hashTable *hashTable1;
	int key;
	int number;
	char *value;
	value = (char *) malloc(sizeof (char )*10);
	printf("please enter the number(1-11) of the keys\n");
	scanf("%d",&number);
	dataStore(number);
	setHash(number);
	Show();
	printf("please enter what you want to search\n");
	while(scanf("%s",value)==1) {
		key = Keys(value);
		if (search(key) == -1) {
			printf("404 not found\n");
		} else {
			printf("success,location is %d,the value is %s\n", search(key),
				   table2[search(key)].value);
		}
	}
	return 0;
}
