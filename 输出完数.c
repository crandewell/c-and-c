//输出完数
#include<stdio.h>
int main()
{
	int i,j,sum;
	printf("1000以内的完数有:\n");
	
	for(i=1;i<=1000;i++){
		sum=0;//每次循环前重置sum为0
		for(j=1;j<i;j++){
			//找出真因子进行计算
			if(i%j==0){
				sum+=j;
			}
		}
	//如果真因子之和为i本身则其是完数	
	//下面就是为了拼一个算式罢了
	if(sum==i){
		printf("%d=1",i);
	for(j=2;j<i;j++){
		if(i%j==0){
			printf("+%d",j);
		}
	}
		printf("\n");
}
}
	return 0;
}




