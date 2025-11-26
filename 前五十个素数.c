#include<stdio.h>
int main()
{
	int x;
	x=2;
	int cnt=0;
	
	while (cnt<50)
	{
		int i;
		int ok = 1;
		for(i=2;i<x;i++){
			if(x%i==0){
				ok = 0;
				break;
			}
		}
	if (ok==1){
		printf("   %d",x);
		cnt++;
	}x++;
	}
	printf("\n");
	
	return 0;
	
}
