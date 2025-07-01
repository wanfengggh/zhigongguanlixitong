#include"workerManger.h"
#include<fstream>
#define Filename "save.txt"


workerManger::workerManger() {

	ifstream ifs;
	//1���ļ����������
	ifs.open(Filename, ios::in);
	if (!ifs.is_open())//bool���ͣ��ж��ļ��Ƿ�򿪳ɹ�
	{
		/*����
		cout << "�ļ�������" << endl;*/


		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڵ�û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ����ڲ��Ҽ�¼���ݣ�
	int num = this->getEmpnum();
	/*���Դ���
	cout << "ְ������Ϊ��" << num << endl;*/
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//����������m_EmpArray���飬������Ϊ�գ�
	// �ļ������ݵ��ǣ����γ��������У�����û���ļ��е����ݣ�
	// ������Ҫ����Ա����ʼ�������ļ��е������Ƶ�������
	// �Ա�֤���γ������к����ļ���ԭ������
	this->init();
	/*���Դ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "��� " << this->m_EmpArray[i]->m_Id
			<< " ���� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�� " << this->m_EmpArray[i]->m_DeptId << endl;

	}*/

}
void workerManger::init() {
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	Worker *worker = NULL;
	int index=0;
	while (ifs >> id && ifs >> name&& ifs>>dId) {
		
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker =new Manger(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
	return;
}
int workerManger::getEmpnum() {

	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//ͳ������
	}
	ifs.close();
	return num;


}
void workerManger::show_menu() {
	cout << "��ӭʹ��ְ��ϵͳ" << endl;
	cout << "0.�˳�ְ��ϵͳ" << endl;
	cout << "1.����ְ����Ϣ" << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << "3.ɾ����ְְ��" << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << "6.���ձ������" << endl;
	cout << "7.��������ĵ�" << endl << endl;
}
void workerManger::exit_system() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


void workerManger::Add_Emp() {
	cout << "����������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	

	if (addNum>0)
	{
		int Newsize;
		Newsize = this->m_EmpNum + addNum;//�����¿ռ��С
		Worker** newSpace = new Worker * [Newsize];//�����¿ռ�
			if (this->m_EmpArray!=NULL) {
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}//��ԭ�ռ������ݴ�ŵ��¿ռ���
			for (int i = 0; i < addNum; i++)
			{
				int id;
				string name;
				int dSelect;

				cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
				cin>> id;
				cout << "�������" << i + 1 << "����ְ��������" << endl;
				cin >> name;
				cout << "��ѡ���ְ����λ" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dSelect;
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id,name,1);
					break;
				case 2:
					worker = new Manger(id,name,2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
				newSpace[this->m_EmpNum + i] = worker;
				
			}
			delete[]this->m_EmpArray;//�ͷ�ԭ�пռ�
			this->m_EmpArray = newSpace;//�����¿ռ�ָ��
			this->m_EmpNum = Newsize;//�����µ�ְ������
			this->m_FileIsEmpty = false;//�ļ���Ϊ��
			cout << "�ɹ������" << addNum << "��ְ��" << endl;
			this->save();
			
	}


	else 
	{
		cout << "������������" << endl;
	
	}
	system("pause");
	system("cls");
}

void workerManger::save() {
	ofstream ofs;
	
	ofs.open("save.txt", ios::out);
	
		for (int i = 0; i < this->m_EmpNum; i++) {
			ofs << this->m_EmpArray[i]->m_Id << " "
				<< this->m_EmpArray[i]->m_Name << " "
				<< this->m_EmpArray[i]->m_DeptId << endl;
		}
	
	
	ofs.close();
}

void workerManger::show_Emp() {
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();

		}


	}
	system("pause");
	system("cls");
}

int workerManger::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void workerManger::del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	else 
	{
		cout << "������ɾ��Ա�����:" << endl;
		int id;
		cin >> id;
		int rec = this->IsExist(id);
		if (rec != -1)
		{
		//Ա������,ɾ������Ԫ�أ�����������ǰ��,forѭ��
			for (int i = rec; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
		}
		system("pause");
		system("cls");
	}
}
void workerManger::Mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		int mid=0;
		cout << "���������޸�Ա����ţ�" << endl;
		cin >> mid;
		int rec = this->IsExist(mid);
		if (rec != -1)//Ա������
		{
			delete this->m_EmpArray[rec];
			
			int newid=0, newdSelect=0;
			string newname="";
			cout << "���ҵ�" << mid << "��Ա��,������Ա���±�ţ�" << endl;
			cin >> newid;
			cout << "��������������" << endl;
			cin >> newname;
			cout << "�������λ��" << endl;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newdSelect;
			Worker* worker = NULL;
			switch (newdSelect)
			{
			case 1:
				worker=new Employee(newid,newname,1);
				break;
			case 2:
				worker = new Manger(newid, newname, 2);
				break;
			case 3:
				worker=new Boss(newid,newname,3);
				break;
			default:
				break;
			}
			this->m_EmpArray[rec] = worker;//��������
			cout << "�޸ĳɹ�" << endl;
			this->save();



		}
		else//Ա��������
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManger::Find_Emp() {

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

	}
	else
	{
		cout << "��ѡ����ҷ�ʽ" << endl
			<< "1������Ա����Ų���" << endl
			<< "2��������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int fid;
			cout << "������Ա�����" << endl;
			cin >> fid;
			int rec = this->IsExist(fid);
			if (rec != -1)
			{
				cout << "�ɹ���ѯ�����Ϊ" << fid << "��Ա����Ϣ�����£�" << endl;
				this->m_EmpArray[rec]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if (select == 2) {

			string fname;
			cout << "������Ա������" << endl;
			cin >> fname;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == fname)
				{
					cout << "�ɹ���ѯ������Ϊ" << fname << "��Ա������Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag = false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
			cout << "����ѡ������" << endl;

	}
	system("pause");
	system("cls");
}

void workerManger::Sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "����������ʽ��" << endl
			<< "1������" << endl
			<< "2������" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;

			}

		}

		cout << "������ɣ��������Ϊ��" << endl;
		this->save();
		this->show_Emp();

	}



}


void workerManger::Clean_File() {

	cout << "ȷ����գ�" << endl
		<< "1��ȷ��" << endl
		<< "2������" << endl;
	int select = 0;
	cin >> select;
	if (select==1) {
		ofstream ofs(Filename, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
	
		cout << "����ɹ���" << endl;
	
	}
	system("pause");
	system("cls");

}
workerManger::~workerManger() {
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}