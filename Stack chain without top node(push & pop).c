#include<stdio.h>
#include<malloc.h>

typedef struct SNode{
    int data;
    struct SNode *next;
}SNode, *LinkStack;

LinkStack initStack(){
    LinkStack top;

    top = (LinkStack) malloc (sizeof(SNode));
    printf("Input the data(-1 to stop):");
    scanf("%d", &top->data);
    top->next = NULL;
    

    return top;
}

LinkStack push(LinkStack *pTop){
    LinkStack s;

    while(1){
        //alloc
        s = (LinkStack) malloc (sizeof(SNode));

        //Data in
        printf("Input the data(-1 to stop):");
        scanf("%d", &s->data);

        //Judge stop
        if (s->data == -1){
            free(s);
            break;
        }

        //Link stack    
        s->next = *pTop;
        *pTop = s;
    }

}

int pop(LinkStack *pTop, int *p){
    LinkStack s;

    if(*pTop == NULL){
        printf("The stack is empty!");
        return 1;
    }
    s = *pTop;
    *pTop = s->next;

    *p = s->data;
    free(s);
}

void print(LinkStack top){
    LinkStack p;

    p = top;

    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    LinkStack top;
    int e, p;

    top = initStack();

    push(&top);

    e = pop(&top, &p);

    printf("\nThe stack is: ");
    print(top);

    printf("\nThe pop data is: %d", p);
    printf("\n");

    return 0;
}
