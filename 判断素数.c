#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	int i;
	int ok = 1;
	for(i=2;i<x;i++){
		if(x%i==0){
			ok=0;
			break;
		}
		
	}
	if (ok==1){
		printf("是素数\n");
	}else{
		printf("不是素数\n");
	} 
	return 0;
}
