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

	void show_menu();//�˵�ҳ
	void exit_system();//�ر�ϵͳ
	void Add_Emp();//���
	void save();//����
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��
	int getEmpnum();//ͳ������
	void show_Emp();//��ʾ����
	void del_Emp();//ɾ��
	int IsExist(int id);//�ж�Ա���Ƿ����
	void Mod_Emp();//�޸�Ա��
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
	~workerManger();
	int m_EmpNum;
	void init();//��ʼ��Ա������
	Worker** m_EmpArray;


	
};

