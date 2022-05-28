#include <stdio.h>
#include <stdlib.h>

int col[3] = {0, 0, 0}; // White = 0; Gray = 1; Black = 2;
int stime[3] = {0, 0, 0};
int etime[3] = {0, 0, 0};
int pred[3] = {NULL, NULL, NULL};
int time = 0;


void DFS_Tree(int G[][], int s) {
    col[s] = 1;
    stime[s] = time + 1;
    for (int i = 0; i < 3; i++) {
        if (G[s][i] == 1) {
            if (col[i] == 0) {
                pred[i] = s;
                DFS_Tree(G, i);
            }
        }
    }
    col[s] = 2;
    etime[s] = time + 1;
}

void DFS(int G[][]) {
    for (int i = 0; i < 3; i++) {
        if (col[i] == 0) {
            DFS_Tree(G, i);
        }
    }
}


int main() {

    int G[3][3] = {
        {0, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
        };

    DFS(G);

    return 0;
}