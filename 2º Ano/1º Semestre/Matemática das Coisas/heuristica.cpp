//https://github.com/sth144/christofides-algorithm-cpp/blob/master/tsp.cpp

#include <iostream>
#include <vector>

using namespace std;



#define N 100

int graph[N][N] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };


void compute_shortestPath(int V) {
    vector<int> visited(V,0);

    vector<int> path(1,0);
    int current = 0;
    int count = 1;
    int cost = 0;

    visited[0] = 1;

    while(count < V) {
        int min = 1e9, index = -1;

        for(int i = 0; i < V; i++) {
            if(!visited[i] && graph[current][i] < min) {
                min = graph[current][i];
                index = i;
            }
        }
        cout << index << endl;
        visited[index] = 1;
        path.push_back(index);
        current = index;
        ++count;
        cost += min;
    }

    cost += graph[current][0];
    cout << "Percurso: " << endl;
    for(int i = 0; i < V; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "Custo: " << cost << endl;
}


int main() {
    compute_shortestPath(4);
    return 0;
}