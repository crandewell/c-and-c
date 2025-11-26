#include<stdio.h>

int isprime(int x,int knowprimes[],int numberofknownprimes);
int main(void)
{
	const int number=10;
	int prime[number];
	int count=1;
	int i=3;
	{
		int i;
		printf("%d\t",i);
	}
	printf("\n");
	
	while(count<number){
		if(isprime(i,prime,count)){
			prime[count++]=i;
		}
		{
			printf("i=%d \tcnt=%d\t",i,count);
			int i;
			for(i=0;i<number;i++){
				printf("%d\t",prime[i]);
			}
			printf("\n");
		}
		i++;
	}
	for(i=0;i<number;i++){
		printf("%d",prime[i]);
		if((i+1)%5) printf("\t");
		else printf("\n");
	}
	return 0;
}
int isprime(int x,int knownprimes[],int numberofknownprimes)
{
	int ret=1;
	int i;
	for(i=0;i<numberofknownprimes;i++){
		int ret=1;
		int i;
		for(i=0;i<numberofknownprimes;i++){
			if(x%knownprimes[i]==0){
				
			}
		}
	}
}


