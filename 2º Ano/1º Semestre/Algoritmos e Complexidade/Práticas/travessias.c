#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NV 10


typedef struct aresta {
int dest; int custo;
struct aresta *prox;
} *LAdj, *GrafoL [NV];


typedef int GrafoM [NV][NV];


//O(V+E)
void DFSColoring(GrafoL g, int vertex, int c[], int color) {
    c[vertex] = color;

    LAdj adj = g[vertex]->prox;

    while(adj) {
        if(c[adj->dest] == 0) {
            DFSColoring(g, g[vertex]->dest, c, color);
        }
        adj = adj->prox;
    }
}

//O(V+E)
int componentes(GrafoL g, int c[]) {
    int components = 0;

    for(int i = 0; i < NV; i++) {
        c[i] = 0;
    }

    for(int i = 0; i < NV; i++) {
        if(c[i] == 0) {
            DFSColoring(g, i, c, ++components /*A ordem do ++ importa*/);
        }
    }
    return components;
}

//O(V+E)
int ordTopAux(GrafoL g, int vertex, int visited[], int ord[], int i) {
    LAdj adj = g[vertex]->prox;
    visited[vertex] = 1;
    while(adj) {
        if(!visited[g[vertex]->dest])
            i = ordTopAux(g, g[vertex]->dest, visited, ord, i);
        adj = adj->prox;
    }

    ord[i++] = vertex;
    return i;
}

//O(V+E)
int ordTop(GrafoL g, int ord[]) {
    int visited[NV];
    for(int i = 0; i < NV; i++)
        visited[i] = 0;

    int index = 0;
    for(int i = 0; i < NV; i++) {
        if(!visited[i]) {
            index = ordTopAux(g, i, visited, ord, index);
        }
    }

    //Inverte o array
    for(int i = 0; i < NV / 2; i++) {
        int temp = ord[i];
        ord[i] = ord[NV - 1 - i];
        ord[NV - 1 - i] = temp;
    }

    return index;
}

//O(V+E), Só funciona pq os pesos são todos iguais
//Se tivesses pesos diferentes tinha de ser Dijkstra (se nao tivesses pesos negativos) ou BelmannFord (se tivesses pesos negativos)
//DFS não funciona
int caminho(int L, int C, char* mapa[L], int ls, int cs, int lf, int cf) {

    int caminhos[L * C];
    int visited[L * C];
    int parent[L * C];
    int diff[4] = { -1, 1, -C, C};
    char movements[4] = {'L', 'R', 'U', 'D'};
    for(int i = 0; i < L * C; i++) {
        caminhos[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    int q[2 * NV * NV], front, end;

    front = end = 0;
    q[end++] = ls * C + cs; //enqueue
    visited[ls * C + cs] = 1;
    caminhos[ls * C + cs] = 0;
    int x;
    while(front != end) {
        x = q[front++]; //dequeue

        for(int i = 0; i < 4; i++) {
            if((x + diff[i] >= 0) && (x + diff[i] < L * C) && !visited[x + diff[i]]
                && (mapa[(x + diff[i]) / C][(x + diff[i]) % C] == ' ')) {
                printf("%d\n", x + diff[i]);
                visited[x + diff[i]] = 1;
                caminhos[x + diff[i]] = caminhos[x] + 1;
                parent[x + diff[i]] = x;
                q[end++]= x + diff[i]; //enqueue
            }
        }
    }

    char path[L * C];
    int j = 0;
    x = lf * C + cf;
    while(x != ls * C + cs) {
        for(int i = 0; i < 4; i++) {
            if(diff[i] == x - parent[x]) {
                x = parent[x];
                path[j++] = movements[i];
                break;
            }
        }

    }
    for(int i = j - 1; i >= 0; i--)
        printf("%c", path[i]);

    printf("\n");

    return caminhos[lf * C + cf];
}


int main() {
    char *mapa [10] = {  "##########"
                        ,"# #   #  #"
                        ,"# # # #  #"
                        ,"#   # #  #"
                        ,"##### #  #"
                        ,"#     #  #"
                        ,"## ####  #"
                        ,"#  #     #"
                        ,"#     #  #"
                        ,"##########"};


    int c = caminho(10,10, mapa,1,1,1,8);

    printf("%d\n", c);

    return 0;
}