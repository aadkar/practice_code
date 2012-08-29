#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct tagNode
{
	int data;
	struct tagNode* pNext;
};

typedef struct tagNode Node;

/**
	Adds a node to the end of the list.
	This function will allocate a new Node object and append it to the list.

	@param pHead A pointer to the head of the linked list
	@param data value to be stored inside the new node.
*/
void AddNode(Node* pHead,int data);


/**
	Adds a node to the end of the list.
	This assumes a pre-allocated node object. Null pointers will be ignored.

	@param pHead A pointer to the head of the linked list
	@param pNode A valid pointer to the Node object to be appended to the list

*/
void AddNode(Node* pHead,Node* pNode);


/**
	Retrieves a node from a specified position
	@param pHead A pointer to the head of the list
	@param pos The position to retrieve the node 

	@return A pointer to the returned node, NULL if none found.

*/
Node* GetNode(Node* pHead,int pos);


/**
	Removes a node from the list at a specified position.Request to remove the 0th 
	node will have no effect.

	@param pHead A pointer to head of the list
	@param pos An integer corresponding to the index of the node to be removed within the list. Indices begin at zero.

	@return The removed node. It is the responsibility of the caller to deallocate the object.NULL will be returned incase of
	invalid index passed.
*/
Node* RemoveNode(Node* pHead,int pos);

/**
	Deletes a node in the list at the specified position.This will remove the node from the list and also deallocate the
	object.

	@param pHead A pointer to head of the linked list.
	@param pos The position of the node to be deleted.
*/
void DeleteNode(Node* pHead,int pos);


/**
	Deletes a node in the list with the same address as the passed pointer.

	@param pHead A pointer to the head of the linked list.
	@param pNode A pointer to the node to be deleted.
*/
void DeleteNode(Node* pHead,Node* pNode);

/**
	A recursive implementation of reversing the linked list.

	@param pHead A pointer to the head of the linked list (or the remainder of it in a recursive call)
	@param pPrev A pointer to the node preceding this node, will be NULL for head/initial call

	@return A pointer to the head of the reversed linked list.

*/
Node* RecursiveReverse(Node* pHead,Node* pPrev);


/**
	Iterative implementation of the singly linked list reverse

	@param pHead A pointer to the head of the linked list.

	@return A pointer to the head of the reversed linked list
*/
Node* ReverseList(Node* pHead);

/**
	Swap two nodes withing the linked list.

	@param pHead A pointer to the linked list head
	@param pNodeA One node to swap.
	@param pNodeB The other node to swap with

	@return Pointer to the head of the new linked list
*/
Node* SwapNodes(Node* pHead, Node* pNodeA,Node* pNodeB);



#endif