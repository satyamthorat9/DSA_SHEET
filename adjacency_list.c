
//Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency list.
//Display the adjacency matrix. Calculate indegree, outdegree and total degree of each vertex.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int v;
    struct node *next;
};

int main(){
    int adj[10][10];
    struct node* list[10];   // adjacency list

    int i, j, u, v, n, edges;

    printf("\nHow many vertices : ");
    scanf("%d",&n);

    // initialize
    for(i = 0; i < n; i++){
        list[i] = NULL;
        for(j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }

    // input edges
    printf("How many edges : ");
    scanf("%d",&edges);

    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++){
        scanf("%d %d",&u, &v);

        // adjacency matrix
        adj[u][v] = 1;

        // adjacency list
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->v = v;
        temp->next = list[u];
        list[u] = temp;
    }

    // display adjacency list
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++){
        printf("%d -> ", i);
        struct node *t = list[i];
        while(t){
            printf("%d ", t->v);
            t = t->next;
        }
        printf("\n");
    }

    // display adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    // calculate degrees
    printf("\nVertex\tIndegree\tOutdegree\tTotalDegree\n");
    for(i = 0; i < n; i++){
        int indegree = 0, outdegree = 0;

        for(j = 0; j < n; j++){
            outdegree += adj[i][j];
            indegree += adj[j][i];
        }

        printf("%d\t%d\t\t%d\t\t%d\n",i,indegree,outdegree,indegree+outdegree);
    }

    return 0;
}