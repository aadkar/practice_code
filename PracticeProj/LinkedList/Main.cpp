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

	PrintList(pHead);

	printf("Reversing list...\n");
	Node* pReverseHead = RecursiveReverse(pHead,NULL);
	PrintList(pReverseHead);

}



