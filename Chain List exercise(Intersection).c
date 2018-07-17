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

void function_C(LinkList head_A, LinkList head_B, LinkList head_D){
    LinkList p, q, i, j;

    p = head_A;
    i = head_D;

    while (p != NULL){
        q = head_B;

        //Try to test if there are elements common in two lists
        while(q != NULL){
            if (p->data == q->data){
                j = (LinkList) malloc (sizeof(LNode));
                j->data = p->data;

                //Link to List D
                i->next = j;
                j->next = NULL;
                i = j;
            }

            q = q->next;
        }

        p = p->next;
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
    LinkList head_A, head_B, head_D;

    head_A = initList();
    head_B = initList();
    head_D = initList();

    constructList(head_A, 1);
    constructList(head_B, 0);

    printList(head_A);
    printList(head_B);
    printf("\n");

    function_C(head_A, head_B, head_D);
    printList(head_D->next);

    return 0;
}