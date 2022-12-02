#include<iostream>
#include<cstdlib>

using namespace std;
typedef struct _node
{
	int data;
	struct _node *next;
}Node;

Node* init()
{
	Node* headNode = (Node*)malloc(sizeof(Node));
	headNode->next=NULL;
	return headNode;
}

Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(Node *headNode)
{
	Node* pMove = headNode->next;
	while (pMove!=NULL)
	{
		cout << pMove->data << " ";
		pMove = pMove->next;
	}
}

void insertNodeByHead(Node *headNode, int data)
{
	Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

void deleteNodeByAppoin(Node* headNode, int posdata)
{
	Node* posNode = headNode->next;
	Node* posNodeFront = headNode;
		while (posNode->data != posdata)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;
		}
		posNodeFront->next = posNode->next;                  
		free(posNode);
}

void deleteBypos(Node* headNode,int pos)
{
	Node* posNodeFront = headNode;
	Node* posNode = headNode->next;
	while (pos--)
	{
		posNode = posNode->next;
	}
	posNode->next = posNode->next->next;
}

int main()
{
	Node* list = createList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 3);
	insertNodeByHead(list, 4);
	deleteBypos(list,0);
	printList(list);	
	return 0;
}
