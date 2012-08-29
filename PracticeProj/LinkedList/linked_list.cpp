#include "linked_list.h"
#include<malloc.h>
#include<stdio.h>

void AddNode(Node* pHead,int data)
{
	if(!pHead)	return;

	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->data = data;
	pNode->pNext = NULL;

	AddNode(pHead,pNode);
}

void AddNode(Node* pHead,Node* pNode)
{
	if(!pHead) return;

	while(pHead->pNext)
	{
		pHead = pHead->pNext;
	}

	pHead->pNext = pNode;
}

Node* RemoveNode(Node* pHead,int pos)
{
	if(!pHead || !pos) return NULL;

	Node* pRet = NULL;
	
	int idx = 0;

	while(pHead->pNext && (idx != (pos - 1)))
	{
		pHead = pHead->pNext;
		++idx;
	}

	if(pHead->pNext)
	{
		pRet = pHead->pNext;
		pHead->pNext = pRet->pNext;
	}

	return pRet;
}

void DeleteNode(Node* pHead, int pos)
{
	if(!pHead || !pos) return;

	int idx = 0;

	while(pHead->pNext && (idx != pos - 1))
	{
		pHead = pHead->pNext;
		++idx;
	}

	if(pHead->pNext)
	{
		Node *pToDie = pHead->pNext;
		pHead->pNext = pToDie->pNext;
		free(pToDie);
		pToDie = NULL;
	}
}

void DeleteNode(Node* pHead, Node* pNode)
{
	if(!pHead || !pNode) return;

	while(pHead->pNext && (pHead->pNext != pNode))
	{
		pHead = pHead->pNext;
	}

	if(pHead->pNext)
	{
		Node* pToDie = pHead->pNext;
		pHead->pNext = pToDie->pNext;
		free(pToDie);
		pToDie = NULL;
	}
}

Node* RecursiveReverse(Node* pHead, Node* pPrev)
{
	if(!pHead) return NULL;
	
	if(pHead->pNext == NULL)
	{
		//we have reached the end of the list. Now to backtrack from here.
		pHead->pNext = pPrev;
		return pHead;
	}
	else
	{
		Node *temp = RecursiveReverse(pHead->pNext,pHead);
		pHead->pNext = pPrev;
		return temp;
	}
}