#include<stdio.h>
#include<malloc.h>

typedef struct SNode{
    int data;
    struct SNode *next;
}SNode, *LinkStack;

LinkStack initStack(){
    LinkStack top;

    top = (LinkStack) malloc (sizeof(SNode));
    top->next = NULL;

    return top;
}

void push(LinkStack top){
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
        s->next = top->next;
        top->next = s;     
    }
}

int pop(LinkStack top, int *p){
    LinkStack s;

    if(top->next == NULL){
        printf("The stack is empty!");
        return 1;
    }
    s = top->next;
    top->next = s->next;

    *p = s->data;
    free(s);
}

void print(LinkStack top){
    LinkStack p;

    p = top->next;

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

    push(top);

    e = pop(top, &p);

    printf("\nThe stack is: ");
    print(top);

    printf("\nThe pop data is:%d", p);
    printf("\n");

    return 0;
}