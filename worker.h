#pragma once
#include<iostream>
#include<string>
using namespace std;


class Worker {

public:
	virtual void showInfo() = 0;//չʾ������Ϣ
	virtual string getDeptName() = 0;//��λ����


	int m_Id;
	string m_Name;
	int m_DeptId;


};