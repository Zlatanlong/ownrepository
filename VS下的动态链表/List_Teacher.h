#ifndef LIST_TEACHER_H_INCLUDED
#define LIST_TEACHER_H_INCLUDED
#include"Node.h"
class List_Teacher
{
public:
    List_Teacher();
    ~List_Teacher();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i,Node_teacher *pNode);
    int LocateElem(Node_teacher *pNode);
    bool PriorElem(Node_teacher *pCurrentNode, Node_teacher *pPreNode);
    bool NextElem(Node_teacher *pCurrentNode, Node_teacher *pNextNode);
    void ListTraverse();
	void ListTraverseinFile();
    bool ListInsert(int i, Node_teacher *pNode);
    bool ListDelete(int i, Node_teacher *pNode);
    bool ListInsertHead(Node_teacher *pNode);
    bool ListInsertTail(Node_teacher *pNode);
	void ListRank_num();
	bool ListFindbynum(string num_t, Node_teacher *pNode);
	Node_teacher * Gethead();
	
private:
	Node_teacher * m_pList;
    int m_iLength;
};


#endif // LIST_H_INCLUDED
