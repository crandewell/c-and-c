#include<stdio.h>
int main()
{
	int i;
	int sum=0;
	for(i=1;i<=10;i++){
		sum+=i;
	}
	printf("%d和%d之间数的总和为%d\n",1,10,sum);
	for(i=20;i<=30;i++){
		sum+=i;
	}
	printf("%d和%d之间数的总和为%d\n",20,30,sum);
	for(i=35;i<=45;i++){
		sum+=i;
	}
	printf("%d和%d之间数的总和为%d\n",35,45,sum);
	
	
	return 0;
}
