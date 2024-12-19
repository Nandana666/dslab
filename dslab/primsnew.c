#include <stdio.h>
#include <stdlib.h>

int a, b, u, v, n, i, j, ne = 1;
int min, mincost = 0;
int **cost, *visited;

void main() {
    printf("\nPRIMS ALGM");
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the adjacency matrix and visited array
    cost = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        cost[i] = (int *)malloc(n * sizeof(int));
    }
    visited = (int *)malloc(n * sizeof(int));

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {  // Start from 0
        for (j = 0; j < n; j++) {  // Start from 0
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Represent no edge with a large value
            }
        }
    }

    // Initialize the visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[0] = 1; // Start from the first node (index 0)
    printf("\n");

    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {  // Start from 0
            for (j = 0; j < n; j++) {  // Start from 0
                if (cost[i][j] < min && visited[i] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as used
    }

    printf("\n\nMinimum cost: %d\n", mincost);

    // Free dynamically allocated memory
    for (i = 0; i < n; i++) {
        free(cost[i]);
    }
    free(cost);
    free(visited);
}
