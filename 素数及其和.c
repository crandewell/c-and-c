#include<stdio.h>
int main()
{
	int m,n;
	int i;
	int cnt=0;
	int sum=0;
	printf("素数计算机byLMF in 2025.10.19制作\n"); 
	printf("输入两个非相等的整数进行操作\n");
	scanf("%d %d",&m,&n);
	if(m==1)
	m=2;
	
	for (i=m;i<=n;i++){
		int isprime =1;
	    int k;
		
		for(k=2;k<i-1;k++){
		if(i%k==0){
			isprime=0;
			break;
		}
	}
	if (isprime==1){
		cnt++;
		sum+=i;
	}
}
	printf("其间素数的个数为%d,其总和为%d \n",cnt,sum); 
	return 0;
}
