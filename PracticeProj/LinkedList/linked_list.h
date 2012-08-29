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



#endif