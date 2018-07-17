#include<stdio.h>
#define LISTSIZE 50

//Define element type
typedef struct{
    int key;
}DataType;

//Define list type
typedef struct{
    int items[LISTSIZE];
    int length;
}SqList;


int BinarySearch(SqList L, DataType k){
    int low = 0;
    int high = L.length - 1;
    int mid;
    int loop = 0;

    while(low <= high){
        mid = (low + high) / 2;
        printf("%d\n", mid);
        loop++;
        printf("Loop:%d\n", loop);

        //Success
        if (L.items[mid] == k.key){
            return loop;
        }

        //Else
        if (L.items[mid] < k.key)
            low = mid + 1;
        else
            high = mid - 1;

    }

    return -1;
}


int main(){
    SqList list;
    DataType k;
    int runtime;

    int i;
    list.items[0] = 1;
    list.items[1] = 3;
    list.items[2] = 9;
    list.items[3] = 12;
    list.items[4] = 32;
    list.items[5] = 41;
    list.items[6] = 45;
    list.items[7] = 62;
    list.items[8] = 75;
    list.items[9] = 77;
    list.items[10] = 82;
    list.items[11] = 95;
    list.items[12] = 100;

    list.length = 13;

    k.key = 82;

    runtime = BinarySearch(list, k);
    printf("\nThe run time is:%d", runtime);
}
