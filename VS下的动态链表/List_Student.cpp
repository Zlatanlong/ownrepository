#include"List_Student.h"
#include<iostream>
using namespace std;
List_Student::List_Student()
{
	m_pList = new Node_student;
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List_Student::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int List_Student::ListLength()
{
	return m_iLength;
}

void List_Student::ClearList()
{
	Node_student *currentNode = m_pList->next;
	while (currentNode != NULL)
	{
		Node_student* temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
	m_iLength = 0;
}

List_Student::~List_Student()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List_Student::ListInsertHead(Node_student * pNode)
{
	Node_student *temp = m_pList->next;
	Node_student *newNode = new Node_student;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List_Student::ListInsertTail(Node_student * pNode)
{
	Node_student *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	Node_student *newNode = new Node_student;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List_Student::ListInsert(int i, Node_student *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node_student * currentNode = m_pList;
	for (int k = 0; k<i; k++)
	{
		currentNode = currentNode->next;
	}
	Node_student *newNode = new Node_student;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

bool List_Student::ListDelete(int i, Node_student *pNode)
{

	if (i<0 || i >= m_iLength)
	{
		return false;
	}
	Node_student*currentNode = m_pList;
	Node_student*currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	m_iLength--;
	return true;
}

bool List_Student::GetElem(int i, Node_student * pNode)
{
	if (i<0 || i >= m_iLength)
	{
		return false;
	}
	Node_student*currentNode = m_pList;
	Node_student*currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List_Student::LocateElem(Node_student *pNode)
{
	Node_student*currentNode = m_pList;
	int sum = 0;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return sum;
		}
		sum++;
	}
	return -1;
}

bool List_Student::PriorElem(Node_student *pCurrentNode, Node_student *pPreNode)
{
	Node_student *currentNode = m_pList;
	Node_student *tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List_Student::NextElem(Node_student *pCurrentNode, Node_student *pNextNode)
{
	Node_student *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode == NULL)
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List_Student::ListTraverse()
{
	int i = 0;
	Node_student*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		i++;
		currentNode = currentNode->next;
		cout << "ÏµÍ³ÖÐ´æ´¢ÐòºÅ£º" << i << endl;
		currentNode->printNode();

	}
}

void List_Student::ListTraverseinFile()
{
	Node_student*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNodeinFile();
	}
}

void List_Student::ListRank_num()
{
	int times = m_iLength;
	Node_student*currentNode = m_pList->next;
	Node_student*teilNode = NULL;
	for (int k = 0; k < m_iLength; k++)
	{
		if (times > 1)
		{
			Student  temp;
			teilNode = currentNode;
			times--;
			for (int i = 0; i < times; i++)
			{
				if (teilNode->data.num > teilNode->next->data.num)
				{
					temp = teilNode->data;
					teilNode->data = teilNode->next->data;
					teilNode->next->data = temp;
				}
				teilNode = teilNode->next;
			}
			
			
		}
		else
		{
			return;
		}
	}
}

void List_Student::ListRank_c()
{
	int times = m_iLength;
	Node_student*currentNode = m_pList->next;
	Node_student*teilNode = NULL;
	for (int k = 0; k < m_iLength; k++)
	{
		if (times > 1)
		{
			Student  temp;
			teilNode = currentNode;
			times--;
			for (int i = 0; i < times; i++)
			{
				if (teilNode->data.score1 <teilNode->next->data.score1)
				{
					temp = teilNode->data;
					teilNode->data = teilNode->next->data;
					teilNode->next->data = temp;
				}
				teilNode = teilNode->next;
			}
		
		}
		else
		{
			return;
		}
	}
}

void List_Student::ListRank_j()
{
	int times = m_iLength;
	Node_student*currentNode = m_pList->next;
	Node_student*teilNode = NULL;
	for (int k = 0; k < m_iLength; k++)
	{
		if (times > 1)
		{
			Student  temp;
			teilNode = currentNode;
			times--;
			for (int i = 0; i < times; i++)
			{
				if (teilNode->data.score2 < teilNode->next->data.score2)
				{
					temp = teilNode->data;
					teilNode->data = teilNode->next->data;
					teilNode->next->data = temp;
				}
				teilNode = teilNode->next;
			}
			
			
		}
		else
		{
			return;
		}
	}
}

Node_student *List_Student::Gethead()
{
	return m_pList;
}

bool List_Student::ListFindbynum(string num_s, Node_student *pNode)
{
	Node_student*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data.num == num_s)
		{
			pNode->data = currentNode->data;
			return true;
		}
	}
	return false;
}