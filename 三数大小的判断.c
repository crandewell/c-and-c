#include<stdio.h>
int main()
{
	printf("请输入三个整数\n");
	int x,y,z;
	int t;
	scanf("%d %d %d",&x,&y,&z);
	//实则xyz三次互相比较即可得出结果
	
	if(x>y){
		t=x,x=y,y=t;//x,y互换了值
	}
	if(x>z){
		t=x,x=z,z=t;//x,z互换了值
	}
	if(y>z){
		t=y,y=z,z=t;//y,z互换了值
	}
	printf("三个整数从小到大排列的顺序为%d %d %d",x,y,z);
    //从if中的条件来看x其实是那个最大的数但是由于互换，实际上最终倒序了
	return 0;
	
}
