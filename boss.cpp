#include "boss.h"

boss::boss(int id, std::string name, int d_id)
{
	this->m_id = id; 
	this->m_name = name;
	this->m_deptid = d_id;
}

void boss::show_info()
{
	std::cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->get_dept_name()
		<< " \t岗位职责：管理公司所有事务" << std::endl;
}

std::string boss::get_dept_name()
{
	return std::string("老板");
}
