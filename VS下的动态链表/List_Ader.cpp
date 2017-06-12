#include"List_Ader.h"
#include<iostream>
using namespace std;
List_Ader::List_Ader()
{
	m_pList = new Node_ader;
	//  m_pList->data=0;
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List_Ader::ListEmpty()
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

int List_Ader::ListLength()
{
	return m_iLength;
}

void List_Ader::ClearList()
{
	Node_ader *currentNode = m_pList->next;
	while (currentNode != NULL)
	{
		Node_ader* temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
	m_iLength = 0;
}

List_Ader::~List_Ader()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List_Ader::ListInsertHead(Node_ader * pNode)
{
	Node_ader *temp = m_pList->next;
	Node_ader *newNode = new Node_ader;
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

bool List_Ader::ListInsertTail(Node_ader * pNode)
{
	Node_ader *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	Node_ader *newNode = new Node_ader;
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

bool List_Ader::ListInsert(int i, Node_ader *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node_ader * currentNode = m_pList;
	for (int k = 0; k<i; k++)
	{
		currentNode = currentNode->next;
	}
	Node_ader *newNode = new Node_ader;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

bool List_Ader::ListDelete(int i, Node_ader *pNode)
{

	if (i<0 || i >= m_iLength)
	{
		return false;
	}
	Node_ader*currentNode = m_pList;
	Node_ader*currentNodeBefore = NULL;
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

bool List_Ader::GetElem(int i, Node_ader * pNode)
{
	if (i<0 || i >= m_iLength)
	{
		return false;
	}
	Node_ader*currentNode = m_pList;
	Node_ader*currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List_Ader::LocateElem(Node_ader *pNode)
{
	Node_ader*currentNode = m_pList;
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

bool List_Ader::PriorElem(Node_ader *pCurrentNode, Node_ader *pPreNode)
{
	Node_ader *currentNode = m_pList;
	Node_ader *tempNode = NULL;
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

bool List_Ader::NextElem(Node_ader *pCurrentNode, Node_ader *pNextNode)
{
	Node_ader *currentNode = m_pList;
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

void List_Ader::ListTraverse()
{
	int i=0;
	Node_ader*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		i++;
		currentNode = currentNode->next;
		cout << "ÏµÍ³ÖÐ´æ´¢ÐòºÅ£º" << i << endl;
		currentNode->printNode();

	}
}

void List_Ader::ListTraverseinFile()
{
	Node_ader*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNodeinFile();
	}
}

void List_Ader::ListRank_num()
{
	int times = m_iLength;
	Node_ader*currentNode = m_pList->next;
	Node_ader*teilNode = NULL;
	for (int k = 0; k < m_iLength; k++)
	{
		if (times > 1)
		{
			Ader  temp;
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

Node_ader *List_Ader::Gethead()
{
	return m_pList;
}

bool List_Ader::ListFindbynum(string num, Node_ader *pNode)
{
	Node_ader*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data.num == num)
		{
			pNode->data = currentNode->data;
			return true;
		}
	}
	return false;
}