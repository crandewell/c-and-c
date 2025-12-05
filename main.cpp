#include<iostream>
using namespace std;
#include"WorkerManager.h"

int main()
{
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		 case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}