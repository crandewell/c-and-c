#include <stdio.h>

int main(){
	
	/********* Begin *********/
	int sum[10];
	int i=0;
	int j=0;
	int k=0;
	
// 输入10个整数
	for(i=0;i<10;i++){
		scanf("%d",&sum[i]);  // 添加了取地址符 &
	}
	
	int max=sum[0];  // 初始化为第一个元素
	int min=sum[0];  // 初始化为第一个元素
	int max_index=0; // 最大值下标
	int min_index=0; // 最小值下标
	
// 查找最大值和最小值
	for(j=1;j<10;j++)  // 从第二个元素开始比较
	{
		if(sum[j]>max)
		{
			max=sum[j];
			max_index=j;
		}
	} 
	
	for(k=1;k<10;k++)  // 从第二个元素开始比较
	{
		if(sum[k]<min)
		{
			min=sum[k];
			min_index=k;
		}
	}
	
	printf("最大值：%d\n",max);        // 修正：输出max而不是sum[i]
	printf("最大值下标：%d\n",max_index); // 修正：输出max_index而不是j
	printf("最小值：%d\n",min);        // 修正：输出min
	printf("最小值下标：%d\n",min_index); // 修正：输出min_index而不是k
	
	/********* End *********/
}
//要初始最值为数组中的数
//输出下标时候应该首先要考虑到有一个变量用于输出
