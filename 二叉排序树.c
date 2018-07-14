#include<stdio.h>
#include<malloc.h>

//Define binary tree
typedef struct Node{
    int data;
    struct Node *left, *right;
}BSTNode, *BSTree;

//Define element type
typedef struct{
    int key;
}DataType;


//创建二叉排序树 
BSTree BSTCreate(){
    BSTree p, q, s, record;
    int insert_data;

    //Create the root node
    p = (BSTree) malloc (sizeof(BSTNode));

    printf("Please input the key of the node:");
    scanf("%d", &p->data);

    p->left = NULL;
    p->right = NULL;

    while(1){
        printf("Please input the key of the node:");
        scanf("%d", &insert_data);

        if(insert_data == -1){
            break;
        }else{
            //Search for insert position
            s = p;
            while(s != NULL){
                record = s;

                if(insert_data == s->data)
                    break;

                if(insert_data > s->data)
                    s = s->right;
                else
                    s = s->left;
            }

            //Create and link node
            q = (BSTree) malloc (sizeof(BSTNode));
            q->data = insert_data;
            q->left = NULL;
            q->right = NULL;

            if(insert_data > record->data)
                record->right = q;
            else
                record->left = q;
        }
    }

    return p;
}


//插入 
void BSTInsert(BSTree *r, DataType x){
    BSTree p, q;

    p = *r;

    //Search for the insert position
    while(p != NULL){
        q = p;                    //Record the last position of p

        if (p->data == x.key)     //Existed, do not insert
            return;

        if (p->data > x.key)
            p = p->left;
        else
            p = p->right;
    }

    //Create new node
    p = (BSTree) malloc (sizeof(BSTNode));
    p->data = x.key;
    p->left = NULL;
    p->right = NULL;

    //Insert
    if (q == NULL){                //If the tree is empty
        *r = p;
        return;
    }

    if (p->data > x.key){
        q->left = p;
    }else{
        q->right = p;
    }
}

//查找 
BSTNode *BSTSearch(BSTree r, DataType x){
    BSTree p;
    p = r;

    if (p == NULL)
        return NULL;

    while (p != NULL){
        if (p->data == x.key)
            return p;
        
        if (p->data > x.key)
            p = p->left;
        else
            p = p->right;
    }
    
    return NULL;
}

//测试代码，忽略即可 
void PreOrderTraverse(BSTree p){
    if(p != NULL){
        printf("%d ", p->data);

    PreOrderTraverse(p->left);
    PreOrderTraverse(p->right);
    }
}

//主函数 
int main(){
    BSTree p;

    p = BSTCreate();

    PreOrderTraverse(p);

    return 0;
}
