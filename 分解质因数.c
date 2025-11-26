//分解质因数
#include<stdio.h>
int main()
{
	int a;
	int i;
	printf("请输入一个正整数\n");
	scanf("%d=",&a);
	//如何输出乘号是关键
	for(i=2;i<=a;i++){
		while(a%i==0){
			printf("%d",i);
			a/=i;
			if(a!=1){
				printf("*");
			}
		}
	}
}
