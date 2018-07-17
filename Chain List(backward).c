#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	int data;
	struct Node *next;
}LNode, *LinkList;


LinkList initList(void){
	LinkList head;
	
	head = (LinkList) malloc (sizeof(LNode));
	head->next = NULL;
	
	return head;
}

void constructList(LinkList head, int length){
	int i;
	LinkList p, q;
	
	p = head;
	
	for(i = 0; i < length; i++){
		q = (LinkList) malloc (sizeof(LNode));
		printf("Input data:");
		scanf("%d", &(q->data));
		q->next = NULL;
		p->next = q;
		p = q;
	}
}

int insertList(LinkList head, int val, int pos){
	LinkList p = head, q;
	int i = 0;

	while(p && i < pos - 1){
		p = p->next;
		i++;
	}

	//Judgement
	if(!p || i > pos - 1){
		printf("Unavailable postion\n");
		return 0;
	}

	q = (LinkList) malloc (sizeof (LNode));
	q->data = val;
	q->next = p->next;
	p->next = q;
}

void printList(LinkList head){
	LinkList find;
	
	find = head->next;
	
	while(find->next != NULL){
		printf("%d  ", find->data);
		find = find->next;
	}
	printf("%d\n", find->data);
}

int main()
{
	int length, value, postion, judge;
	LinkList head;

	head = initList();

	printf("Input the length of the list:");
	scanf("%d", &length);

	constructList(head, length);

	printf("Input the new data:");
	scanf("%d", &value);
	printf("Input the postion:");
	scanf("%d", &postion);

	judge = insertList(head, value, postion);

	printList(head);
	
	return 0;
}
