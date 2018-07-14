#include<stdio.h>
#include<malloc.h>

//定义单链表 
typedef struct Node{
	int data;
	struct Node *next;
}LNode, *LinkList;

//初始化单链表 
LinkList initList(void){
	LinkList head;
	
	head = (LinkList) malloc (sizeof(LNode));
	head->next = NULL;
	
	return head;
}

//创建单链表 
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

//插入 
int insertList(LinkList head, int val, int pos){
	LinkList temp = head->next, q, p;
	int i = 0;

	while(temp && i < pos - 2){
		temp = temp->next;
		i++;
	}
	p = temp->next;

	//Judgement
	if(!p || i > pos - 1){
		printf("Unavailable postion\n");
		return 0;
	}

	q = (LinkList) malloc (sizeof (LNode));
	q->data = val;
	q->next = p;
	temp->next = q;
}

//删除 
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

//输出 
void printList(LinkList head){
	LinkList find;
	
	find = head->next;
	
	while(find->next != NULL){
		printf("%d  ", find->data);
		find = find->next;
	}
	printf("%d\n", find->data);
}

//主函数 
int main()
{
	int length, value, postion, judge;
	LinkList head;

	head = initList();

	printf("Input the length of the list:");
	scanf("%d", &length);

	constructList(head, length);

	printf("Input the new data:");
	scanf("%d", &value);
	printf("Input the postion:");
	scanf("%d", &postion);

	judge = insertList(head, value, postion);

	printList(head);
	
	return 0;
}
