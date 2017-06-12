#include"List_Teacher.h"
#include<iostream>
#include<string>
using namespace std;
List_Teacher::List_Teacher()
{
    m_pList= new Node_teacher;
  //  m_pList->data=0;
    m_pList->next=NULL;
    m_iLength=0;
}

bool List_Teacher::ListEmpty()
{
    if(m_iLength==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int List_Teacher::ListLength()
{
    return m_iLength;
}

void List_Teacher::ClearList()
{
	Node_teacher *currentNode=m_pList->next;
    while(currentNode != NULL)
    {
		Node_teacher* temp=currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
    m_pList->next = NULL;
	m_iLength = 0;
}

List_Teacher::~List_Teacher()
{
    ClearList();
    delete m_pList;
    m_pList=NULL;
}

bool List_Teacher::ListInsertHead(Node_teacher * pNode)
{
	Node_teacher *temp = m_pList->next;
	Node_teacher *newNode = new Node_teacher;
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data = pNode->data;
    m_pList->next=newNode;
    newNode->next=temp;
    m_iLength++;
    return true;
}

bool List_Teacher::ListInsertTail(Node_teacher * pNode)
{
	Node_teacher *currentNode = m_pList;
    while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
    }
	Node_teacher *newNode = new Node_teacher;
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data=pNode->data;
    newNode->next=NULL;
    currentNode->next = newNode;
    m_iLength++;
    return true;
}

bool List_Teacher::ListInsert(int i, Node_teacher *pNode)
{
    if(i<0||i>m_iLength)
    {
        return false;
    }
	Node_teacher * currentNode=m_pList;
    for(int k = 0;k<i;k++)
    {
        currentNode = currentNode->next;
    }
	Node_teacher *newNode = new Node_teacher;
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data=pNode->data;
    newNode->next=currentNode->next;
    currentNode->next=newNode;
    return true;
}

bool List_Teacher::ListDelete(int i, Node_teacher *pNode)
{

    if(i<0||i>=m_iLength)
    {
        return false;
    }
	Node_teacher*currentNode=m_pList;
	Node_teacher*currentNodeBefore=NULL;
    for(int k = 0;k<=i;k++)
    {
        currentNodeBefore = currentNode;
        currentNode=currentNode->next;
    }
    currentNodeBefore->next=currentNode->next;
    pNode->data=currentNode->data;
    delete currentNode;
    m_iLength--;
    return true;
}

bool List_Teacher::GetElem(int i, Node_teacher * pNode)
{
     if(i<0||i>=m_iLength)
    {
        return false;
    }
	 Node_teacher*currentNode=m_pList;
    for(int k = 0;k<=i;k++)
    {
        currentNode=currentNode->next;
    }
    pNode->data=currentNode->data;
    return true;
}

int List_Teacher::LocateElem(Node_teacher *pNode)
{
	Node_teacher*currentNode=m_pList;
    int sum=0;
     while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
        if(currentNode->data==pNode->data)
        {
            return sum;
        }
        sum++;
    }
    return -1;
}

bool List_Teacher::PriorElem(Node_teacher *pCurrentNode, Node_teacher *pPreNode)
{
	Node_teacher *currentNode=m_pList;
	Node_teacher *tempNode=NULL;
     while(currentNode->next!=NULL)
    {
        tempNode=currentNode;
        currentNode = currentNode->next;
        if(currentNode->data==pCurrentNode->data)
        {
            if(tempNode==m_pList)
            {
                return false;
            }
            pPreNode->data=tempNode->data;
            return true;
        }
    }
    return false;
}

bool List_Teacher::NextElem(Node_teacher *pCurrentNode, Node_teacher *pNextNode)
{
	Node_teacher *currentNode=m_pList;
    while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
        if(currentNode->data==pCurrentNode->data)
        {
            if(currentNode==NULL)
            {
                return false;
            }
            pNextNode->data=currentNode->next->data;
            return true;
        }
    }
    return false;
}

void List_Teacher::ListTraverse()
{
	int i = 0;
	Node_teacher*currentNode= m_pList;
    while(currentNode->next!=NULL)
    {
		i++;
		currentNode=currentNode->next;
		cout << "ÏµÍ³ÖÐ´æ´¢ÐòºÅ£º" << i << endl;
        currentNode->printNode();
    }
}

void List_Teacher::ListTraverseinFile()
{
	Node_teacher*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNodeinFile();
	}
}

void List_Teacher::ListRank_num()
{
	int times = m_iLength;
		Node_teacher*currentNode = m_pList->next;
		Node_teacher*teilNode = NULL;
		for (int k = 0; k < m_iLength; k++)
		{
			if (times > 1)
			{
				Teacher  temp;
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

Node_teacher * List_Teacher::Gethead()
{
	return m_pList;
}

bool List_Teacher::ListFindbynum(string num_t, Node_teacher *pNode)
{
	Node_teacher*currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data.num == num_t)
		{
			pNode->data = currentNode->data;
			return true;
		}
	}
	return false;
}
