#include <stdio.h>

int main(){
	int a[6]={1,4,8,14,23},i; 
	
	/********* Begin *********/
	int num;
	scanf("%d", &num);
	
// 从后向前比较并移动
	for(i = 4; i >= 0; i--) {//此处内部是int i还是i是不一样的
		if(num < a[i]) {
			a[i+1] = a[i];  // 向后移动
		} else {
			break;  // 找到插入位置
		}
	}
	a[i+1] = num;  // 插入新元素
	
// 输出结果
	for(i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	/********* End *********/
}
//关于插入的实现
