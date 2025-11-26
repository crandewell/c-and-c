#include<stdio.h>

void sum(int begin,int end)
{
	int i;
	int sum =0;
	for(i=begin;i<=end;i++)
	{
		sum+=i;
	}
	printf("%d到%d之间的和为%d\n",begin,end,sum);

}
int main()
{
	sum(20,45);
	sum(60,80);
	sum(13,91);
	return 0;
}
				 




	

