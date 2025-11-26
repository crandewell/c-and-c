//输出三位数水仙花数
//难点在于对三位数做一个拆解
#include<stdio.h>
int main()
{
	int x,y,z,i;
	int sum=0;
	for(i=100;i<=999;i++){
		x=i%10;
		//学习分解的方法
		y=(i/10)%10;
		z=(i/100)%10;
		//对三位数单独做了分解
		if (i==x*x*x+y*y*y+z*z*z){
			printf("%d  ",i);
		}
	}
	return 0;
	
}
