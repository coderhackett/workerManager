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
	std::cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->get_dept_name()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << std::endl;
}

std::string manager::get_dept_name()
{
	return std::string("����");
}
