#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"

/*测试代码*/
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
	workerManager wm;	//实例化对象
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		std::cout << "input your choice:" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exit_system();	//退出系统
		break;
		case 1:
			wm.add_employee();	//添加员工
		break; 
		case 2:
			wm.show_emp();		//显示职工
		break; 
		case 3:
			wm.del_emp();		//删除职工
		break; 
		case 4:
			wm.mod_emp();		//修改职工
		break; 
		case 5:
			wm.find_emp();		//查找职工
		break; 
		case 6:
			wm.sort_emp();		//排序职工
		break; 
		case 7:
			wm.clear_file();	//清空文件
		break; 
		default:
			system("cls");
		break;
		}
	}

	system("pause");
	return 0;
}