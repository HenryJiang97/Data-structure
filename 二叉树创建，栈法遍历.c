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

//先序遍历（栈方法） 
void PreOrderTraverse(BiTreeLink t){
    PBTNode p;
    PBTNode s[100] = {0};
    int top = 0;

    p = t;

    while(p || top){
        while(p != NULL){           
            if(p->data != '^'){
                printf("%c ", p->data);
            }
            
            s[top++] = p;
            p = p->left;
        }

        if(top > 0){
            p = s[--top];
            p = p->right;
        }
        
    }
}

//中序遍历（栈方法） 
void InOrderTraverse(BiTreeLink t){
    PBTNode p;
    PBTNode s[100] = {0};
    int top = 0;

    p = t;

    while(p || top){
        while(p != NULL){
            s[top++] = p;
            p = p->left;
        }

        if(top > 0){
            p = s[--top];

            if(p->data != '^'){
                printf("%c ", p->data);
            }

            p = p->right;
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
}
