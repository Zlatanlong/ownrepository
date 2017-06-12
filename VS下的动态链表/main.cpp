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
	cout << "|*---------------主菜单-----------------*|" << endl;
	cout << "|*--------1.从文件中读取人员数据--------*|" << endl;
	cout << "|*--------2.录入新成员------------------*|" << endl;
	cout << "|*--------3.从指定位置录入新成员--------*|" << endl;
	cout << "|*--------4.保存所有成员到文件----------*|" << endl;
	cout << "|*--------5.浏览所有人员----------------*|" << endl;
	cout << "|*--------6.更改人员数据----------------*|" << endl;
	cout << "|*--------7.删除人员--------------------*|" << endl;
	cout << "|*--------8.选择排序方法----------------*|" << endl;
	cout << "|*--------9.选择数据操作方法------------*|" << endl;
	cout << "|*--------10.按编号查找-----------------*|" << endl;
	cout << "|*--------11.清空人员数据---------------*|" << endl;
	cout << "|*--------0.退出系统--------------------*|" << endl;
	cout << "     请输入：" ;
	string order = "null";
	cin >> order;
	cout << endl;
	return order;
}

string choose()
{
	string order_de1 = "null";
	cout << "请选择人员类型：" << endl;
	cout << "1.老师" << endl;
	cout << "2.学生" << endl;
	cout << "3.管理人员" << endl;
	cin >> order_de1;
	cout << endl;
	return order_de1;
}

void error_input()
{ cout <<endl<< "---!!!提示：请输入正确的数字!!!---" << endl<<endl; }


void create_teacher(List_Teacher *pList_teacher)
{
	Node_teacher node_teacher;
	Teacher teacher1;
	cout << "请输入该老师的姓名：";
	cin >> teacher1.name;
	cout << "请输入该老师的编号：";
	cin >> teacher1.num;
	cout << "请输入该老师的性别：";
	cin >> teacher1.sex;
	cout << "请输入该老师的年龄：";
	cin >> teacher1.ege;
	cout << "请输入该老师的科目：";
	cin >> teacher1.subject;
	cout << "请输入该老师的月薪：";
	cin >> teacher1.salary;
	cout << "请输入该老师的工作量：";
	cin >> teacher1.workload;
	node_teacher.data = teacher1;
	pList_teacher->ListInsertTail(&node_teacher);
	cout << "----------------------老师录入完成-----------------------"<<endl<<endl;
}

void create_student(List_Student *pList_student)
{
	Node_student node_student;
	Student student1;
	cout << "请输入该学生的姓名：";
	cin >> student1.name;
	cout << "请输入该学生的编号：";
	cin >> student1.num;
	cout << "请输入该学生的性别：";
	cin >> student1.sex;
	cout << "请输入该学生的年龄：";
	cin >> student1.ege;
	cout << "请输入该学生C++的成绩：";
	cin >> student1.score1;
	cout << "请输入该学生Java的成绩：";
	cin >> student1.score2;
	cout << "请输入学生的月花销：";
	cin >> student1.expense;
	node_student.data = student1;
	pList_student->ListInsertTail(&node_student);
	cout << "----------------------学生录入完成-----------------------" <<endl<< endl;
}

void create_ader(List_Ader *pList_ader)
{
	Node_ader node_ader;
	Ader ader1;
	cout << "请输入该管理人员的姓名：";
	cin >> ader1.name;
	cout << "请输入该管理人员的编号：";
	cin >> ader1.num;
	cout << "请输入该管理人员的性别：";
	cin >> ader1.sex;
	cout << "请输入该管理人员的年龄：";
	cin >> ader1.ege;
	cout << "请输入该管理人员的部门：";
	cin >> ader1.department;
	cout << "请输入该管理人员的月薪：";
	cin >> ader1.salary;
	cout << "请输入该管理人员的工作量：";
	cin >> ader1.workload;
	node_ader.data = ader1;
	pList_ader->ListInsertTail(&node_ader);
	cout << "----------------------管理人员录入完成-----------------------" <<endl<< endl;
}


void create_teacher_at(List_Teacher *pList_teacher)
{
	Node_teacher node_teacher;
	Teacher teacher1;
	int i;
	cout << "请输入插入位置（请输入整数）：";
	cin >>i;
	if (i > pList_teacher->ListLength())
	{
		cout << "请输入正确的位置" <<endl<< endl;
		return;
	}
	else 
	{
		cout << "请输入该老师的姓名：";
		cin >> teacher1.name;
		cout << "请输入该老师的编号：";
		cin >> teacher1.num;
		cout << "请输入该老师的性别：";
		cin >> teacher1.sex;
		cout << "请输入该老师的年龄：";
		cin >> teacher1.ege;
		cout << "请输入该老师的科目：";
		cin >> teacher1.subject;
		cout << "请输入该老师的月薪：";
		cin >> teacher1.salary;
		cout << "请输入该老师的工作量：";
		cin >> teacher1.workload;
		node_teacher.data = teacher1;
		pList_teacher->ListInsert(i - 1, &node_teacher);
		cout << "----------------------老师插入完成--------------------------" << endl<<endl;
	}
}

void create_student_at(List_Student *pList_student)
{
	Node_student node_student;
	Student student1;
	int i;
	cout << "请输入插入位置（请输入整数）：";
	cin >> i;
	if (i > pList_student->ListLength())
	{
		cout << "请输入正确的位置" << endl << endl;
		return;
	}
	else
	{
		cout << "请输入该学生的姓名：";
		cin >> student1.name;
		cout << "请输入该学生的编号：";
		cin >> student1.num;
		cout << "请输入该学生的性别：";
		cin >> student1.sex;
		cout << "请输入该学生的年龄：";
		cin >> student1.ege;
		cout << "请输入该学生C++的成绩：";
		cin >> student1.score1;
		cout << "请输入该学生Java的成绩：";
		cin >> student1.score2;
		cout << "请输入学生的月花销：";
		cin >> student1.expense;
		node_student.data = student1;
		pList_student->ListInsert(i - 1, &node_student);
		cout << "----------------------学生插入完成--------------------------" <<endl<< endl;
	}
}

void create_ader_at(List_Ader *pList_ader)
{
	Node_ader node_ader;
	Ader ader1;
	int i;
	cout << "请输入插入位置（请输入整数）：";
	cin >> i;
	if (i > pList_ader->ListLength())
	{
		cout << "请输入正确的位置" << endl << endl;
		return;
	}
	else
	{
		cout << "请输入该管理人员的姓名：";
		cin >> ader1.name;
		cout << "请输入该管理人员的编号：";
		cin >> ader1.num;
		cout << "请输入该管理人员的性别：";
		cin >> ader1.sex;
		cout << "请输入该管理人员的年龄：";
		cin >> ader1.ege;
		cout << "请输入该管理人员的部门：";
		cin >> ader1.department;
		cout << "请输入该管理人员的月薪：";
		cin >> ader1.salary;
		cout << "请输入该管理人员的工作量：";
		cin >> ader1.workload;
		node_ader.data = ader1;
		pList_ader->ListInsert(i - 1, &node_ader);
		cout << "----------------------管理人员插入完成--------------------------" <<endl<<endl;
	}
}


void change_teacher(List_Teacher *pList_teacher)
{
	int i; string gettf = "null";
	Node_teacher node_teacher;
	cout << "请输入更改的序号：" << endl;
	cin >> i;
	pList_teacher->GetElem(i-1, &node_teacher);
	cout << "请确认修改人员的信息（确认：1；放弃：0；）" << endl;
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
		cout << "请输入该老师的姓名：";
		cin >> teacher1.name;
		cout << "请输入该老师的编号：";
		cin >> teacher1.num;
		cout << "请输入该老师的性别：";
		cin >> teacher1.sex;
		cout << "请输入该老师的年龄：";
		cin >> teacher1.ege;
		cout << "请输入该老师的科目：";
		cin >> teacher1.subject;
		cout << "请输入该老师的月薪：";
		cin >> teacher1.salary;
		cout << "请输入该老师的工作量：";
		cin >> teacher1.workload;
		node_teacher.data = teacher1;
		pList_teacher->ListInsert(i-1, &node_teacher);
		cout <<endl<< "----------------------修改完成--------------------------" << endl << endl;
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
	cout << "请输入更改的序号：" << endl;
	cin >> i;
	pList_student->GetElem(i-1, &node_student);
	cout << "请确认修改人员的信息（确认：1；放弃：0；）" << endl;
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
		cout << "请输入该学生的姓名：";
		cin >> student1.name;
		cout << "请输入该学生的编号：";
		cin >> student1.num;
		cout << "请输入该学生的性别：";
		cin >> student1.sex;
		cout << "请输入该学生的年龄：";
		cin >> student1.ege;
		cout << "请输入该学生C++的成绩：";
		cin >> student1.score1;
		cout << "请输入该学生Java的成绩：";
		cin >> student1.score2;
		cout << "请输入学生的月花销：";
		cin >> student1.expense;
		node_student.data = student1;
		pList_student->ListInsert(i-1, &node_student);
		cout << endl << "----------------------修改完成--------------------------" << endl << endl;
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
	cout << "请输入更改的序号：" << endl;
	cin >> i;
	pList_ader->GetElem(i-1, &node_ader);
	cout << "请确认修改人员的信息（确认：1；放弃：0；）" << endl;
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
		cout << "请输入插入位置（请输入整数）：";
		cin >> i;
		cout << "请输入该管理人员的姓名：";
		cin >> ader1.name;
		cout << "请输入该管理人员的编号：";
		cin >> ader1.num;
		cout << "请输入该管理人员的性别：";
		cin >> ader1.sex;
		cout << "请输入该管理人员的年龄：";
		cin >> ader1.ege;
		cout << "请输入该管理人员的部门：";
		cin >> ader1.department;
		cout << "请输入该管理人员的月薪：";
		cin >> ader1.salary;
		cout << "请输入该管理人员的工作量：";
		cin >> ader1.workload;
		node_ader.data = ader1;
		pList_ader->ListInsert(i, &node_ader);
		cout << endl << "----------------------修改完成--------------------------" << endl << endl;
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
	cout << "请输入想要删除人员的序号：" << endl;
	cin >> i;
	tf=pList_teacher->GetElem(i-1, &node_teacher);
	if (tf == true) {
		node_teacher.printNode();
		cout << "请确认想要删除人员的信息（确认：1；放弃：0；）" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_teacher->ListDelete(i-1, &node_teacher);
			cout << "----------------------删除完成--------------------------" << endl;
		}
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
	}
}

void delete_at_student(List_Student *pList_student)
{
	int i; string gettf = "null"; bool tf;
	Node_student node_student;
	cout << "请输入想要删除人员的序号：" << endl;
	cin >> i;
	tf = pList_student->GetElem(i-1, &node_student);
	if (tf == true) {
		node_student.printNode();
		cout << "请确认想要删除人员的信息（确认：1；放弃：0；）" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_student->ListDelete(i-1, &node_student);
			cout << "----------------------删除完成--------------------------" << endl;
		}
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
	}
}

void delete_at_ader(List_Ader *pList_ader)
{
	bool tf;
	int i; string gettf = "null";
	Node_ader node_ader;
	cout << "请输入想要删除人员的序号：" << endl;
	cin >> i;
	tf = pList_ader->GetElem(i-1, &node_ader);
	if (tf == true) {
		node_ader.printNode();
		cout << "请确认想要删除人员的信息（确认：1；放弃：0；）" << endl;
		cin >> gettf;
		if (gettf == "0")
		{
			return;
		}
		else if (gettf == "1")
		{
			pList_ader->ListDelete(i-1, &node_ader);
			cout << "----------------------删除完成--------------------------" << endl;
		}
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
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
	cout << "请输入老师编号：" << endl;
	cin >> n;
	Node_teacher node_teacher;
	tf=pList_teacher->ListFindbynum(n, &node_teacher);
	if (tf == true) {
		node_teacher.printNode();
		cout << endl << "----------查找完毕----------" << endl << endl;
		return;
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
		return;
	}
}

void find_Studentbynum(List_Student *pList_student)
{
	bool tf;
	string n = "null";
	cout << "请输入学生编号：" << endl;
	cin >> n;
	Node_student node_student;
	pList_student->ListFindbynum(n, &node_student);
	if (tf == true) {
		node_student.printNode();
		cout << endl << "----------查找完毕----------" << endl << endl;
		return;
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
		return;
	}
}

void find_Aderbynum(List_Ader *pList_ader)
{
	bool tf;
	string n = "null";
	cout << "请输入管理人员编号：" << endl;
	cin >> n;
	Node_ader node_ader;
	pList_ader->ListFindbynum(n, &node_ader);
	if (tf == true) {
		node_ader.printNode();
		cout <<endl<< "----------查找完毕----------" << endl<<endl;
		return;
	}
	else
	{
		cout << "没有找到，请您确认后重新查找" << endl;
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
	cout << "---------------老师数据读取完成-------------------" << endl << endl;
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
	cout << "---------------学生数据读取完成-------------------" << endl << endl;
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
	cout << "---------------管理人员数据读取完成-------------------" << endl << endl;
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
	cout << "您好，欢迎来到:" << endl;
	cout << "          中国石油大学（华东）人员及财务管理系统Pre-alpha1.0_5.12"<<endl ;
	cout<<"          （使用方法：输入数字进入功能选项）"<<endl;
	cout << endl;
	while (userOrder != "00")
	{
		userOrder = menu();
		if (userOrder == "1")
		{
			cout << endl;
			cout << "您的选择是：1.从文件中读取人员数据" << endl;
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
			cout << "您的选择是：2.录入新成员" << endl;
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
			cout << "您的选择是：3.从指定位置录入新成员" << endl;
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
			cout << "您的选择是：4.保存所有成员到文件" << endl;
			order_choose = choose();
		 if (order_choose == "1")
			{
			 remove("Teachers.txt");
				pList_teacher->ListTraverseinFile();
				cout << "--------保存完成！--------" << endl<<endl;
			}
		else if (order_choose == "2")
			{
			remove("Students.txt");
				pList_student->ListTraverseinFile();
				cout << "--------保存完成！--------" << endl << endl;
			}
			if (order_choose == "3")
			{
				remove("Aders.txt");
				pList_ader->ListTraverseinFile();
				cout << "--------保存完成！--------" << endl << endl;
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
			cout << "您的选择是：5.浏览所有人员" << endl;
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
			cout << "您的选择是：6.更改人员数据" << endl;
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
			cout << "您的选择是：7.删除人员" << endl;
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
			cout << "您的选择是：8.选择排序方法" << endl;
			cout << "请您继续选择：" << endl;
			string order_de8="null";
			cout << "1.按编号排序（由小到大）" << endl;
			cout << "2.按C++成绩对学生排序（由高至低）" << endl;
			cout << "3.按Java成绩对学生排序（由高至低）" << endl;
			cout << "0.返回上一层菜单" << endl;
			cout << "更多功能请联系作者" << endl<<endl;
			cin >> order_de8;
			if (order_de8 == "1")
			{
				cout << "您的选择是：1.按编号排序（由小到大）" << endl;
				order_choose = choose();
				if (order_choose == "1")
				{
					pList_teacher->ListRank_num();
					cout<< endl << "----------排序完成----------" << endl << endl;
				}
				if (order_choose == "2")
				{
					pList_student->ListRank_num();
					cout << endl << "----------排序完成----------" << endl << endl;
				}
				if (order_choose == "3")
				{
					pList_ader->ListRank_num();
					cout << endl << "----------排序完成----------" << endl << endl;
				}
				else
				{
					error_input();
				}
			}
			else if (order_de8=="2")
			{
				cout << "您的选择是：2.按C++成绩对学生排序（由高至低）" << endl;
				pList_student->ListRank_c();
				cout << endl << "----------排序完成----------" << endl << endl;
			}
			else if (order_de8 == "3")
			{
				cout << "您的选择是：3.按Java成绩对学生排序（由高至低）" << endl;
				pList_student->ListRank_j();
				cout <<endl<< "----------排序完成----------" << endl << endl;
			}
			else if (order_de8 == "0")
			{
				cout << "您的选择是：0.返回上一层菜单" << endl;
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
			cout << "您的选择是：9.选择数据操作方法" << endl;
			cout << "请您继续选择：" << endl;
			string order_de9="null";
			cout << "1.统计各类型人员数" << endl;
			cout << "2.统计老师平均工资" << endl;
			cout << "3.统计学生C++平均成绩" << endl;
			cout << "0.返回上一层菜单" << endl;
			cout << "更多功能请联系作者" << endl<<endl;
			cin >> order_de9;
			if (order_de9 == "1")
			{
				cout << "您的选择是：1.统计各类型人员数" << endl;
				cout << "老师的总人数是："<<pList_teacher->ListLength()<<endl;
				cout << "学生的总人数是："<<pList_student->ListLength()<<endl;
				cout << "管理人员的总人数是："<<pList_ader->ListLength()<<endl;
				cout << endl << endl;
			}
			else if (order_de9 == "2")
			{
				cout << "您的选择是：2.统计老师平均工资" << endl;
				cout<<"老师的平均工资是："<<ave_salary_teacher(pList_teacher)<<"元/月"<<endl;
				cout << endl << endl;
			}
			else if (order_de9 == "3")
			{
				cout << "您的选择是：3.统计学生C++平均成绩" << endl;
				cout << "学生C++的平均成绩是" << ave_c_student(pList_student) << "分" << endl;
				cout << endl << endl;
			}
			else if (order_de9 == "0")
			{
				cout << "您的选择是：0.返回上一层菜单" << endl;
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
			cout << "您的选择是：10.按编号查找" << endl;
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
			cout << "您的选择是：11.清空人员数据" << endl;
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
			cout << "现在即将退出，是否已经保存文件？" << endl;
			cout << "0.已保存，直接退出系统" << endl;
			cout << "1.返回主菜单保存" << endl;
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
		/*cout << "您的操作已经完成！" << endl;
		cout << "退出系统请输入:0" << endl;
		cout << "返回主菜单请输入任意键。" << endl;
		cin >> tf_return;
		if (tf_return == "0")
		{
			break;
		}*/
	}
	cout << endl<<endl;
	cout << "您已退出系统，感谢您的使用！" << endl;
	cout << "作者：通信1603李昌隆" << endl;
	cout << "QQ：928339761" << endl;
	cout << "E-mail：txgc-long@foxmail.com" << endl;
	cout << "E-mail：clongzlatan@gmail.com" << endl;
	delete pList_ader;
	pList_ader = NULL;
	delete pList_teacher;
	pList_teacher = NULL;
	delete pList_student;
	pList_student = NULL;
    return 0;
	system("pasue	");
}
