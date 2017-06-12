#include"People.h"
ostream &operator<<(ostream &out, Teacher &person)
{
	out << "人员类别：教师" << endl;
	out << "姓名：" << person.name << "" << endl; 
	out << "编号：" << person.num << "" << endl;
	out << "性别：" << person.sex << "" << endl;
	out << "年龄：" <<  person.ege << "" << endl;
	out << "科目：" << person.subject << "" << endl;
	out << "月薪：" << setiosflags(ios::fixed) << setprecision(2) << person.salary << "元/月" << endl;
	out << "工作量：" <<  person.workload << "月" << endl;
	out << "-------------------------" <<  endl;
	out <<endl;
	return out;
}

ostream &operator<<(ostream &out, Student &person)
{
	out << "人员类别：学生" << endl;
	out << "姓名：" << person.name << "" << endl;
	out << "编号：" << person.num << "" << endl;
	out << "性别：" << person.sex << "" << endl;
	out << "年龄：" << person.ege << "岁" << endl;
	out << "C++成绩：" << person.score1 << "分" << endl;
	out << "Java成绩：" << person.score2 << "分" << endl;
	out << "花销：" << setiosflags(ios::fixed) << setprecision(2) << person.expense << "元/月" << endl;
	out << "-------------------------" << endl;
	out << endl;
	return out;
}

ostream &operator<<(ostream &out, Ader &person)
{
	out << "人员类别：管理人员" << endl;
	out << "姓名：" << person.name << "" << endl;
	out << "编号：" << person.num << "" << endl;
	out << "性别：" << person.sex << "" << endl;
	out << "年龄：" << person.ege << "岁" << endl;
	out << "所属部门：" << person.department << "" << endl;
	out << "月薪：" << setiosflags(ios::fixed) << setprecision(2) << person.salary << "元/月" << endl;
	out << "工作量：" << person.workload << "月" << endl;
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