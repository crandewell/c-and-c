#include <stdio.h>
#include <math.h>
//题目 4
int main() {
	int sign = 1;      
	double intial = 1.0;  
	double term;       
	double pi = 0.0;   
	
	do {
		term = sign /intial ;    
		pi += term;                  
		sign = -sign;                
		intial += 2;           
	} while (fabs(term) >= 1e-6);     
	
	pi *= 4;  
	
	printf("π的近似值为：%.6f\n", pi);
	
	
	return 0;
}
