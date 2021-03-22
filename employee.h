#pragma once
#include <iostream>
#include "worker.h"

class employee : public worker
{
public:
	employee(int id , std::string name , int d_id);
	~employee();

	virtual void show_info();	//显示个人信息
	virtual std::string get_dept_name();	//获取职工岗位名称

private:

};

