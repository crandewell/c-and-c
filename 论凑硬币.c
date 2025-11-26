#include<stdio.h>
int main()
{
	int x;
	int one,two,five;
	
	scanf("%d",&x);
	for (one=1;one<x*10;one++){
		for(two=2;two<x*5;two++){
			for(five=5;five<x*2;five++){
				if(one+two*2+five*5==x*10){
					printf("可以用%d个1角，%d个2角，%d个5角凑成%d元\n",one,two,five,x);
					goto out;
				}
			}
		}
	}
	out:
	return 0;
}
