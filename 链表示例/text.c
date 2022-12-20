#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
	int id;
	struct node *next;
}*pNode;

typedef struct FBresult{
	pNode Fresult;
	pNode Bresult;
}Result;

pNode CreatNode(int id)
{
	pNode newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	
	newnode->id = id;
	newnode->next = NULL;
	return newnode;
}


void ScanList(pNode head)
{
	pNode shift;
	for(shift = head; shift != NULL; shift = shift->next)
		printf("ID: %d\n",shift->id);
		
}

pNode FrontInsert(pNode head, pNode newnode)
{
	newnode->next = head;
	head = newnode;
	return head;
}

pNode BackInsert(pNode head, pNode newnode)
{	
	pNode shift;
	if( NULL == head)
		head = newnode;
	else{
		shift = head;
		while( NULL != shift->next){
			shift = shift->next;}
		shift->next = newnode;
	}
	return head;
}

Result CreatList(int length)
{
	pNode head = NULL, newnode1;
	pNode head2 = NULL, newnode2;
	srand((unsigned int)time(NULL));
	
	int number;
	Result ys;
	for(int i = 0; i < length; i++){
		number = rand()%100;
	
		printf("number: %d\n",number);
		newnode1 = CreatNode(number);
		newnode2 = CreatNode(number);

		head = FrontInsert(head,newnode1);
		head2 = BackInsert(head2,newnode2);
	}
	ys.Fresult = head;
	ys.Bresult = head2;
	
	return ys;

}

int main(int argc,char* argv[])
{
	if( 2 != argc){
		printf("Useage: %s size\n",argv[0]);
			exit(10);
	}
	
	Result ys;
	
	ys = CreatList(atoi(argv[1]));
  ScanList(ys.Fresult);
  ScanList(ys.Bresult);
	return 0;
}
