#include<stdio.h>
#include<malloc.h>

#define LISTSIZE 100

//����˳���ṹ 
typedef struct {
	int items[LISTSIZE];
    int length;
}SqList;

//��ʼ�� 
void init(SqList *list){
    list->length = 0;
}

//���� 
int InsertList(SqList *list, int pos, int data){
    int i;

	//���������һλ��ǰ�ƣ�������λ�ú�����������ƶ�һλ 
    for(i = list->length - 1; i >= pos - 1; i--){
        list->items[i + 1] = list->items[i];
    }

	//�������� 
    list->items[pos - 1] = data;
    
    //˳����ȼ�һ 
    list->length++;
}

//ɾ�� 
int DeleteList(SqList *list, int pos, int *data){
    int i;

	//�Ƿ�����λ�� 
    if(pos < 1 || pos > list->length){
        printf("Invalid position");
        return 1;
    }
    
    //��¼��Ҫɾ�������� 
    *data = list->items[i - 1];

	//ǰ�����ݣ�������Ҫɾ�������� 
    for(i = pos; i < list->length; i++){
        list->items[i - 1] = list->items[i];
    }

    list->length--;
}

//��� 
void print(SqList *list){
    int i = 0;
    
    printf("\nThe list is:");

    while(i < list->length){
        printf("%d  ", list->items[i]);
        i++;
    }
}

//������ 
int main(){
    SqList list; 
    int position, data, tryI, tryD, d;

    init(&list);

    list.length = 4;
    list.items[0] = 1;
    list.items[1] = 2;
    list.items[2] = 3;
    list.items[3] = 4;


    //printf("Input the data:");
    //scanf("%d", &data);
    printf("Input the insert/delete position:");
    scanf("%d", &position);

    //tryI = InsertList(&list, position, data);

    tryD = DeleteList(&list, position, &d);
    print(&list);
    printf("Deleted item: %d",d);
}
