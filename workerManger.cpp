#include"workerManger.h"
#include<fstream>
#define Filename "save.txt"


workerManger::workerManger() {

	ifstream ifs;
	//1、文件不存在情况
	ifs.open(Filename, ios::in);
	if (!ifs.is_open())//bool类型，判断文件是否打开成功
	{
		/*测试
		cout << "文件不存在" << endl;*/


		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在并且记录数据；
	int num = this->getEmpnum();
	/*测试代码
	cout << "职工人数为：" << num << endl;*/
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//堆区创建了m_EmpArray数组，但数据为空，
	// 文件有数据但是（本次程序运行中）堆区没有文件中的数据，
	// 所以需要进行员工初始化，将文件中的数据移到堆区，
	// 以保证本次程序运行涵盖文件中原有数据
	this->init();
	/*测试代码
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号 " << this->m_EmpArray[i]->m_Id
			<< " 姓名 " << this->m_EmpArray[i]->m_Name
			<< " 部门编号 " << this->m_EmpArray[i]->m_DeptId << endl;

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
		num++;//统计人数
	}
	ifs.close();
	return num;


}
void workerManger::show_menu() {
	cout << "欢迎使用职工系统" << endl;
	cout << "0.退出职工系统" << endl;
	cout << "1.增加职工信息" << endl;
	cout << "2.显示职工信息" << endl;
	cout << "3.删除离职职工" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
	cout << "6.按照编号排序" << endl;
	cout << "7.清空所有文档" << endl << endl;
}
void workerManger::exit_system() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


void workerManger::Add_Emp() {
	cout << "请输入增加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	

	if (addNum>0)
	{
		int Newsize;
		Newsize = this->m_EmpNum + addNum;//计算新空间大小
		Worker** newSpace = new Worker * [Newsize];//开辟新空间
			if (this->m_EmpArray!=NULL) {
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}//将原空间下内容存放到新空间下
			for (int i = 0; i < addNum; i++)
			{
				int id;
				string name;
				int dSelect;

				cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
				cin>> id;
				cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
				cin >> name;
				cout << "请选择该职工岗位" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
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
			delete[]this->m_EmpArray;//释放原有空间
			this->m_EmpArray = newSpace;//更新新空间指向
			this->m_EmpNum = Newsize;//更新新的职工人数
			this->m_FileIsEmpty = false;//文件不为空
			cout << "成功添加了" << addNum << "个职工" << endl;
			this->save();
			
	}


	else 
	{
		cout << "输入数据有误" << endl;
	
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
		cout << "文件不存在或文件为空" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}

	else 
	{
		cout << "请输入删除员工编号:" << endl;
		int id;
		cin >> id;
		int rec = this->IsExist(id);
		if (rec != -1)
		{
		//员工存在,删除数组元素，本质是数据前移,for循环
			for (int i = rec; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "删除失败，未找到该员工" << endl;
		}
		system("pause");
		system("cls");
	}
}
void workerManger::Mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		int mid=0;
		cout << "请输入所修改员工编号：" << endl;
		cin >> mid;
		int rec = this->IsExist(mid);
		if (rec != -1)//员工存在
		{
			delete this->m_EmpArray[rec];
			
			int newid=0, newdSelect=0;
			string newname="";
			cout << "查找到" << mid << "号员工,请输入员工新编号：" << endl;
			cin >> newid;
			cout << "请输入新姓名：" << endl;
			cin >> newname;
			cout << "请输入岗位：" << endl;
			cout << "请选择该职工岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			this->m_EmpArray[rec] = worker;//更新数据
			cout << "修改成功" << endl;
			this->save();



		}
		else//员工不存在
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManger::Find_Emp() {

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

	}
	else
	{
		cout << "请选择查找方式" << endl
			<< "1、按照员工编号查找" << endl
			<< "2、按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int fid;
			cout << "请输入员工编号" << endl;
			cin >> fid;
			int rec = this->IsExist(fid);
			if (rec != -1)
			{
				cout << "成功查询到编号为" << fid << "的员工信息，如下：" << endl;
				this->m_EmpArray[rec]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else if (select == 2) {

			string fname;
			cout << "请输入员工姓名" << endl;
			cin >> fname;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == fname)
				{
					cout << "成功查询到姓名为" << fname << "的员工，信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag = false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
			cout << "输入选项有误" << endl;

	}
	system("pause");
	system("cls");
}

void workerManger::Sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "请输入排序方式：" << endl
			<< "1、升序" << endl
			<< "2、降序" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
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

		cout << "排序完成，排序后结果为：" << endl;
		this->save();
		this->show_Emp();

	}



}


void workerManger::Clean_File() {

	cout << "确认清空？" << endl
		<< "1、确认" << endl
		<< "2、返回" << endl;
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
	
		cout << "清除成功！" << endl;
	
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