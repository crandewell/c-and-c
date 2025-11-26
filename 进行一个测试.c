#include<stdio.h>
int main()
{
	int i=3;
	int j=5; 
	int a[i][j];
	for(i=0;i<3;i++){
		for(j=0;j<5;j++)
		a[i][j]=i*j;
		printf("%d %d\n",i,j);
	}
	
	return 0;
}
