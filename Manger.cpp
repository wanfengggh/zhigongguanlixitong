#include"Manger.h"

Manger::Manger(int M_id,string M_name ,int dId) {

	this->m_Id = M_id;
	this->m_Name = M_name;
	this->m_DeptId = dId;
}
void Manger::showInfo() {
	cout << "员工编号:" << this->m_Id
		<< "\t员工姓名:" << this->m_Name
		<< "\t员工部门编号:" << this->m_DeptId
		<< "\t岗位职责：完成老板交给的任务，并下发给员工" << endl;

}

string Manger::getDeptName() {
	return string("经理");
}
