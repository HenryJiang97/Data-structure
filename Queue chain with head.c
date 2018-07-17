#include<stdio.h>
#include<malloc.h>
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode, *LQueue;

typedef struct{
    LQueue front;
    LQueue rear;
}LinkQueue;

LinkQueue InitQueue(){
    LinkQueue Q;

    Q.front = Q.rear = (LQueue) malloc (sizeof(QNode));
    Q.front->next = NULL;

    return Q;
}

void EnQueue(LinkQueue Q){
    LQueue p;
 
    while(1){
        //Create new node
        p = (LQueue) malloc (sizeof(QNode));
        printf("Input data(-1 to stop):");
        scanf("%d", &p->data);
        p->next = NULL;

        //Judge stop
        if(p->data == -1){
            free(p);
            break;
        }

        //Link queue
        Q.rear->next = p;
        Q.rear = p;
    }
}

int DeQueue(LinkQueue Q, int *p){
    LQueue s = Q.front->next;

    

    *p = s->data;
    Q.front->next = s->next;
    free(s);
}

void print(LinkQueue Q){
    LQueue find;

    find = Q.front->next;

    while(find != NULL){
        printf("%d  ", find->data);
        find = find->next;
    }
    printf("\n");
}

int main(){
    LinkQueue Q;
    int p, try;

    Q = InitQueue();
    
    EnQueue(Q);

    printf("\nThe queue is: ");
    try = DeQueue(Q, &p);
    print(Q);
    printf("\nThe data dequeued is: %d", p);

    return 0;
}