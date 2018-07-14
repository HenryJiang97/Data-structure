#include<stdio.h>
#include<malloc.h>

//定义队 
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode, *LQueue;

//定义首尾指针（队类型） 
typedef struct{
    LQueue front;
    LQueue rear;
}LinkQueue;

//初始化 
LinkQueue InitQueue(){
    LinkQueue Q;

    Q.front = Q.rear = (LQueue) malloc (sizeof(QNode));
    Q.front->next = NULL;

    return Q;
}

//入队 
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

//出队 
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

//主函数 
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
