#include"Node.h"
#include<iostream>
using namespace std;
void Node_student::printNode()
{
    cout<<data<<endl;
}

void Node_student::printNodeinFile()
{
	ofstream fout("Students.txt", ios::app);
	if (!fout)
	{
		cout << "Cannot open output file.\n";
		return;
	}
	fout << data.name << endl;
	fout << data.num << endl;
	fout << data.sex << endl;
	fout  << data.ege << endl;
	fout  << data.score1 << endl;
	fout << data.score2 << endl;
	fout << setiosflags(ios::fixed) << setprecision(2) << data.expense << endl;
	fout.close();
}

void Node_teacher::printNode()
{
	cout << data << endl;
}

void Node_teacher::printNodeinFile()
{
	ofstream fout("Teachers.txt", ios::app);
	if(!fout)
	{
		cout << "Cannot open output file.\n";
		return ;
	}
	fout << data.name << endl;
	fout << data .num<< endl;
	fout << data .sex<< endl;
	fout  << data .ege<< endl;
	fout << data.subject << endl;
	fout << setiosflags(ios::fixed) << setprecision(2) << data .salary<< endl;
	fout << data .workload<< endl;
	fout.close();
}

void Node_ader::printNode()
{
	cout << data << endl;
}

void Node_ader::printNodeinFile()
{
	ofstream fout("Aders.txt", ios::app);
	if (!fout)
	{
		cout << "Cannot open output file.\n";
		return;
	}
	fout << data.name << endl;
	fout << data.num << endl;
	fout << data.sex << endl;
	fout << data.ege << endl;
	fout << data.department << endl;
	fout << setiosflags(ios::fixed) << setprecision(2) << data.salary << endl;
	fout << data.workload << endl;
	fout.close();
}
