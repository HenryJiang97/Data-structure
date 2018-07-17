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

    p = head->next->next;
    head->next->next = NULL;

    while(p != NULL){
        q = head;
        r = head->next;

        while((p->data > r->data) && (r->next != NULL)){
            q = q->next;
            r = r->next;
        }

        if(p->data <= r->data){
            //Link node
            q->next = p;
            p = p->next;
            q->next->next = r;
        }else{
            r->next = p;
            p = p->next;
            r->next->next = NULL;
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