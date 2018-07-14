#include<stdio.h>
#define MAXSIZE 100

//定义顺序表类型 
typedef struct{
    int key;
    int data;
}SqList[MAXSIZE], SortItem;

//选择排序 
void SelectionSort(SqList list, int n){
    int i, j, min;
    SortItem p;
    
    for(i = 0; i < n - 1; i++){
        min = i;
        
        //Find the minimum value in the unsorted list
        for(j = i + 1; j < n; j++){
            if(list[j].key < list[min].key)
                min = j;
        }

        //Exchange two value
        if(min != i){
            p = list[min];
            list[min] = list[i];
            list[i] = p;
        }
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


    SelectionSort(list, 7);

    PrintSort(list, 7);
}
