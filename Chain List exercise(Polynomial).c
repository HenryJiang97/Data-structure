#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int coefficient;
    int index;
    struct Node *next;
}LNode, *LinkList;

//Initialization
LinkList initList(){
    LinkList head;

    head = (LinkList) malloc (sizeof(LNode));

    head->next = NULL;
    return head;
}

void constructList(LinkList head, int judge){
	LinkList p, q;
	int idx = 0;

	p = head;
	
	while (1){
		q = (LinkList) malloc (sizeof(LNode));
		printf("Input the coefficient of X^%d (-1 to stop):", idx);
		scanf("%d", &(q->coefficient));
        q->index = idx;
        idx++;

        //Judge if is the last element
        if (q->coefficient == -1){
            printf("\n");
            if (judge == 1){
                printf("Enter the second polynomial:\n");
            }               
            break;
        }

        //Link
		q->next = NULL;
		p->next = q;
		p = q;
	}
}

void printList(LinkList head){
	LinkList find;
	
	find = head->next;
	
	while(find != NULL){
        //Index = 0
        if(find->index == 0){
            //Index = 0 (Last node)
            if(find->next == NULL){
                printf("%d", find->coefficient);
            }else{
                //Index = 0 (Not the last node)
                printf("%d + ", find->coefficient);
            }
        }else if(find->index == 1){
            //Index = 1 (Last node)
            if(find->next == NULL){
                printf("%dX", find->coefficient);
            }else{
                //Index = 1 (Not the last node)
                printf("%dX + ", find->coefficient);
            } 
        }else{
            //Last node
            if(find->next == NULL){
                printf("%dX^%d", find->coefficient, find->index);
            }else{
                //Not the last node
                printf("%dX^%d + ", find->coefficient, find->index);
            } 
        }

		find = find->next;
	}
	printf("\n");
}


LinkList addingPoly(LinkList head1, LinkList head2, LinkList head3){
    LinkList p = head1->next;
    LinkList q = head2->next;
    LinkList r = head3;
    LinkList v;

    //When both polynomial are not at the end
    while((p != NULL) && (q != NULL)){
        //Create new node
        v = (LinkList) malloc (sizeof(LNode));
        v->coefficient = p->coefficient + q->coefficient;
        v->index = p->index;
        v->next = NULL;
        //Link node
        r->next = v;
        r = v;

        //p,q move forward
        p = p->next;
        q = q->next;
    }

    //Judge which chain is shorter
    if(p == NULL){
        while(q != NULL){
            //Create new node
            v = (LinkList) malloc (sizeof(LNode));
            v->coefficient = q->coefficient;
            v->index = q->index;
            v->next = NULL;
            //Link nodes
            r->next = v;
            r = v;
            //q move forward
            q = q->next;
        }    
    }else{
        while(p != NULL){
            v = (LinkList) malloc (sizeof(LNode));
            v->coefficient = p->coefficient;
            v->index = p->index;
            v->next = NULL;
            //Link nodes
            r->next = v;
            r = v;
            //p move forward
            p = p->next;
        }
    }

    return head3;
}

int main(){

    LinkList head1, head2, head3;
    head1 = initList();
    head2 = initList();
    head3 = initList();

    printf("Input the first polynomial:\n");
    constructList(head1, 1);
    constructList(head2, 0);

    head3 = addingPoly(head1, head2, head3);

    printf("The first polynomial:\n");
    printList(head1);
    printf("\n");
    printf("The second polynomial:\n");
    printList(head2);
    printf("\n");
    printf("Sum of two polynomial:\n");
    printList(head3);

    return 0;
}