#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	int data;
	struct Node *next;
}LNode, *LinkList;

int main()
{
	LinkList p, q, head, find;
	int i;
	
	head = (LinkList) malloc (sizeof(LNode));
	head->next = NULL;
	
	p = head;
	
	for(i = 0; i < 5; i++){
		q = (LinkList) malloc (sizeof(LNode));
		printf("Input data:");
		scanf("%d", &(q->data));
		q->next = p;
		p = q;		
	}
	
	find = p;

	while(find->next != NULL){
		printf("%d\n", find->data);
		find = find->next;
	}
	
	return 0;
}
