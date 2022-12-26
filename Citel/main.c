#include<stdio.h>
#include<math.h>
void ComputePI(){
	double sum = 0;
	int count = 1;
	double pi = 0;
	while(fabs(pi-3.14159265)>0.00001){
		sum += 1.0/(double)(count*count);
		count ++;
		pi = sqrt(6*sum);
	}
	printf("%.10lf\n",sum);
	printf("%.10lf\n",pi);
	printf("%d\n",count-1);
}
int main(void){
	ComputePI();
	return 0;
}