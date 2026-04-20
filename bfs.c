#include <stdio.h>
int adj[20][20], visited[20];
int i, n;  // number of vertices

// Function for BFS traversal
void bfs(int start) {
    int queue[20], front = 0, rear = 0;

    // Mark start node as visited and enqueue
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges,i, j, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);
  
    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Remove this line for directed graph
    }

    printf("Adjacency Matrix :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}