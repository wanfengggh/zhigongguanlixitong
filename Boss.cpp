#include"Boss.h"

Boss::Boss(int B_id, string B_name, int dId) {
	this->m_Id = B_id;
	this->m_Name = B_name;
	this->m_DeptId = dId;
}
void Boss::showInfo() {
	cout << "Ա�����:" << this->m_Id
		<< "\tԱ������:" << this->m_Name
		<< "\tԱ�����ű��:" << this->m_DeptId
		<< "\t��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName() {

	return string("�ܲ�");
}