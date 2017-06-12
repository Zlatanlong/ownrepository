#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include"List_Teacher.h"
#include"List_Student.h"
#include"List_Ader.h"
using namespace std;
string menu()
{
	cout << "|*---------------���˵�-----------------*|" << endl;
	cout << "|*--------1.���ļ��ж�ȡ��Ա����--------*|" << endl;
	cout << "|*--------2.¼���³�Ա------------------*|" << endl;
	cout << "|*--------3.��ָ��λ��¼���³�Ա--------*|" << endl;
	cout << "|*--------4.�������г�Ա���ļ�----------*|" << endl;
	cout << "|*--------5.���������Ա----------------*|" << endl;
	cout << "|*--------6.������Ա����----------------*|" << endl;
	cout << "|*--------7.ɾ����Ա--------------------*|" << endl;
	cout << "|*--------8.ѡ�����򷽷�----------------*|" << endl;
	cout << "|*--------9.ѡ�����ݲ�������------------*|" << endl;
	cout << "|*--------10.����Ų���-----------------*|" << endl;
	cout << "|*--------11.�����Ա����---------------*|" << endl;
	cout << "|*--------0.�˳�ϵͳ--------------------*|" << endl;
	cout << "     �����룺" ;
	string order = "null";
	cin >> order;
	cout << endl;
	return order;
}

string choose()
{
	string order_de1 = "null";
	cout << "��ѡ����Ա���ͣ�" << endl;
	cout << "1.��ʦ" << endl;
	cout << "2.ѧ��" << endl;
	cout << "3.������Ա" << endl;
	cin >> order_de1;
	cout << endl;
	return order_de1;
}

void error_input()
{ cout <<endl<< "---!!!��ʾ����������ȷ������!!!---" << endl<<endl; }


void create_teacher(List_Teacher *pList_teacher)
{
	Node_teacher node_teacher;
	Teacher teacher1;
	cout << "���������ʦ��������";
	cin >> teacher1.name;
	cout << "���������ʦ�ı�ţ�";
	cin >> teacher1.num;
	cout << "���������ʦ���Ա�";
	cin >> teacher1.sex;
	cout << "���������ʦ�����䣺";
	cin >> teacher1.ege;
	cout << "���������ʦ�Ŀ�Ŀ��";
	cin >> teacher1.subject;
	cout << "���������ʦ����н��";
	cin >> teacher1.salary;
	cout << "���������ʦ�Ĺ�������";
	cin >> teacher1.workload;
	node_teacher.data = teacher1;
	pList_teacher->ListInsertTail(&node_teacher);
	cout << "----------------------��ʦ¼�����-----------------------"<<endl<<endl;
}

void create_student(List_Student *pList_student)
{
	Node_student node_student;
	Student student1;
	cout << "�������ѧ����������";
	cin >> student1.name;
	cout << "�������ѧ���ı�ţ�";
	cin >> student1.num;
	cout << "�������ѧ�����Ա�";
	cin >> student1.sex;
	cout << "�������ѧ�������䣺";
	cin >> student1.ege;
	cout << "�������ѧ��C++�ĳɼ���";
	cin >> student1.score1;
	cout << "�������ѧ��Java�ĳɼ���";
	cin >> student1.score2;
	cout << "������ѧ�����»�����";
	cin >> student1.expense;
	node_student.data = student1;
	pList_student->ListInsertTail(&node_student);
	cout << "----------------------ѧ��¼�����-----------------------" <<endl<< endl;
}

void create_ader(List_Ader *pList_ader)
{
	Node_ader node_ader;
	Ader ader1;
	cout << "������ù�����Ա��������";
	cin >> ader1.name;
	cout << "������ù�����Ա�ı�ţ�";
	cin >> ader1.num;
	cout << "������ù�����Ա���Ա�";
	cin >> ader1.sex;
	cout << "������ù�����Ա�����䣺";
	cin >> ader1.ege;
	cout << "������ù�����Ա�Ĳ��ţ�";
	cin >> ader1.department;
	cout << "������ù�����Ա����н��";
	cin >> ader1.salary;
	cout << "������ù�����Ա�Ĺ�������";
	cin >> ader1.workload;
	node_ader.data = ader1;
	pList_ader->ListInsertTail(&node_ader);
	cout << "----------------------������Ա¼�����-----------------------" <<endl<< endl;
}


void create_teacher_at(List_Teacher *pList_teacher)
{
	Node_teacher node_teacher;
	Teacher teacher1;
	int i;
	cout << "���������λ�ã���������������";
	cin >>i;
	if (i > pList_teacher->ListLength())
	{
		cout << "��������ȷ��λ��" <<endl<< endl;
		return;
	}
	else 
	{
		cout << "���������ʦ��������";
		cin >> teacher1.name;
		cout << "���������ʦ�ı�ţ�";
		cin >> teacher1.num;
		cout << "���������ʦ���Ա�";
		cin >> teacher1.sex;
		cout << "���������ʦ�����䣺";
		cin >> teacher1.ege;
		cout << "���������ʦ�Ŀ�Ŀ��";
		cin >> teacher1.subject;
		cout << "���������ʦ����н��";
		cin >> teacher1.salary;
		cout << "���������ʦ�Ĺ�������";
		cin >> teacher1.workload;
		node_teacher.data = teacher1;
		pList_teacher->ListInsert(i - 1, &node_teacher);
		cout << "----------------------��ʦ�������--------------------------" << endl<<endl;
	}
}

void create_student_at(List_Student *pList_student)
{
	Node_student node_student;
	Student student1;
	int i;
	cout << "���������λ�ã���������������";
	cin >> i;
	if (i > pList_student->ListLength())
	{
		cout << "��������ȷ��λ��" << endl << endl;
		return;
	}
	else
	{
		cout << "�������ѧ����������";
		cin >> student1.name;
		cout << "�������ѧ���ı�ţ�";
		cin >> student1.num;
		cout << "�������ѧ�����Ա�";
		cin >> student1.sex;
		cout << "�������ѧ�������䣺";
		cin >> student1.ege;
		cout << "�������ѧ��C++�ĳɼ���";
		cin >> student1.score1;
		cout << "�������ѧ��Java�ĳɼ���";
		cin >> student1.score2;
		cout << "������ѧ�����»�����";
		cin >> student1.expense;
		node_student.data = student1;
		pList_student->ListInsert(i - 1, &node_student);
		cout << "----------------------ѧ���������--------------------------" <<endl<< endl;
	}
}

void create_ader_at(List_Ader *pList_ader)
{
	Node_ader node_ader;
	Ader ader1;
	int i;
	cout << "���������λ�ã���������������";
	cin >> i;
	if (i > pList_ader->ListLength())
	{
		cout << "��������ȷ��λ��" << endl << endl;
		return;
	}
	else
	{
		cout << "������ù�����Ա��������";
		cin >> ader1.name;
		cout << "������ù�����Ա�ı�ţ�";
		cin >> ader1.num;
		cout << "������ù�����Ա���Ա�";
		cin >> ader1.sex;
		cout << "������ù�����Ա�����䣺";
		cin >> ader1.ege;
		cout << "������ù�����Ա�Ĳ��ţ�";
		cin >> ader1.department;
		cout << "������ù�����Ա����н��";
		cin >> ader1.salary;
		cout << "������ù�����Ա�Ĺ�������";
		cin >> ader1.workload;
		node_ader.data = ader1;
		pList_ader->ListInsert(i - 1, &node_ader);
		cout << "----------------------������Ա�������--------------------------" <<endl<<endl;
	}
}


void change_teacher(List_Teacher *pList_teacher)
{
	int i; string gettf = "null";
	Node_teacher node_teacher;
	cout << "��������ĵ���ţ�" << endl;
	cin >> i;
	pList_teacher->GetElem(i-1, &node_teacher);
	cout << "��ȷ���޸���Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
	node_teacher.printNode();
	cin >> gettf;
	if (gettf == "0")
	{
		return ;
	}
	else if (gettf=="1")
	{
		pList_teacher->ListDelete(i-1, &node_teacher);
		Teacher teacher1;
		cout << "���������ʦ��������";
		cin >> teacher1.name;
		cout << "���������ʦ�ı�ţ�";
		cin >> teacher1.num;
		cout << "���������ʦ���Ա�";
		cin >> teacher1.sex;
		cout << "���������ʦ�����䣺";
		cin >> teacher1.ege;
		cout << "���������ʦ�Ŀ�Ŀ��";
		cin >> teacher1.subject;
		cout << "���������ʦ����н��";
		cin >> teacher1.salary;
		cout << "���������ʦ�Ĺ�������";
		cin >> teacher1.workload;
		node_teacher.data = teacher1;
		pList_teacher->ListInsert(i-1, &node_teacher);
		cout <<endl<< "----------------------�޸����--------------------------" << endl << endl;
	}
	else
	{
		error_input();
	}
}

void change_student(List_Student *pList_student)
{
	int i; string gettf = "null";
	Node_student node_student;
	cout << "��������ĵ���ţ�" << endl;
	cin >> i;
	pList_student->GetElem(i-1, &node_student);
	cout << "��ȷ���޸���Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
	node_student.printNode();
	cin >> gettf;
	if (gettf == "0")
	{
		return;
	}
	else if (gettf == "1")
	{
		pList_student->ListDelete(i-1, &node_student);
		Student student1;
		cout << "�������ѧ����������";
		cin >> student1.name;
		cout << "�������ѧ���ı�ţ�";
		cin >> student1.num;
		cout << "�������ѧ�����Ա�";
		cin >> student1.sex;
		cout << "�������ѧ�������䣺";
		cin >> student1.ege;
		cout << "�������ѧ��C++�ĳɼ���";
		cin >> student1.score1;
		cout << "�������ѧ��Java�ĳɼ���";
		cin >> student1.score2;
		cout << "������ѧ�����»�����";
		cin >> student1.expense;
		node_student.data = student1;
		pList_student->ListInsert(i-1, &node_student);
		cout << endl << "----------------------�޸����--------------------------" << endl << endl;
	}
	else
	{
		error_input();
	}
}

void change_ader(List_Ader *pList_ader)
{
	int i; string gettf = "null";
	Node_ader node_ader;
	cout << "��������ĵ���ţ�" << endl;
	cin >> i;
	pList_ader->GetElem(i-1, &node_ader);
	cout << "��ȷ���޸���Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
	node_ader.printNode();
	cin >> gettf;
	if (gettf == "0")
	{
		return;
	}
	else if (gettf == "1")
	{
		pList_ader->ListDelete(i, &node_ader);
		Ader ader1;
		cout << "���������λ�ã���������������";
		cin >> i;
		cout << "������ù�����Ա��������";
		cin >> ader1.name;
		cout << "������ù�����Ա�ı�ţ�";
		cin >> ader1.num;
		cout << "������ù�����Ա���Ա�";
		cin >> ader1.sex;
		cout << "������ù�����Ա�����䣺";
		cin >> ader1.ege;
		cout << "������ù�����Ա�Ĳ��ţ�";
		cin >> ader1.department;
		cout << "������ù�����Ա����н��";
		cin >> ader1.salary;
		cout << "������ù�����Ա�Ĺ�������";
		cin >> ader1.workload;
		node_ader.data = ader1;
		pList_ader->ListInsert(i, &node_ader);
		cout << endl << "----------------------�޸����--------------------------" << endl << endl;
	}
	else
	{
		error_input();
	}
}


void delete_at_teacher(List_Teacher *pList_teacher)
{
	bool tf;
	int i; string gettf = "null";
	Node_teacher  node_teacher;
	cout << "��������Ҫɾ����Ա����ţ�" << endl;
	cin >> i;
	tf=pList_teacher->GetElem(i-1, &node_teacher);
	if (tf == true) {
		node_teacher.printNode();
		cout << "��ȷ����Ҫɾ����Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_teacher->ListDelete(i-1, &node_teacher);
			cout << "----------------------ɾ�����--------------------------" << endl;
		}
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
	}
}

void delete_at_student(List_Student *pList_student)
{
	int i; string gettf = "null"; bool tf;
	Node_student node_student;
	cout << "��������Ҫɾ����Ա����ţ�" << endl;
	cin >> i;
	tf = pList_student->GetElem(i-1, &node_student);
	if (tf == true) {
		node_student.printNode();
		cout << "��ȷ����Ҫɾ����Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_student->ListDelete(i-1, &node_student);
			cout << "----------------------ɾ�����--------------------------" << endl;
		}
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
	}
}

void delete_at_ader(List_Ader *pList_ader)
{
	bool tf;
	int i; string gettf = "null";
	Node_ader node_ader;
	cout << "��������Ҫɾ����Ա����ţ�" << endl;
	cin >> i;
	tf = pList_ader->GetElem(i-1, &node_ader);
	if (tf == true) {
		node_ader.printNode();
		cout << "��ȷ����Ҫɾ����Ա����Ϣ��ȷ�ϣ�1��������0����" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_ader->ListDelete(i-1, &node_ader);
			cout << "----------------------ɾ�����--------------------------" << endl;
		}
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
	}
}


double ave_salary_teacher(List_Teacher *pList_teacher)
{
	double ave=0,sum=0,i=0;
	Node_teacher*currentNode = pList_teacher->Gethead();
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		sum+=currentNode->data.salary;
		i++;
	}
	return sum / i;
}

double ave_c_student(List_Student*pList_student)
{
	double ave = 0, sum = 0, i = 0;
	Node_student*currentNode = pList_student->Gethead();
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		sum += currentNode->data.score1;
		i++;
	}
	return sum / i;
}


void find_Teacherbynum(List_Teacher *pList_teacher)
{
	bool tf;
	string n="null";
	cout << "��������ʦ��ţ�" << endl;
	cin >> n;
	Node_teacher node_teacher;
	tf=pList_teacher->ListFindbynum(n, &node_teacher);
	if (tf == true) {
		node_teacher.printNode();
		cout << endl << "----------�������----------" << endl << endl;
		return;
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
		return;
	}
}

void find_Studentbynum(List_Student *pList_student)
{
	bool tf;
	string n = "null";
	cout << "������ѧ����ţ�" << endl;
	cin >> n;
	Node_student node_student;
	pList_student->ListFindbynum(n, &node_student);
	if (tf == true) {
		node_student.printNode();
		cout << endl << "----------�������----------" << endl << endl;
		return;
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
		return;
	}
}

void find_Aderbynum(List_Ader *pList_ader)
{
	bool tf;
	string n = "null";
	cout << "�����������Ա��ţ�" << endl;
	cin >> n;
	Node_ader node_ader;
	pList_ader->ListFindbynum(n, &node_ader);
	if (tf == true) {
		node_ader.printNode();
		cout <<endl<< "----------�������----------" << endl<<endl;
		return;
	}
	else
	{
		cout << "û���ҵ�������ȷ�Ϻ����²���" << endl;
		return;
	}
}


void Teacher_Openfile(List_Teacher *pList_teacher)
{
	Node_teacher node_teacher;
	Teacher teacher1;
	ifstream fin("Teachers.txt", ios::in);
	if (!fin)
	{
		cout << "Cannot open output file.\n";
		return;
	}
	while (fin.peek()!=EOF)
	{
		fin >> teacher1.name;
		fin >> teacher1.num;
		fin >> teacher1.sex;
		fin >> teacher1.ege;
		fin >> teacher1.subject;
		fin >> teacher1.salary;
		fin >> teacher1.workload;
		node_teacher.data = teacher1;
		pList_teacher->ListInsertTail(&node_teacher);
		fin.get();
	}
	fin.close();
	cout << "---------------��ʦ���ݶ�ȡ���-------------------" << endl << endl;
}

void Student_Openfile(List_Student *pList_student)
{
	Node_student node_student;
	Student student1;
	ifstream fin("Students.txt", ios::in);
	if (!fin)
	{
		cout << "Cannot open output file.\n";
		return;
	}
	while (fin.peek() != EOF)
	{
		fin >> student1.name;
		fin >> student1.num;
		fin >> student1.sex;
		fin >> student1.ege;
		fin >> student1.score1;
		fin >> student1.score2;
		fin >> student1.expense;
		node_student.data = student1;
		pList_student->ListInsertTail(&node_student);
		fin.get();
	}
	fin.close();
	cout << "---------------ѧ�����ݶ�ȡ���-------------------" << endl << endl;
}

void Ader_Openfile(List_Ader *pList_ader)
{
	Node_ader node_ader;
	Ader ader1;
	ifstream fin("Aders.txt", ios::in);
	if (!fin)
	{
		cout << "Cannot open output file.\n";
		return;
	}
	while (fin.peek() != EOF)
	{
		fin >>ader1.name;
		fin >> ader1.num;
		fin >> ader1.sex;
		fin >> ader1.ege;
		fin >> ader1.department;
		fin >> ader1.salary;
		fin >> ader1.workload;
		node_ader.data = ader1;
		pList_ader->ListInsertTail(&node_ader);
		fin.get();
	}
	fin.close();
	cout << "---------------������Ա���ݶ�ȡ���-------------------" << endl << endl;
}





int main()
{
	string userOrder = "null";
	string order_choose = "null";
	string order_0 = "null";
	string tf_return = "null";
	List_Teacher *pList_teacher = new List_Teacher();
	List_Student *pList_student = new List_Student();
	List_Ader *pList_ader = new List_Ader();
	cout << "���ã���ӭ����:" << endl;
	cout << "          �й�ʯ�ʹ�ѧ����������Ա���������ϵͳPre-alpha1.0_5.12"<<endl ;
	cout<<"          ��ʹ�÷������������ֽ��빦��ѡ�"<<endl;
	cout << endl;
	while (userOrder != "00")
	{
		userOrder = menu();
		if (userOrder == "1")
		{
			cout << endl;
			cout << "����ѡ���ǣ�1.���ļ��ж�ȡ��Ա����" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				Teacher_Openfile(pList_teacher);
			}
			else if (order_choose == "2")
			{
				Student_Openfile(pList_student);
			}
			else if (order_choose == "3")
			{
				Ader_Openfile(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "2")
		{
			cout << endl;
			cout << "����ѡ���ǣ�2.¼���³�Ա" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				create_teacher(pList_teacher);
			}
			else if (order_choose == "2")
			{
				create_student(pList_student);
			}
			else if (order_choose == "3")
			{
				create_ader(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "3")
		{
			cout << endl;
			cout << "����ѡ���ǣ�3.��ָ��λ��¼���³�Ա" << endl;
			order_choose = choose();
		 if (order_choose == "1")
			{
				create_teacher_at(pList_teacher);
			}
		else if (order_choose == "2")
			{
				create_student_at(pList_student);
			}
		else if (order_choose == "3")
			{
				create_ader_at(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "4")
		{
			cout << endl;
			cout << "����ѡ���ǣ�4.�������г�Ա���ļ�" << endl;
			order_choose = choose();
		 if (order_choose == "1")
			{
			 remove("Teachers.txt");
				pList_teacher->ListTraverseinFile();
				cout << "--------������ɣ�--------" << endl<<endl;
			}
		else if (order_choose == "2")
			{
			remove("Students.txt");
				pList_student->ListTraverseinFile();
				cout << "--------������ɣ�--------" << endl << endl;
			}
			if (order_choose == "3")
			{
				remove("Aders.txt");
				pList_ader->ListTraverseinFile();
				cout << "--------������ɣ�--------" << endl << endl;
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "5")
		{
			cout << endl;
			cout << "����ѡ���ǣ�5.���������Ա" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				pList_teacher->ListTraverse();
			}
			else if (order_choose == "2")
			{
				pList_student->ListTraverse();
			}
			else if (order_choose == "3")
			{
				pList_ader->ListTraverse();
			}
			else
			{
				error_input();
			}
		}
		else if (userOrder == "6")
		{
			cout << endl;
			cout << "����ѡ���ǣ�6.������Ա����" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				change_teacher(pList_teacher);
			}
			else if (order_choose == "2")
			{
				change_student(pList_student);
			}
			else if (order_choose == "3")
			{
				change_ader(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "7")
		{
			cout << endl;
			cout << "����ѡ���ǣ�7.ɾ����Ա" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				delete_at_teacher(pList_teacher);
			}
			else if (order_choose == "2")
			{
				delete_at_student(pList_student);
			}
			else if (order_choose == "3")
			{
				delete_at_ader(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "8")
		{
			cout << endl;
			cout << "����ѡ���ǣ�8.ѡ�����򷽷�" << endl;
			cout << "��������ѡ��" << endl;
			string order_de8="null";
			cout << "1.�����������С����" << endl;
			cout << "2.��C++�ɼ���ѧ�������ɸ����ͣ�" << endl;
			cout << "3.��Java�ɼ���ѧ�������ɸ����ͣ�" << endl;
			cout << "0.������һ��˵�" << endl;
			cout << "���๦������ϵ����" << endl<<endl;
			cin >> order_de8;
			if (order_de8 == "1")
			{
				cout << "����ѡ���ǣ�1.�����������С����" << endl;
				order_choose = choose();
				if (order_choose == "1")
				{
					pList_teacher->ListRank_num();
					cout<< endl << "----------�������----------" << endl << endl;
				}
				if (order_choose == "2")
				{
					pList_student->ListRank_num();
					cout << endl << "----------�������----------" << endl << endl;
				}
				if (order_choose == "3")
				{
					pList_ader->ListRank_num();
					cout << endl << "----------�������----------" << endl << endl;
				}
				else
				{
					error_input();
				}
			}
			else if (order_de8=="2")
			{
				cout << "����ѡ���ǣ�2.��C++�ɼ���ѧ�������ɸ����ͣ�" << endl;
				pList_student->ListRank_c();
				cout << endl << "----------�������----------" << endl << endl;
			}
			else if (order_de8 == "3")
			{
				cout << "����ѡ���ǣ�3.��Java�ɼ���ѧ�������ɸ����ͣ�" << endl;
				pList_student->ListRank_j();
				cout <<endl<< "----------�������----------" << endl << endl;
			}
			else if (order_de8 == "0")
			{
				cout << "����ѡ���ǣ�0.������һ��˵�" << endl;
				continue;
			}
			else
			{
				error_input();
			}
		}
		else if (userOrder == "9")
		{
			cout << endl;
			cout << "����ѡ���ǣ�9.ѡ�����ݲ�������" << endl;
			cout << "��������ѡ��" << endl;
			string order_de9="null";
			cout << "1.ͳ�Ƹ�������Ա��" << endl;
			cout << "2.ͳ����ʦƽ������" << endl;
			cout << "3.ͳ��ѧ��C++ƽ���ɼ�" << endl;
			cout << "0.������һ��˵�" << endl;
			cout << "���๦������ϵ����" << endl<<endl;
			cin >> order_de9;
			if (order_de9 == "1")
			{
				cout << "����ѡ���ǣ�1.ͳ�Ƹ�������Ա��" << endl;
				cout << "��ʦ���������ǣ�"<<pList_teacher->ListLength()<<endl;
				cout << "ѧ�����������ǣ�"<<pList_student->ListLength()<<endl;
				cout << "������Ա���������ǣ�"<<pList_ader->ListLength()<<endl;
				cout << endl << endl;
			}
			else if (order_de9 == "2")
			{
				cout << "����ѡ���ǣ�2.ͳ����ʦƽ������" << endl;
				cout<<"��ʦ��ƽ�������ǣ�"<<ave_salary_teacher(pList_teacher)<<"Ԫ/��"<<endl;
				cout << endl << endl;
			}
			else if (order_de9 == "3")
			{
				cout << "����ѡ���ǣ�3.ͳ��ѧ��C++ƽ���ɼ�" << endl;
				cout << "ѧ��C++��ƽ���ɼ���" << ave_c_student(pList_student) << "��" << endl;
				cout << endl << endl;
			}
			else if (order_de9 == "0")
			{
				cout << "����ѡ���ǣ�0.������һ��˵�" << endl;
				continue;
			}
			else
			{
				error_input();
			}
		}
		else if (userOrder == "10")
		{
			cout << endl;
			cout << "����ѡ���ǣ�10.����Ų���" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				find_Teacherbynum(pList_teacher);
			}
			else if (order_choose == "2")
			{
				find_Studentbynum(pList_student);
			}
			else if (order_choose == "3")
			{
				find_Aderbynum(pList_ader);
			}
			else
			{
				error_input();
				continue;
			}
		}
		else if (userOrder == "11")
		{
			cout << endl;
			cout << "����ѡ���ǣ�11.�����Ա����" << endl;
			order_choose = choose();
			if (order_choose == "1")
			{
				pList_teacher->ClearList();
			}
			else if (order_choose == "2")
			{
				pList_student->ClearList();
			}
			else if (order_choose == "3")
			{
				pList_ader->ClearList();
			}
			else
			{
				error_input();
			}
		}
		else if (userOrder == "0")
		{
			cout << "���ڼ����˳����Ƿ��Ѿ������ļ���" << endl;
			cout << "0.�ѱ��棬ֱ���˳�ϵͳ" << endl;
			cout << "1.�������˵�����" << endl;
			cin >> order_0;
			if (order_0 == "0")
			{
				break;
			}
			else if(order_0=="1")
			{
				continue;
			}
			else 
			{
				error_input();
			}
		}
		else
		{
			error_input();
		}
		/*cout << "���Ĳ����Ѿ���ɣ�" << endl;
		cout << "�˳�ϵͳ������:0" << endl;
		cout << "�������˵��������������" << endl;
		cin >> tf_return;
		if (tf_return == "0")
		{
			break;
		}*/
	}
	cout << endl<<endl;
	cout << "�����˳�ϵͳ����л����ʹ�ã�" << endl;
	cout << "���ߣ�ͨ��1603���¡" << endl;
	cout << "QQ��928339761" << endl;
	cout << "E-mail��txgc-long@foxmail.com" << endl;
	cout << "E-mail��clongzlatan@gmail.com" << endl;
	delete pList_ader;
	pList_ader = NULL;
	delete pList_teacher;
	pList_teacher = NULL;
	delete pList_student;
	pList_student = NULL;
    return 0;
	system("pasue	");
}
