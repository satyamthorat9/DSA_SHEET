// //*****************Graph****************** */
// #include <stdio.h>

// #define MAX 10

// int main() {
//     int adj[MAX][MAX];
//     int n, edges;
//     int i, j, u, v;

//     printf("Enter number of vertices: ");
//     scanf("%d", &n);

//     // Initialize adjacency matrix to 0
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < n; j++) {
//             adj[i][j] = 0;
//         }
//     }

//     printf("Enter number of edges: ");
//     scanf("%d", &edges);

//     printf("Enter edges (u v):\n");
//     for(i = 0; i < edges; i++) {
//         scanf("%d %d", &u, &v);
//         adj[u][v] = 1;   // Directed graph
//     }

//     // Display adjacency matrix
//     printf("\nAdjacency Matrix:\n");
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < n; j++) {
//             printf("%d ", adj[i][j]);
//         }
//         printf("\n");
//     }

//     // Calculate indegree and outdegree
//     printf("\nVertex\tIndegree\tOutdegree\tTotal Degree\n");

//     for(i = 0; i < n; i++) {
//         int indegree = 0, outdegree = 0;

//         for(j = 0; j < n; j++) {
//             outdegree += adj[i][j];   // Row sum
//             indegree += adj[j][i];    // Column sum
//         }

//         printf("%d\t%d\t\t%d\t\t%d\n", i, indegree, outdegree, indegree + outdegree);
//     }

//     return 0;
// }

#include<stdio.h>
int main(){
    int adj[10][10];
    int i, j, u, v, n, edges;
    printf("\nHow many  vertices :");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }
    //input edges
    printf("How many edges :\n");
    scanf("%d",&edges);
    printf("Enter edges as (u v) :\n");
    for(i = 0; i < edges; i++){
        scanf("%d %d",&u, &v);
        adj[u][v] = 1;
    }
    //display adjacency matrix
    printf("Adjacency matrix :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    //calculate indegree, outdegree, totaldegree
    printf("\nVertex\tIndegree\tOutdegree\tTotalDegree\n");
    for(i = 0; i < n; i++){
        int indegree = 0, outdegree = 0;
        for(j = 0; j < n; j++){
            outdegree += adj[i][j];
            indegree += adj[j][i];
        }
        printf("\n%d\t%d\t\t%d\t\t%d",i,indegree, outdegree, indegree+outdegree);
    }
    return 0;
}