#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"

/*���Դ���*/
/*void test()
{
	worker* worker = new employee(1 , "zhang san" , 1);
	worker->show_info();
	delete worker;

	worker = new manager(2 , "li si" , 2);
	worker->show_info();
	delete worker;

	worker = new boss(3 , "wang wu" , 3);
	worker->show_info();
	delete worker;

}*/

int main(int argc , char ** argv)
{
	workerManager wm;	//ʵ��������
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		std::cout << "input your choice:" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exit_system();	//�˳�ϵͳ
		break;
		case 1:
			wm.add_employee();	//���Ա��
		break; 
		case 2:
			wm.show_emp();		//��ʾְ��
		break; 
		case 3:
			wm.del_emp();		//ɾ��ְ��
		break; 
		case 4:
			wm.mod_emp();		//�޸�ְ��
		break; 
		case 5:
			wm.find_emp();		//����ְ��
		break; 
		case 6:
			wm.sort_emp();		//����ְ��
		break; 
		case 7:
			wm.clear_file();	//����ļ�
		break; 
		default:
			system("cls");
		break;
		}
	}

	system("pause");
	return 0;
}