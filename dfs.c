// #include <stdio.h>

// #define MAX 10

// int adj[MAX][MAX], visited[MAX], queue[MAX];
// int n;

// // BFS function
// void bfs(int start) {
//     int front = 0, rear = 0;

//     queue[rear++] = start;
//     visited[start] = 1;

//     while (front < rear) {
//         int v = queue[front++];
//         printf("%d ", v);

//         for (int i = 0; i < n; i++) {
//             if (adj[v][i] == 1 && visited[i] == 0) {
//                 queue[rear++] = i;
//                 visited[i] = 1;
//             }
//         }
//     }
// }

// int main() {
//     int i, j, edges, u, v, start;

//     printf("Enter number of vertices: ");
//     scanf("%d", &n);

//     // initialize matrix
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             adj[i][j] = 0;

//     printf("Enter number of edges: ");
//     scanf("%d", &edges);

//     // input edges
//     for (i = 0; i < edges; i++) {
//         printf("Enter edge (u v): ");
//         scanf("%d %d", &u, &v);
//         adj[u][v] = 1;
//         adj[v][u] = 1;  // remove this line for directed graph
//     }

//     // initialize visited
//     for (i = 0; i < n; i++)
//         visited[i] = 0;

//     printf("Enter starting vertex: ");
//     scanf("%d", &start);

//     printf("BFS Traversal: ");
//     bfs(start);

//     return 0;
// }




// #include <stdio.h>

// #define MAX 10

// int adj[MAX][MAX], visited[MAX];
// int n;

// // DFS function
// void dfs(int v) {
//     printf("%d ", v);
//     visited[v] = 1;

//     for (int i = 0; i < n; i++) {
//         if (adj[v][i] == 1 && visited[i] == 0) {
//             dfs(i);
//         }
//     }
// }

// int main() {
//     int i, j, edges, u, v, start;

//     printf("Enter number of vertices: ");
//     scanf("%d", &n);

//     // initialize adjacency matrix
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             adj[i][j] = 0;

//     printf("Enter number of edges: ");
//     scanf("%d", &edges);

//     // input edges
//     for (i = 0; i < edges; i++) {
//         printf("Enter edge (u v): ");
//         scanf("%d %d", &u, &v);
//         adj[u][v] = 1;
//         adj[v][u] = 1;   // remove for directed graph
//     }

//     // 🔹 Print adjacency matrix
//     printf("\nAdjacency Matrix:\n");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             printf("%d ", adj[i][j]);
//         }
//         printf("\n");
//     }

//     // initialize visited array
//     for (i = 0; i < n; i++)
//         visited[i] = 0;

//     printf("\nEnter starting vertex: ");
//     scanf("%d", &start);

//     printf("DFS Traversal: ");
//     dfs(start);

//     return 0;
// }


#include<stdio.h>
int adj[20][20], visited[20], n, i;

void dfs(int v){
    printf("%d  ", v);
    visited[v] = 1;
    for(i = 0; i < n; i++){
        if(adj[v][i]==1 && visited[i] == 0){
            dfs(i);
        }
    }
}
int main(){
    int i, j, u, v, start, edges;
    printf("How many vertices:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }
    printf("How many edges :\n");
    scanf("%d",&edges);
    for(i = 0; i < edges; i++){
        printf("Enter edge as (u v) :");
        scanf("%d%d",&u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    printf("Adjacency Matrix :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }
    //initialise visited to 0
    for(i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("Enter starting vertex :\n");
    scanf("%d",&start);

    printf("DFS traversal : ");
    dfs(start);
    return 0;
}