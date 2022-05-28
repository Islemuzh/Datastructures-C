#include <stdio.h>
#include  <stdlib.h>

//Own implementation of BFS, not sure if it works
//Tried using arrays for color, dist and pred
//Graph is given as matrix, where 1 means there is an edge and 0 means there is none

//Queue and its functions are not implemented

void BFS(int G[][], int s) {
    int color[3] = {0, 0, 0}; // White = 0; Gray = 1; Black = 2;
    int dist[3] = {1000, 1000, 1000};
    int pred[3] = {NULL, NULL, NULL};

    color[s] = 1;
    dist[s] = 0;
    enqueue(Q, s);
    while (!isEmpty(Q)) {
        int v = deque(Q);
        for (int i = 0; i < 3; i++) {
            if (G[v][i] == 1) {
                if (color[i] == 0) {
                    color[i] = 1;
                    dist[i] = dist[v] + 1;
                    pred[i] = v;
                    enqueue(Q, i);
                }
            }
        }
        color[v] = 2;
    }
}

int main() {
    int G[3][3] = {
        {0, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
        };

    BFS(G, 0);

    return 0;
}