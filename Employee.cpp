#include"Employee.h"


Employee::Employee(int id,string name,int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Employee::showInfo() {
	cout << "Ա�����:" << this->m_Id
		<< "\tԱ������:" << this->m_Name
		<< "\tԱ�����ű��:" << this->m_DeptId 
		<<"\t��λְ����ɾ����·�������" << endl;
}
string Employee::getDeptName() {

	return string("Ա��");
}