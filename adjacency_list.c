#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(){
    int adj[10][10];
    struct node* list[10];

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
        struct node *p = (struct node*)malloc(sizeof(struct node));
        p->data = v;
        p->next = list[u];
        list[u] = p;
    }

    // display adjacency list
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++){
        printf("%d -> ", i);
        struct node *temp = list[i];
        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
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

    // calculate degree
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