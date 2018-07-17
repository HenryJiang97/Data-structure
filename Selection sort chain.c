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

void InsertSortChain(LinkList head){
    LinkList p, q, r;

    p = head;

    while(p->next->next != NULL){
        r = p->next;
        q = r->next;

        while(q->next != NULL){
            if(q->next->data < r->data)
                r = q;

            q = q->next;
        }
        
    }
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

    //Create list
	head = initList();

	printf("Input the length of the list:");
	scanf("%d", &length);

	constructList(head, length);

    InsertSortChain(head);

    //Print
	printList(head);
	
	return 0;
}