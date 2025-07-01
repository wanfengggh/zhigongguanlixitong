#include"Boss.h"

Boss::Boss(int B_id, string B_name, int dId) {
	this->m_Id = B_id;
	this->m_Name = B_name;
	this->m_DeptId = dId;
}
void Boss::showInfo() {
	cout << "员工编号:" << this->m_Id
		<< "\t员工姓名:" << this->m_Name
		<< "\t员工部门编号:" << this->m_DeptId
		<< "\t岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptName() {

	return string("总裁");
}