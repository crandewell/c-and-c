#include<stdio.h>
int main()
{
	int a=1,b=1,temp,i;
	printf("%12d%12d",a,b);
	
	for(i=3;i<=40;i+=2){
		temp=a+b;
		printf("%12d",temp);
		
		a=b;
		b=temp;
		
		temp=a+b;
		printf("%12d\n",temp);
		
		a=b;
		b=temp;
	}
return 0;
}

