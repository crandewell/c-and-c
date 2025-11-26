#include<stdio.h>
int main()
{
	int x;
	for(x=2;x<100;x++){		int i;	int ok=1;
									for(i=2;i<x;i++){
									if (x%i==0){
										ok=0;
				break;
									}
									if (ok==1){
										printf("  %d",x);
									}
								}
								
							}
	
	printf("%d\n",x);

	return 0;
}
