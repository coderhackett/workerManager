#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();
	~workerManager();

	//显示菜单
	void show_menu();

	//退出系统
	void exit_system();

	//增加员工
	void add_employee();

	//数据保存入文件
	void save();

	//统计人数
	int get_emp_num();

	//初始化员工
	void init_emp();

	//显示职工
	void show_emp();

	//删除职工
	void del_emp();

	//修改职工
	void mod_emp();

	//查找职工
	void find_emp();

	//排序职工
	void sort_emp();

	//清空文件
	void clear_file();

	//判断职工编号是否存在 存在返回数组的位置 不存在返回-1
	int is_exist(int id);

private:
	int m_EmpNum;	//记录文件中的人数个数
	worker** m_EmpArray;	//员工数组的指针
	bool m_FileIsEmpty;	//标记文件是否为空
};
