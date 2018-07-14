#include<stdio.h>

#define MAXVEX 5
#define MAXARC 6

typedef struct{
    int arcs[MAXVEX][MAXVEX];  //matrix info
    char vexs[MAXVEX];         //vertex info
}MGraph, *AdjMetrix;

//创建邻接矩阵 
AdjMetrix CreateGraph(AdjMetrix g){
    int i, j, k;

    //Input the info of vertex
    printf("Input the vertex info [i]:");
    for(i = 0; i < MAXVEX; i++){      
        scanf("%c", &g->vexs[i]);
    }
    
    //Initiate edge
    for(i = 0; i < MAXVEX; i++){
        for(j = 0; j < MAXVEX; j++){
            g->arcs[i][j] = 0;
        }
    }

    //Input edge info
    for(k = 0; k < MAXARC; k++){
        printf("Input the connected edge (i, j):");
        scanf("%d, %d", &i, &j);

        g->arcs[i][j] = 1;
        g->arcs[j][i] = 1;                //Non-derection undigraph
    }


    return g;
}

//深度遍历 
void DFSTraverse(AdjMetrix g, int i){
    static int visited[MAXVEX] = {0};
    int j;
    
    //Print and modify visited
    printf("%c ", g->vexs[i]);
    visited[i] = 1;

    for(j = 0; j < MAXVEX; j++){
        if((visited[j] == 0) && (g->arcs[i][j] == 1)){
            
            DFSTraverse(g, j);
        }
    }
}

//广度遍历 
void BFSTraverse(AdjMetrix g, int k){
    static int visited[MAXVEX];
    int i = 0;
    int j;

    //Init queue
    int q[MAXVEX] = {0};
    int front = 0;
    int rear = 0;

    //The first vexs
    printf("%c ", g->vexs[k]);
    visited[k] = 1;
    //Enqueue
    q[i] = k;
    rear++;

    //Loop
    while(!(front == rear)){
        //DeQueue
        i = q[front];
        front++;

        for(j = 0; j < MAXVEX; j++){
            if((visited[j] == 0) && (g->arcs[i][j] == 1)){
                printf("%c ", g->vexs[j]);
                visited[j] = 1;

                //EnQueue
                q[rear] = j;
                rear++;
            }
        }
    }
}

//主函数 
int main(){
    MGraph a;
    AdjMetrix g;

    g = CreateGraph(&a);

    printf("The DFS traverse is: ");
    DFSTraverse(g, 0);

    printf("\nThe BFS traverse is: ");
    BFSTraverse(g, 0);

    return 0;
}
