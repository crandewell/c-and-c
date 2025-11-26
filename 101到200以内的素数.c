#include<stdio.h>
int main()
{
	int i,j;
	int cnt=0;
	
	for(i=101;i<=200;i++){
		for(j=2;j<i;j++){
			if(i%j==0)
				break;//意为跳出了j=2的这个循环，到了外面的一层for循环
			//如果满足的话那么内层循环会一直执行下去
			
		}
		//实际上是相等，因为会一直执行到最后让这俩值相等
		if(j>=i){
			cnt++;
			printf("%d ",i);
			//计数器利用cnt除的原理
			if(cnt%5==0)
				printf("\n");	
		}
	}
	
	return 0;
}
