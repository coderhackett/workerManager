#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();
	~workerManager();

	//��ʾ�˵�
	void show_menu();

	//�˳�ϵͳ
	void exit_system();

	//����Ա��
	void add_employee();

	//���ݱ������ļ�
	void save();

	//ͳ������
	int get_emp_num();

	//��ʼ��Ա��
	void init_emp();

	//��ʾְ��
	void show_emp();

	//ɾ��ְ��
	void del_emp();

	//�޸�ְ��
	void mod_emp();

	//����ְ��
	void find_emp();

	//����ְ��
	void sort_emp();

	//����ļ�
	void clear_file();

	//�ж�ְ������Ƿ���� ���ڷ��������λ�� �����ڷ���-1
	int is_exist(int id);

private:
	int m_EmpNum;	//��¼�ļ��е���������
	worker** m_EmpArray;	//Ա�������ָ��
	bool m_FileIsEmpty;	//����ļ��Ƿ�Ϊ��
};
