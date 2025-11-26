#include<stdio.h>
int main()
{
	int x;//设起始时候的桃子数为x
	int i=9;
	int Last=1;
	while(i>0){
		Last=(Last+1)*2;//前一天的桃子数加一之和乘上2
		i--;
	}//中间的赋值可能有问题，且循环应该为9次才对
	printf("第一天桃子的总数为%d",Last);
	return 0;
}
