#include<stdio.h>
#include<stdlib.h>
int main(){
	long int number1,number2;
	long int count = 0;
	long int ans[10000000];
	for(int i = 0;i<10000000;i++)
		ans[i] = 0;
	while((scanf("%ld %ld",&number1,&number2))==2){
		long total = number1+number2;
		ans[count] = total;
		count++;
	}
	for (int i = 0; i < count-1; i++) {
		printf("%ld\n",ans[i]);
		printf("\n");
	}
	printf("%ld\n",ans[count-1]);
    system("pause");
    return 0;
}
