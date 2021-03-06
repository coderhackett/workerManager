#include "manager.h"

manager::manager(int id, std::string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = d_id;
}

manager::~manager()
{
}

void manager::show_info()
{
	std::cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->get_dept_name()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << std::endl;
}

std::string manager::get_dept_name()
{
	return std::string("经理");
}
