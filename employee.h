#pragma once
#include <iostream>
#include "worker.h"

class employee : public worker
{
public:
	employee(int id , std::string name , int d_id);
	~employee();

	virtual void show_info();	//��ʾ������Ϣ
	virtual std::string get_dept_name();	//��ȡְ����λ����

private:

};

