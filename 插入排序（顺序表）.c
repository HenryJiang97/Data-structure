#include<stdio.h>
#define MAXSIZE 100

//定义顺序表类型 
typedef struct{
    int key;
    int data;
}SqList[MAXSIZE], SortItem;

//插入排序 
void InsertSort(SqList list, int n){
    int i, j;
    SortItem p;

    for(i = 1; i < n; i++){
        p = list[i];

        for(j = i - 1; j >= 0 && list[j].key > p.key; j--){
            list[j + 1] = list[j]; 
        }

        list[j + 1] = p;
    }
}


void PrintSort(SqList list, int n){
    int i;
    
    for(i = 0; i < n; i++){
        printf("%d ", list[i].key);
    }
}

//主函数 
int main(){
    SqList list;

    list[0].key = 49;
    list[1].key = 38;
    list[2].key = 65;
    list[3].key = 97;
    list[4].key = 76;
    list[5].key = 13;
    list[6].key = 27;


    InsertSort(list, 7);

    PrintSort(list, 7);
}
