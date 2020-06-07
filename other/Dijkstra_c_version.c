#include <stdio.h>
#include <stdlib.h>

#define Maxint 32767
#define NOVERTEX -1
#define TRUE 1
#define FALSE 0

/*
* 输入：
    * 顶点个数n
    * 起点、终点（各为1~n中的一个数字）
    * 邻接矩阵（adjacent matrix），没有边则使用Maxint
*/

typedef struct TableEntry {
    int known;
    int pre_node;
    int dist;
}TableEntry;

int smallest_unknown_dis_vertex(int** adjacency, TableEntry* T, int num_of_vertex, int startp) {
    int ret_vertex = NOVERTEX, min = Maxint;
    for(int i=0;i<num_of_vertex;i++) {
        if(!T[i].known&&adjacency[startp][i]<min) {
            ret_vertex = i;
            min = adjacency[startp][i];
        }
    }
    return ret_vertex;
}

void print_path(int vertex, TableEntry* T) {
    if(T[vertex].pre_node!=NOVERTEX) {
        print_path(T[vertex].pre_node, T);
    }
    printf("%d ", vertex+1);
}

void Initialize_Dijkstra(int ***adjacency, TableEntry** T, int num_of_vertex, int startp) {
    // Create adjacency list

    printf("Input distance of each two vertex\n");
    *adjacency = (int** ) malloc(num_of_vertex*sizeof(int*));
    for(int i=0;i<num_of_vertex;i++) {
        (*adjacency)[i] = (int*) malloc(num_of_vertex*sizeof(int));
        for(int j=0;j<num_of_vertex;j++) {
            scanf("%d",&((*adjacency)[i][j]));
        }
    }

    // Initialize Table for Dijkstra
    *T = (TableEntry*) malloc(num_of_vertex*sizeof(TableEntry));
    for(int i=0;i<num_of_vertex;i++) {
        (*T)[i].known = FALSE;
        (*T)[i].dist = Maxint;
        (*T)[i].pre_node = NOVERTEX;
    }
    (*T)[startp].dist = 0;
}

void Dijkstra() {
    int num_of_vertex, startp, endp;
    int **adjacency;
    TableEntry* T;

    printf("Input the number of vertex:\n");
    scanf("%d", &num_of_vertex);
    printf("Input the starting point and endpoint:\n");
    scanf("%d %d", &startp, &endp);

    Initialize_Dijkstra(&adjacency, &T, num_of_vertex, startp-1);

    int v, w;
    for(;;) {
        v = smallest_unknown_dis_vertex(adjacency, T, num_of_vertex, startp-1);
        if(v==NOVERTEX) {
            break;
        }
        T[v].known = TRUE;
        for(w=0;w<num_of_vertex;w++) {
            if(!T[w].known) {
                if(T[v].dist+adjacency[v][w]<T[w].dist) {
                    T[w].dist = T[v].dist+adjacency[v][w];
                    T[w].pre_node = v;
                }
            }
        }
    }

    // Output
    print_path(endp-1, T);

    // Free
    free(T);
    for(int i=0;i<num_of_vertex;i++) {
        free(*(adjacency+i));
    }
}

int main() {
    Dijkstra();
    return 0;
}