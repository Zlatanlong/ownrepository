#ifndef LIST_STUDENT_H_INCLUDED
#define LIST_STUDENT_H_INCLUDED
#include"Node.h"
class List_Student
{
public:
	List_Student();
	~List_Student();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node_student *pNode);
	int LocateElem(Node_student *pNode);
	bool PriorElem(Node_student *pCurrentNode, Node_student *pPreNode);
	bool NextElem(Node_student *pCurrentNode, Node_student *pNextNode);
	void ListTraverse();
	void ListTraverseinFile();
	bool ListInsert(int i, Node_student *pNode);
	bool ListDelete(int i, Node_student *pNode);
	bool ListInsertHead(Node_student *pNode);
	bool ListInsertTail(Node_student *pNode);
	void ListRank_num();
	void ListRank_c();
	void ListRank_j();
	Node_student *Gethead();
	bool ListFindbynum(string num, Node_student *pNode);
private:
	Node_student * m_pList;
	int m_iLength;
};


#endif // LIST_H_INCLUDED
