#include "boss.h"

boss::boss(int id, std::string name, int d_id)
{
	this->m_id = id; 
	this->m_name = name;
	this->m_deptid = d_id;
}

void boss::show_info()
{
	std::cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->get_dept_name()
		<< " \t��λְ�𣺹���˾��������" << std::endl;
}

std::string boss::get_dept_name()
{
	return std::string("�ϰ�");
}
