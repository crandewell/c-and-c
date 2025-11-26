#include<stdio.h>
int main()
{
	const double rate=8.25;
	const int low=40;
	double pay=0;
	int hours;
	printf("请输入你的工作小时数");
	scanf("%d",&hours);
	
	if (hours>low)
	pay=low*rate+(hours-low)*rate;
	else
	pay=hours*rate;
	
	printf("应发您%f元\n",pay);
	printf("hard working");
	
	
	return 0;
	
	
}
