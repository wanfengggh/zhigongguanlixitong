#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int B_id, string B_name, int dId);

	virtual void showInfo();
	virtual string getDeptName();
};