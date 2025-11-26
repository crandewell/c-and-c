#include<stdio.h>
int main()
{
	int grade;
	scanf("%d",&grade);
	if(grade>=90){
		printf("A");
	}else if(grade>60&&grade<=89){
		printf("B");
	}else if(grade<=60){
		printf("C");
	}
	return 0;
}
