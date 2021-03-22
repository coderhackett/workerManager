#include "workerManager.h"
#include <fstream>

workerManager::workerManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		std::cout << "file don't exist!" << std::endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//文件存在但是没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "file is empty!" << std::endl;

		this->m_EmpArray = nullptr;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	int num = this->get_emp_num();
	//std::cout << "worker num = " << num << std::endl; //test code
	this->m_EmpNum = num;

	//根据职工数创建数组
	this->m_EmpArray = new worker * [this->m_EmpNum];
	init_emp();

	//测试代码
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		std::cout << "职工号： " << this->m_EmpArray[i]->m_id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_name
			<< " 部门编号： " << this->m_EmpArray[i]->m_deptid << std::endl;
	}*/
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != nullptr)
		delete[] this->m_EmpArray;
}


void workerManager::show_menu()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  欢迎使用职工管理系统！ **********" << std::endl;
	std::cout << "*************  0.退出管理程序  *************" << std::endl;
	std::cout << "*************  1.增加职工信息  *************" << std::endl;
	std::cout << "*************  2.显示职工信息  *************" << std::endl;
	std::cout << "*************  3.删除离职职工  *************" << std::endl;
	std::cout << "*************  4.修改职工信息  *************" << std::endl;
	std::cout << "*************  5.查找职工信息  *************" << std::endl;
	std::cout << "*************  6.按照编号排序  *************" << std::endl;
	std::cout << "*************  7.清空所有文档  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}

void workerManager::exit_system()
{
	std::cout << "good bye , see you next time" << std::endl;
	system("pause");
	exit(0);
}

void workerManager::add_employee()
{
	std::cout << "input add worker num: " << std::endl;
	int addNum = 0;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//重新计算空间大小
		int newSize = this->m_EmpNum + addNum;
		
		//开辟新空间
		worker** newSpace = new worker*[newSize];

		//将原空间的内容放到新空间下
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}
		for (int i = 0; i < addNum; i++)
		{
			int id,dSelect;
			std::string name;
			
			std::cout << "please input " << i + 1 << " new worker num " << std::endl;
			std::cin >> id;

			std::cout << "please input " << i + 1 << " new worker name " << std::endl;
			std::cin >> name;

			std::cout << "please select worker type: " << std::endl;
			std::cout << "1:employee " << std::endl;
			std::cout << "2:manager " << std::endl;
			std::cout << "3:boss " << std::endl;
			std::cin >> dSelect;

			worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id , name , 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间
		delete[] this->m_EmpArray;
		
		//更新新空间的指向
		this->m_EmpArray = newSpace;
		
		//更新新的个数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示信息
		std::cout << "add success" << addNum << "new worker" << std::endl;

		//保存新增的数据到文件
		this->save();
	}
	else
	{
		std::cout << "input num error! " << std::endl;
	}
	system("pause");
	system("cls");
}

void workerManager::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptid << std::endl;
	}
	ofs.close();
}

int workerManager::get_emp_num()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;
	
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;	//记录人数
	}
	ifs.close();
	return num;
}

void workerManager::init_emp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* worker = nullptr;
		//根据不同的部门ID创建不同对象
		switch (dId)
		{
		case 1:
			worker = new employee(id, name, dId);
			break;
		case 2:
			worker = new manager(id, name, dId);
			break;
		case 3:
			worker = new boss(id, name, dId);
		default:
			break;
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void workerManager::show_emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "file don't exist or empty" << std::endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->show_info();
		}
	}
	system("pause");
	system("cls");

}

void workerManager::del_emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "file don't exist or empty" << std::endl;
	}
	else
	{
		std::cout << "please input del worker num: " << std::endl;
		int id = 0;
		std::cin >> id;

		int index = this->is_exist(id);
		if (index != -1)	//说明index上位置的数据需要删除
		{
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();	//删除后需要同步写入文件
			std::cout << "del success! " << std::endl;
		}
		else
		{
			std::cout << "del failed! " << std::endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::mod_emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "file don't exist or empty" << std::endl;
	}
	else
	{
		std::cout << "please input modify worker num: " << std::endl;
		int id = 0;
		std::cin >> id;

		int ret = this->is_exist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			std::string newName = "";
			int dSelect = 0;

			std::cout << "search:    " << id << " worker num ,please input new worker num:" << std::endl;
			std::cin >> id;

			std::cout << "please input new worker name : " << std::endl;
			std::cin >> newName;

			std::cout << "please select worker type: " << std::endl;
			std::cout << "1:employee " << std::endl;
			std::cout << "2:manager " << std::endl;
			std::cout << "3:boss " << std::endl;
			std::cin >> dSelect;

			worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			std::cout << "modify success !" << std::endl;

			this->save();	//修改后更新到文件中
		}
		else
		{
			std::cout << "modify failed  no this worker!" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::find_emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "file don't exist or empty" << std::endl;
	}
	else
	{
		std::cout << "please input find type: " << std::endl;
		std::cout << "1:find in num " << std::endl;
		std::cout << "2:find in name " << std::endl;
		int select = 0;
		std::cin >> select;

		if (select == 1)
		{
			int id;
			std::cout << "please input find num " << std::endl;
			std::cin >> id;
			
			int ret = is_exist(id);
			if (ret != -1)
			{
				std::cout << "find success , the worker info: " << std::endl;
				this->m_EmpArray[ret]->show_info();
			}
			else
			{
				std::cout << "find failed  no this worker!" << std::endl;
			}
		}
		else if(select == 2)
		{ 
			std::string name;
			std::cout << "please input find name : " << std::endl;
			std::cin >> name;

			bool flag = false;	//查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					std::cout << "find success , the worker info: " << std::endl;
					this->m_EmpArray[i]->show_info();
					flag = true;
				}
			}
			if (flag == false)
			{
				std::cout << "find failed  no this worker!" << std::endl;
			}
		}
		else
		{
			std::cout << "input value error !" << std::endl;
		}
		system("pause");
		system("cls");
	}
}

void workerManager::sort_emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "file don't exist or empty" << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "please input sort type: " << std::endl;
		std::cout << "1:sort in num up" << std::endl;
		std::cout << "2:sort in num down" << std::endl;
		int select = 0;
		std::cin >> select;
		
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)
				{
					if (m_EmpArray[minOrMax]->m_id < m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					std::cout << "sort type num error !" << std::endl;
				}
			}
			if (i != minOrMax)
			{
				worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		std::cout << "sort success ! sort result: " << std::endl;

		this->save();	//保存更新
		this->show_emp();

	}
}

void workerManager::clear_file()
{
	std::cout << "are you sure clear ? " << std::endl;
	std::cout << "1:sure " << std::endl;
	std::cout << "2:return " << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		//打开模式：ios::trunc 如果存在删除文件并重新创建
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != nullptr)
					delete this->m_EmpArray[i];
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = nullptr;
			this->m_FileIsEmpty = true;
		}
		std::cout << "clear success ! " << std::endl;
	}
	system("pause");
	system("cls");
}

int workerManager::is_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

