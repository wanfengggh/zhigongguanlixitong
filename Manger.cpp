#include"Manger.h"

Manger::Manger(int M_id,string M_name ,int dId) {

	this->m_Id = M_id;
	this->m_Name = M_name;
	this->m_DeptId = dId;
}
void Manger::showInfo() {
	cout << "Ա�����:" << this->m_Id
		<< "\tԱ������:" << this->m_Name
		<< "\tԱ�����ű��:" << this->m_DeptId
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա��" << endl;

}

string Manger::getDeptName() {
	return string("����");
}
