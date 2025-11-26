/*#include<stdio.h>
int main()
{
	int sum=0;
	int cnt=0;
	int a;
	int hig=0;
	printf("请输入数值与项数\n");
	scanf("%d %d",&a,&cnt);
	
	while(cnt>0){
		sum+=a;
		a*=10;
		hig+=sum;
		cnt--;
	}
	printf("计算的结果为%d\n",hig);
	return 0;
}	
*/
//通过递归来实现
#include<stdio.h>

int c_term(int count,int base);
int main()
{
	int count;//项数
	int base;//初始数字
	int sum=0;//end
	
	printf("请输入一个初始的值\n");
	scanf("%d",&base);
	printf("请输入一个指定项数\n");
	scanf("%d",&count);
	//检验符合要求性
	if(count<=0||base<=0){
		printf("输入的初始值和项数必须为正整数");
		return 1;//返回错误状态
	}
	//循环累加
	for(int i=1;i<=count;i++){
		sum+=c_term(i,base);
	}
	printf("最终的结果为%d\n",sum);
}	
	int c_term(int count,int base){
		if(count==1){
			//如果count是1那么我们不需要进一步计算了，返回base值即可
			return base;
		}else{
			return c_term(count-1,base)*10+base;
		}
	}


