//哥德巴赫猜想的验证代码

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int limit;
	
	printf("请输入要验证的最大偶数：");
	scanf("%d", &limit);
	
	printf("\n验证哥德巴赫猜想（6到%d）：\n", limit);
	
	int allVerified = 1;
	
	for (int num = 6; num <= limit; num += 2) {
		int found = 0;
		
		for (int i = 2; i <= num / 2; i++) {
			if (isPrime(i) && isPrime(num - i)) {
				found = 1;
				break;
			}
		}
		
		if (!found) {
			printf("%d - 验证失败！\n", num);
			allVerified = 0;
			break;
		}
	}
	
	if (allVerified) {
		printf("\n 在%d范围内，哥德巴赫猜想成立！\n", limit);
	} else {
		printf("\n 在%d范围内，哥德巴赫猜想不成立！\n", limit);
	}
	
	// 显示一些示例
	printf("\n示例：\n");
	int examples[] = {100, 500, 1000};
	for (int i = 0; i < 3; i++) {
		for (int j = 2; j <= examples[i] / 2; j++) {
			if (isPrime(j) && isPrime(examples[i] - j)) {
				printf("%d = %d + %d\n", examples[i], j, examples[i] - j);
				break;
			}
		}
	}
	
	return 0;
}
