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
		cout << "����������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();//�˳�
			break;
		case 1://���
			wm.Add_Emp();
			break;
		case 2://��ʾ
			wm.show_Emp();
			break;
		case 3://ɾ��
			wm.del_Emp();
			break;
		case 4://�޸�
			wm.Mod_Emp();
			break;
		case 5://����
			wm.Find_Emp();
			break;
		case 6://����
			wm.Sort_Emp();
			break;
		case 7://���
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