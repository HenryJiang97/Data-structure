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

void constructList(LinkList head, int judge){
	LinkList p, q;
	
	p = head;
	
	while (1){
		q = (LinkList) malloc (sizeof(LNode));
		printf("Input data (0 to stop):");
		scanf("%d", &(q->data));
        if (q->data == 0){
            printf("\n");
            if (judge == 1){
                printf("Enter the next list\n");
            }               
            break;
        }
		q->next = NULL;
		p->next = q;
		p = q;
	}
}




void printList(LinkList head){
	LinkList find;
	
	find = head->next;
	
	while(find != NULL){
		printf("%d  ", find->data);
		find = find->next;
	}
	printf("\n");
}


int main(){
    LinkList head_A, head_B;

    head_A = initList();
    head_B = initList();

    constructList(head_A, 1);
    constructList(head_B, 0);

    printList(head_A);
    printList(head_B);
    printf("\n");

    return 0;
}