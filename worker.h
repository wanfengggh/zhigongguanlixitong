#pragma once
#include<iostream>
#include<string>
using namespace std;


class Worker {

public:
	virtual void showInfo() = 0;//展示个人信息
	virtual string getDeptName() = 0;//岗位名称


	int m_Id;
	string m_Name;
	int m_DeptId;


};