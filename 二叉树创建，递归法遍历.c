#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
}BTNode, *BiTreeLink, *PBTNode;

//创建二叉树 
BiTreeLink CreatBiTree(char *nodes, int pos, int num){
    PBTNode p;

    //Judge ending
    if(nodes[pos - 1] == '\0' || pos > num){
        return NULL;
    }

    //Create new root
    p = (PBTNode) malloc (sizeof(BTNode));
    if(!p){
        printf("Error to create binary tree!\n");
        return 0;
    }

    p->data = nodes[pos - 1];
    p->left = CreatBiTree(nodes, pos * 2, num);
    p->right = CreatBiTree(nodes, pos * 2 + 1, num);

    return p;
}

//先序遍历（递归法） 
void PreOrderTraverse(BiTreeLink p){
    if(p != NULL){
        if(p->data != '^'){
            printf("%c ", p->data);
        }

        PreOrderTraverse(p->left);
        PreOrderTraverse(p->right);
    }
}

//中序遍历（递归法） 
void InOrderTraverse(BiTreeLink p){
    if(p != NULL){
        InOrderTraverse(p->left);

        if(p->data != '^'){
            printf("%c ", p->data);
        }
        
        InOrderTraverse(p->right);
    }
}

//后序遍历（递归法） 
void PostOrderTraverse(BiTreeLink p){
    if(p != NULL){
        PostOrderTraverse(p->left);
        PostOrderTraverse(p->right);

        if(p->data != '^'){
            printf("%c ", p->data);
        }
    }
}

//主函数 
int main(){
    BiTreeLink r;
    char sign[7] = {'A', 'B', 'C', 'D', '^', '^', 'E'};

    r = CreatBiTree(sign, 1, 7);


    //Traverse
    printf("The pre order traverse of binary tree is:\n");
    PreOrderTraverse(r);
    printf("\n\n");

    printf("The in order traverse of binary tree is:\n");
    InOrderTraverse(r);
    printf("\n\n");

    printf("The post order traverse of binary tree is:\n");
    PostOrderTraverse(r);
    printf("\n\n");
}
