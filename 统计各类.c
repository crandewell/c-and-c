#include<stdio.h>
int main()
{
	char c;
	int lettercount=0;
	int spacecount=0;
	int digitcount=0;
	int othercount=0;
	
	printf("请输入一些字符:\n");
	//每次循环都从c中读取一个字符，getchar本身是一个标准函数
	while((c=getchar())!='\n'){
		if((c>='a'&&c<='z')||(c>'A'&&c<'Z')){
			lettercount++;
		}else if(c>='0'&&c<='9'){
			digitcount++;
		}else if(c==' '){
			spacecount++;
		}else othercount++;
	}
	printf("字母=%d,数字=%d,空格=%d,其他=%d\n",lettercount,digitcount,spacecount,othercount);
	
	return 0;
}
