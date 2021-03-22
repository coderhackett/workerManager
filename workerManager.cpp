#include "workerManager.h"
#include <fstream>

workerManager::workerManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		std::cout << "file don't exist!" << std::endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//�ļ����ڵ���û�м�¼
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

	//����ְ������������
	this->m_EmpArray = new worker * [this->m_EmpNum];
	init_emp();

	//���Դ���
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		std::cout << "ְ���ţ� " << this->m_EmpArray[i]->m_id
			<< " ְ�������� " << this->m_EmpArray[i]->m_name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_deptid << std::endl;
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
	std::cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << std::endl;
	std::cout << "*************  0.�˳��������  *************" << std::endl;
	std::cout << "*************  1.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  2.��ʾְ����Ϣ  *************" << std::endl;
	std::cout << "*************  3.ɾ����ְְ��  *************" << std::endl;
	std::cout << "*************  4.�޸�ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  5.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  6.���ձ������  *************" << std::endl;
	std::cout << "*************  7.��������ĵ�  *************" << std::endl;
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
		//���¼���ռ��С
		int newSize = this->m_EmpNum + addNum;
		
		//�����¿ռ�
		worker** newSpace = new worker*[newSize];

		//��ԭ�ռ�����ݷŵ��¿ռ���
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
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		
		//�����µĸ���
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		std::cout << "add success" << addNum << "new worker" << std::endl;

		//�������������ݵ��ļ�
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
		num++;	//��¼����
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
		//���ݲ�ͬ�Ĳ���ID������ͬ����
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
		//�����������
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
			//���ö�̬���ýӿ�
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
		if (index != -1)	//˵��index��λ�õ�������Ҫɾ��
		{
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();	//ɾ������Ҫͬ��д���ļ�
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
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			std::cout << "modify success !" << std::endl;

			this->save();	//�޸ĺ���µ��ļ���
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

			bool flag = false;	//���ҵ��ı�־
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

		this->save();	//�������
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
		//��ģʽ��ios::trunc �������ɾ���ļ������´���
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

