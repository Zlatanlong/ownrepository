#ifndef LIST_ADER_H_INCLUDED
#define LIST_ADER_H_INCLUDED
#include"Node.h"
class List_Ader
{
public:
	List_Ader();
	~List_Ader();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node_ader *pNode);
	int LocateElem(Node_ader *pNode);
	bool PriorElem(Node_ader *pCurrentNode, Node_ader *pPreNode);
	bool NextElem(Node_ader *pCurrentNode, Node_ader *pNextNode);
	void ListTraverse();
	void ListTraverseinFile();
	bool ListInsert(int i, Node_ader *pNode);
	bool ListDelete(int i, Node_ader *pNode);
	bool ListInsertHead(Node_ader *pNode);
	bool ListInsertTail(Node_ader *pNode);
	void ListRank_num();
	Node_ader *Gethead();
	bool ListFindbynum(string num, Node_ader *pNode);
private:
	Node_ader * m_pList;
	int m_iLength;
};


#endif // LIST_H_INCLUDED
