#pragma once

#include <iostream>
#include <string>

class worker
{
public:

	virtual void show_info() = 0;	//��ʾ������Ϣ	
	virtual std::string get_dept_name() = 0; //��ȡ��λ��Ϣ

	int m_id;
	std::string m_name;
	int m_deptid;

private:

};
