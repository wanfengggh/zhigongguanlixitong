#include<iostream>
#include<fstream>
#include"workerManger.h"
#include"Employee.h"
#include"Manger.h"
#include"Boss.h"
using namespace std;





int main() {
	workerManger wm;
	
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "请输入您的选择：";
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();//退出
			break;
		case 1://添加
			wm.Add_Emp();
			break;
		case 2://显示
			wm.show_Emp();
			break;
		case 3://删除
			wm.del_Emp();
			break;
		case 4://修改
			wm.Mod_Emp();
			break;
		case 5://查找
			wm.Find_Emp();
			break;
		case 6://排序
			wm.Sort_Emp();
			break;
		case 7://清空
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