#include<stdio.h>
#include<malloc.h>
#define MAXVEX 5
#define MAXARC 6

//定义边结点类型 
typedef struct arcnode{             //Edge node
    int adjvex;
    struct arcnode *next;
}ArcNode;

//定义顶点结点类型 
typedef struct vexnode{             //Head node
    char data;
    ArcNode *head;
}VexNode;

typedef VexNode ALGraph[MAXVEX];

//创建邻接表 
void CreateGraph(ALGraph g){
    int i, j, k;
    ArcNode *p;

    //Input vexs
    printf("Input vexs:");
    for(i = 0; i < MAXVEX; i++){
        scanf("%c", &g[i].data);
        g[i].head = NULL;
    }

    //Input edges
    for(k = 0; k < MAXARC; k++){
        printf("Please input edge info (i,j):");
        scanf("%d, %d", &i, &j);

        //Malloc and link new nodes to vexnodes
        p = (ArcNode *) malloc (sizeof(ArcNode));
        p->adjvex = j;
        p->next = g[i].head;
        g[i].head = p;
    }

}

//主函数 
int main(){
    ALGraph gc;

    CreateGraph(gc);

    return 0;
}

