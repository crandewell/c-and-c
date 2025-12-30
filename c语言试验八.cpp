#include <stdio.h>
#include <math.h>
/*定义点的结构体：包含x、y坐标*/
/********* Begin *********/
typedef struct Point
{
	double x;
	double y;
} Point;
/********* End *********/

void inputPoint(Point *p1,Point *p2);       /*输入点的坐标*/ 
Point getMidPoint(Point p1, Point p2);    /* 计算两个点的中点*/
double getDistance(Point p1, Point p2);   /* 计算两点间距离*/


int main(){
	Point p1, p2, midPoint;  /*定义两个点和中点*/
	double distance;         /*两点间距离*/
	
	/*调用函数，输入两个点的坐标*/
	/********* Begin *********/
	inputPoint(&p1,&p2);
	/********* End *********/
	
	/*调用函数，计算并输出中点坐标*/
	/********* Begin *********/
	midPoint = getMidPoint(p1,p2);
	/********* End *********/
	
	/*调用函数，计算并输出两点间距离*/
	/********* Begin *********/
	distance = getDistance(p1,p2);
	printf("中点坐标：(%.2lf, %.2lf)\n",midPoint.x,midPoint.y);
	printf("两点间距离：%.2lf\n",distance);
	/********* End *********/   
} 

void inputPoint(Point *p1,Point *p2) {
	/********* Begin *********/
	scanf("%lf,%lf",&(p1->x),&(p1->y));
	scanf("%lf,%lf",&(p2->x),&(p2->y));
	/********* End *********/    
}


Point getMidPoint(Point p1, Point p2) {
	/********* Begin *********/
	Point mid;
	mid.x = (p1.x + p2.x) / 2.0;
	mid.y = (p1.y + p2.y) / 2.0;  // 修正：应该是p1.y + p2.y
	return mid;
	/********* End *********/    
}


double getDistance(Point p1, Point p2) {
	/********* Begin *********/
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	return sqrt(dx*dx + dy*dy);
	/********* End *********/    
}
