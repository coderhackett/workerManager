#include "employee.h"


employee::employee(int id, std::string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = d_id;
}

employee::~employee()
{
}

void employee::show_info()
{
	std::cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->get_dept_name()
		<< " \t岗位职责：完成经理交给的任务" << std::endl;
}

std::string employee::get_dept_name()
{
	return std::string("员工");
}
