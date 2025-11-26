#include<stdio.h>

int max(int a,int b)
{
	int ret;
	if(a>b)
	return a;
	else
	return b;
//不好说单一出口，用return传递	
}

int main()
{
	int a=6;
	int b=8;
	int c;
	c=max(10,12);
	c=max(a,b);
	c=max(c,23);
	printf("%d\n",max(a,b));
	
	return 0;
}
