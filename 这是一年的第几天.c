#include<stdio.h>
int Ryear(int year){
	if((year%4==0&&year%100==0)||(year%400!=0)){
		return 1;
	}else return 0;
}
int main(){
	
	int daysmonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int day,month,year;
	int totaldays=0;
	int totaldaysMonth=0;
	int i;
	printf("请输入(年)(月)(日)\n");
	scanf("%d %d %d",&year,&month,&day);
	if(Ryear){
		daysmonth[1]=29;	
	}
	//此处i=0就错了，因为数组从0下标开始数
	//由于月份一共就十二，month-1 -2注意出错
	for(i=0;i<=month-2;i++){
		totaldaysMonth+=daysmonth[i];
	}
	totaldaysMonth+=day;
	
	printf("%d年%d月%d日是今年的第%d天\n",year,month,day,totaldaysMonth);
	
	return 0;
	
	
		
}




