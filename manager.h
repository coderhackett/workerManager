#pragma once
#include <iostream>
#include "worker.h"

class manager : public worker
{
public:
	manager(int id , std::string name , int d_id);
	~manager();

	virtual void show_info();	//显示个人信息
	virtual std::string get_dept_name();	//获取职工岗位信息

private:

};


