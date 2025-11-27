/*#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	printf("请输入一个不小于3的正整数\n");
	scanf("%d",&n);
	if(n<3)
	{
		printf("请输入不小于3的正整数\n");
		return 1;
	}

	int isprime=1;
	
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			isprime=0;
			break;
		}
	}
	
	if(isprime){
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
}


#include<stdio.h>
int main()
{
	int num=0;
	int sum=0;
	
	printf("请输入一个正整数\n");
	scanf("%d",&num);
	
	if(num<=0)
	{
		printf("请输入正整数\n");
		return 1;
	}
	int temp=num;
	
	while(temp>0)
	{
		sum+=temp%10;
		temp/=10;
	}
	printf("数字%d的各位数字的累加和为：%d\n",num,sum);
	return 0;
}

#include<stdio.h>
int main()
{
	printf("1000以内的完数有：\n");
	
	for(int num = 2; num <= 1000; num++)
	{
		int sum = 1;  // 1是所有数的因子
		int factors[100];
		int count = 1;
		factors[0] = 1;  // 第一个因子是1
		
		// 找出所有因子
		for(int i = 2; i * i <= num; i++)
		{
			if(num % i == 0)
			{
				sum += i;  // 修正：应该是 sum += i，不是 sum += sum/i
				factors[count++] = i;
				
				if(i != num / i)  // 避免重复添加平方根
				{
					sum += num / i;
					factors[count++] = num / i;
				}
			}
		}
		
		// 如果是完数，输出结果
		if(sum == num)
		{
			// 对因子进行排序
			for(int i = 0; i < count - 1; i++)
			{
				for(int j = 0; j < count - 1 - i; j++)
				{
					if(factors[j] > factors[j + 1])
					{
						int temp = factors[j];
						factors[j] = factors[j + 1];
						factors[j + 1] = temp;
					}
				}
			}
			
			// 输出完数及其因子
			printf("%d its factors are ", num);
			for(int i = 0; i < count; i++)
			{
				if(i == 0) {
					printf("%d", factors[i]);
				} else {
					printf(",%d", factors[i]);
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}*/



