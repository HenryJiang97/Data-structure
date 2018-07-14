#include<stdio.h>
#include<malloc.h>

#define LISTSIZE 100

//定义顺序表结构 
typedef struct {
	int items[LISTSIZE];
    int length;
}SqList;

//初始化 
void init(SqList *list){
    list->length = 0;
}

//插入 
int InsertList(SqList *list, int pos, int data){
    int i;

	//从数组最后一位往前推，将插入位置后的数据往后移动一位 
    for(i = list->length - 1; i >= pos - 1; i--){
        list->items[i + 1] = list->items[i];
    }

	//插入数据 
    list->items[pos - 1] = data;
    
    //顺序表长度加一 
    list->length++;
}

//删除 
int DeleteList(SqList *list, int pos, int *data){
    int i;

	//非法插入位置 
    if(pos < 1 || pos > list->length){
        printf("Invalid position");
        return 1;
    }
    
    //记录需要删除的数据 
    *data = list->items[i - 1];

	//前移数据，覆盖需要删除的数据 
    for(i = pos; i < list->length; i++){
        list->items[i - 1] = list->items[i];
    }

    list->length--;
}

//输出 
void print(SqList *list){
    int i = 0;
    
    printf("\nThe list is:");

    while(i < list->length){
        printf("%d  ", list->items[i]);
        i++;
    }
}

//主函数 
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
