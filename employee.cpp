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
	std::cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->get_dept_name()
		<< " \t��λְ����ɾ�����������" << std::endl;
}

std::string employee::get_dept_name()
{
	return std::string("Ա��");
}
