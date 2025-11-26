#include<stdio.h>
int main()
{
	int a,b,c;
	int max=0;
	
	printf("请输入a,b,c的取值");
	scanf("%d %d %d",&a,&b,&c);
	
	if(a>b){
		if(a>c){
			max=a;
		}else{
			max=c;
		}
	
	}else{
		if(b>c){
			max=b;
		}else{
			max=c;
		}
	}
	printf("最大值为%d\n",max);
	
	return 0;
}

