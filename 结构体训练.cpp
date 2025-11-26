#include<iostream>
#include<string>
using namespace std;
struct Hero
{
	string name;
	int age;
	string sex;
};
//打印排序后的数组中的信息
void printHero(struct Hero heroArray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "姓名： " << heroArray[i].name << " 年龄：" << heroArray[i].age
		<< "性别：" << heroArray[i].sex << endl;
	}
}
//实现冒泡排序的函数
void bubblesort(struct Hero heroArray[],int len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			//如果j下标的元素年龄大于j+1元素年龄则交换
			if (heroArray[j].age > heroArray[j + 1].age) {
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}
int main()
{
	struct Hero heroArray[5] =
	{
		{"liubei",23,"nan"},
		{"guanyu",22,"nan"},
		{"zhangfei",20,"nan"},
		{"zhaoyun",21,"nan"},
		{"diaochan",19,"nv"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	
	bubblesort(heroArray, len);
	printHero(heroArray,len);
	system("pause");
	return 0;
}
