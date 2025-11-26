#include<stdio.h>
int main(){  
	float x,y;
	scanf("%f", &x);
	if (x < 0 && x != -3) {
		y = x *x + x - 6;
	} else if (x >= 0 && x < 10 && x != 2 && x != 3) {
		y = x * x - 5 * x + 6;
	} else {
		y = x * x - x - 1;
	}
	printf("%.3f\n",y);
	
	return 0;
}
