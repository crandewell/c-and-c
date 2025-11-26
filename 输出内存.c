#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	void *p;
	int cnt = 0;
	whlie( (p = malloc(100 * 1024 * 1024)) ){
		cnt++;
	}
	printf("%d00MB\n", cnt);

	return 0;
}
