#pragma once
#include <iostream>
#include "worker.h"

class boss : public worker
{
public:
	boss(int id , std::string name , int d_id);
	~boss();

	virtual void show_info();	//��ʾ������Ϣ
	virtual std::string get_dept_name();	//��ȡְ����λ��Ϣ

private:

};
