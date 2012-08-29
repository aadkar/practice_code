// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linked_list.h"
#include<malloc.h>
#include<stdio.h>

void PrintList(Node* pHead)
{
	printf("\n\n");
	while(pHead)
	{
		printf("%d->",pHead->data);
		pHead = pHead->pNext;
	}

	printf("NULL\n\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node* pHead = (Node*)malloc(sizeof(Node));
	pHead->data = 123;
	pHead->pNext = NULL;

	AddNode(pHead,1);
	AddNode(pHead,2);
	AddNode(pHead,3);
	AddNode(pHead,4);
	AddNode(pHead,5);
	AddNode(pHead,6);
	AddNode(pHead,7);
	AddNode(pHead,8);
	AddNode(pHead,9);
	AddNode(pHead,10);
	AddNode(pHead,11);
	PrintList(pHead);
	
	printf("\nSwapping nodes 4,5\n");
	Node* pNode4 = GetNode(pHead,0);
	Node* pNode5 = GetNode(pHead,8);

	pHead = SwapNodes(pHead,pNode4,pNode5);

	PrintList(pHead);

}



