#ifndef  PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED
#include<string>
#include<ostream>
#include<fstream>
#include <iomanip>
using namespace std;
class People
{
	//friend ostream &operator<<(ostream &out, People &person);
public:
	string name;
	string num;
	string sex;
	int ege;
	//People &operator=(People &person);
	//bool operator==(People &person);
};

class Teacher :public People
{
	friend ostream &operator<<(ostream &out, Teacher &person);
public:
	string subject;
	double salary;
	double workload;
	Teacher & operator=(Teacher & person);
	bool operator==(Teacher &person);
};

class Student :public People
{
	friend ostream &operator<<(ostream &out, Student &person);
public:
	double score1;
	double score2;
	double expense;
	Student & operator=(Student &person);
	bool operator==(Student &person);
};

class Ader :public People
{
	friend ostream &operator<<(ostream &out, Ader &person);
public:
	string department;
	double salary;
	double workload;
	Ader & operator=(Ader &person);
	bool operator==(Ader &person);
};
#endif