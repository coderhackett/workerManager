#pragma once
#include <iostream>
#include "worker.h"

class manager : public worker
{
public:
	manager(int id , std::string name , int d_id);
	~manager();

	virtual void show_info();	//��ʾ������Ϣ
	virtual std::string get_dept_name();	//��ȡְ����λ��Ϣ

private:

};


