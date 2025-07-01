#pragma once
#include<iostream>
#include"worker.h"
#include"Manger.h"
#include"Boss.h"
#include"Employee.h"
using namespace std;


class workerManger {
public:
	workerManger();

	void show_menu();//菜单页
	void exit_system();//关闭系统
	void Add_Emp();//添加
	void save();//保存
	bool m_FileIsEmpty;//判断文件是否为空
	int getEmpnum();//统计人数
	void show_Emp();//显示功能
	void del_Emp();//删除
	int IsExist(int id);//判断员工是否存在
	void Mod_Emp();//修改员工
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
	~workerManger();
	int m_EmpNum;
	void init();//初始化员工数组
	Worker** m_EmpArray;


	
};

