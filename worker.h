#pragma once

#include <iostream>
#include <string>

class worker
{
public:

	virtual void show_info() = 0;	//显示个人信息	
	virtual std::string get_dept_name() = 0; //获取岗位信息

	int m_id;
	std::string m_name;
	int m_deptid;

private:

};
