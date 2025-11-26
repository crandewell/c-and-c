#include<stdio.h>
int main()
{
	srand(time(0));
	int number =rand()%100+1;
	int count =0;
	int a=0;
	
	printf("我已经想好了一个两位数");
	do{
		printf("请猜猜这个数是谁：");
		scanf("%d",&a);
		count++;
		if(a>number){
			printf("你猜到的数大了");
		}else if(a<number){
			printf("你猜到的数小了");
			
		}
	}
	while (a!=number);
	printf("man you are right。用了%d次就猜到了答案\n");
	
	return 0;
}
