#include<stdio.h>
int main()
{
	const int young=35;
	
	int age=0;
	
	printf("请输入你的年龄：");
	scanf("%d",&age);
	
	if(age>young){
		printf("珍惜以后的年岁吧.\n");
	}
	else{(printf("年轻正是当时.\n")); 
	}
	
	printf("年龄决定你的精神世界。\n");
	
	return 0; 
}
