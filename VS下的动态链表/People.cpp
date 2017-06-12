#include"People.h"
ostream &operator<<(ostream &out, Teacher &person)
{
	out << "��Ա��𣺽�ʦ" << endl;
	out << "������" << person.name << "" << endl; 
	out << "��ţ�" << person.num << "" << endl;
	out << "�Ա�" << person.sex << "" << endl;
	out << "���䣺" <<  person.ege << "" << endl;
	out << "��Ŀ��" << person.subject << "" << endl;
	out << "��н��" << setiosflags(ios::fixed) << setprecision(2) << person.salary << "Ԫ/��" << endl;
	out << "��������" <<  person.workload << "��" << endl;
	out << "-------------------------" <<  endl;
	out <<endl;
	return out;
}

ostream &operator<<(ostream &out, Student &person)
{
	out << "��Ա���ѧ��" << endl;
	out << "������" << person.name << "" << endl;
	out << "��ţ�" << person.num << "" << endl;
	out << "�Ա�" << person.sex << "" << endl;
	out << "���䣺" << person.ege << "��" << endl;
	out << "C++�ɼ���" << person.score1 << "��" << endl;
	out << "Java�ɼ���" << person.score2 << "��" << endl;
	out << "������" << setiosflags(ios::fixed) << setprecision(2) << person.expense << "Ԫ/��" << endl;
	out << "-------------------------" << endl;
	out << endl;
	return out;
}

ostream &operator<<(ostream &out, Ader &person)
{
	out << "��Ա��𣺹�����Ա" << endl;
	out << "������" << person.name << "" << endl;
	out << "��ţ�" << person.num << "" << endl;
	out << "�Ա�" << person.sex << "" << endl;
	out << "���䣺" << person.ege << "��" << endl;
	out << "�������ţ�" << person.department << "" << endl;
	out << "��н��" << setiosflags(ios::fixed) << setprecision(2) << person.salary << "Ԫ/��" << endl;
	out << "��������" << person.workload << "��" << endl;
	out << "-------------------------" << endl;
	out << endl;
	return out;
}

Teacher &Teacher::operator=(Teacher &person)
{
	this->name = person.name;
	this->num = person.num;
	this->sex = person.sex;
	this->ege = person.ege;
	this->subject = person.subject;
	this->salary = person.salary;
	this->workload = person.workload;
	return *this;
}

Student &Student::operator=(Student &person)
{
	this->name = person.name;
	this->num = person.num;
	this->sex = person.sex;
	this->ege = person.ege;
	this->score1 = person.score1;
	this->score2 = person.score2;
	this->expense = person.expense;
	return *this;
}

Ader &Ader::operator=(Ader &person)
{
	this->name = person.name;
	this->num = person.num;
	this->sex = person.sex;
	this->ege = person.ege;
	this->department = person.department;
	this->salary = person.salary;
	this->workload = person.workload;
	return *this;
}

bool Teacher::operator==(Teacher &person)
{
	if (this->name == person.name && this->num == person.num&& this->sex == person.sex&& this->ege == person.ege&& this->subject == person.subject&& this->salary == person.salary&& this->workload == person.workload)
	{
		return true;
	}
	return false;
}

bool Student::operator==(Student &person)
{
	if (this->name == person.name && this->num == person.num&& this->sex == person.sex&& this->ege == person.ege&& this->score1 == person.score1&& this->score2 == person.score2&& this->expense == person.expense)
	{
		return true;
	}
	return false;
}

bool Ader::operator==(Ader &person)
{
	if (this->name == person.name && this->num == person.num&& this->sex == person.sex&& this->ege == person.ege&& this->department == person.department&& this->salary == person.salary&& this->workload == person.workload)
	{
		return true;
	}
	return false;
}