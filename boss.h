#pragma once
#include <iostream>
#include "worker.h"

class boss : public worker
{
public:
	boss(int id , std::string name , int d_id);
	~boss();

	virtual void show_info();	//显示个人信息
	virtual std::string get_dept_name();	//获取职工岗位信息

private:

};
