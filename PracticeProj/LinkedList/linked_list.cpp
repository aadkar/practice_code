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

Node* GetNode(Node* pHead, int pos)
{
	int idx = 0;

	while(pHead && idx != pos)
	{
		pHead = pHead->pNext;
		++idx;
	}

	return pHead;
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

Node* ReverseList(Node* pHead)
{
	Node* temp = NULL; //place holder
	Node* pPrevNode = NULL; // a node to track previous node to the current node

	while(pHead)
	{
		temp = pHead->pNext;
		pHead->pNext = pPrevNode;
		pPrevNode = pHead;
		pHead = temp;
	}

	return pPrevNode;
}

Node* SwapNodes(Node* pHead,Node* pNodeA,Node* pNodeB)
{
	if(!pHead || !pNodeA || !pNodeB) return pHead;

	if(pNodeA == pNodeB) return pHead;

	Node* pActualHead = pHead;
	Node* pNodeAPrev = NULL;
	Node* pNodeBPrev = NULL;
	
	bool bNodeAFound = false;
	bool bNodeBFound = false;
	
	Node* pNodePrev = NULL;

	while(pHead && (!bNodeAFound || !bNodeBFound))
	{
		if(pHead == pNodeA)
		{
			bNodeAFound = true;		
			pNodeAPrev = pNodePrev;
		}
		else if(pHead == pNodeB)
		{
			bNodeBFound = true;
			pNodeBPrev = pNodePrev;
		}
		
		pNodePrev = pHead;
		pHead = pHead->pNext;

	}

	if(!bNodeAFound || !bNodeBFound)
	{
		return NULL;
	}

	if(pNodeAPrev) 
	{
		pNodeAPrev->pNext = pNodeB;
	}
	else
	{
		pActualHead = pNodeB;
	}
	
	if(pNodeBPrev)
	{
		pNodeBPrev->pNext = pNodeA;
	}
	else
	{
		pActualHead = pNodeA;
	}

	Node* temp = pNodeA->pNext;
	pNodeA->pNext = pNodeB->pNext;
	pNodeB->pNext = temp;

	return pActualHead;
}