#include<stdio.h>
int main()
{
	int n;
	
	scanf("%d",&n);
	
	int i=1;
	
	int fact=1;
	
	while (i <= n) {
		fact *=i;
		i++;
	}
	printf("%d!=%d\n",n,fact);
	
	return 0;
}
