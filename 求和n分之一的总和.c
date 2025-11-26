#include<stdio.h>
int main ()
{
	int n;
	int i;
	double sum = 0.0;
	//求出n分之一的和f(n)过程 
	scanf("%d",&n);
	for ( i=1;i<=n;i++ ){
		sum+= 1.0/i;
	}
	printf("f(%d)=%f\n",n,sum);
	return 0;
}
