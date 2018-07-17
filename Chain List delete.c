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

int DeleteList(LinkList head){
    int position;
    LinkList p = head, s;
    int i = 0;

    printf("Input the delete position:");
    scanf("%d", &position);

    while((p->next != NULL) && (i < position - 1)){
        p = p->next;
        i++;
    }

    if((p->next == NULL) || (i > position - 1)){
        printf("Wrong position!\n");
        return 0;
    }

    s = p->next;
    p->next = s->next;
    free(s);
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
	int length, try;
	LinkList head;

    //Create list
	head = initList();

	printf("Input the length of the list:");
	scanf("%d", &length);

	constructList(head, length);

    //Delete
	try = DeleteList(head);

    //Print
	printList(head);
	
	return 0;
}
