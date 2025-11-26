#include<stdio.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=*temp;
}
int main()
{
	int a,b,c;
	printf("请输入三个数字\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		swap(*a,*b);
	}
	if(a>c){
		swap(*a,*c);
	}
	if(b>c){
		swap(*b,*c);
	}
	printf("从小到大三个数的顺序为:",a,b,c);
}
