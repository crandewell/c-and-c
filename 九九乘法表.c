#include<stdio.h>
int main()
{
	//注意两个换行符号的位置
	
	int i;
	int j;
	for(i=1;i<=9;i++){
		for(j=1;j<=i;j++){
			//内层不要换行了，不然堆不起来，完成一次循环则下一步
			printf("%d*%d=%-3d",i,j,i*j);
		}
	printf("\n");
	}

	return 0;
}
