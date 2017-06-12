#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include"People.h"
class Node_teacher
{
public:
	Teacher data;
	Node_teacher * next;
	void printNode();
	void printNodeinFile();
};

class Node_student
{
public:
	Student data;
	Node_student * next;
	void printNode();
	void printNodeinFile();
};

class Node_ader
{
public:
	Ader data;
	Node_ader * next;
	void printNode();
	void printNodeinFile();
};

#endif // NODE_H_INCLUDED
