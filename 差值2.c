#include<stdio.h>
int main()
{
	int price=0;
	int bill=0;
	printf("请输入金额:"); 
	scanf("%d",&price);
	printf("请输入票面:");
	scanf("%d",&bill);
//计算金额差
	
	
	if(bill>=price){
		printf("应找您%d元\n",bill-price);
	}
	else{
		printf("抱歉，您不足以支付\n");
	}
	return 0;
	
}
