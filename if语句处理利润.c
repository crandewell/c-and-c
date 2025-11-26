#include<stdio.h>
#define w 10000

int main()
{
	double i=0;//profit
	double b=0;//bonus
	
	printf("请输入月利润为（元）\n");
	scanf("%lf",&i);
	i/=w;//保证下面没有太多0
	
	//利用if语句进行运算
	if(i>100*w){
		b+=(i-100)*0.01;
		i=100;
	}
	if(i>60*w){
		b+=(i-60)*0.015;
		i=60;
	}
	if(i>40*w){
		b+=(i-40)*0.03;
		i=40;
	}
	if(i>20){
		b+=(i-20)*0.05;
		i=20;
	}
	if(i>10){
		b+=(i-10)*0.1;
		i=10;
	}
	b+=(i*0.1);
	printf("你所得的奖金为%lf\n",b);
	
	return 0;
}
