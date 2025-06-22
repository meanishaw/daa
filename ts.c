#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int V, E;             // Number of vertices and edges

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v; // Push vertex to stack after visiting all adjacent nodes
}

void topologicalSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (format: from to):\n", E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed edge from u to v
    }

    topologicalSort();

    return 0;
}
