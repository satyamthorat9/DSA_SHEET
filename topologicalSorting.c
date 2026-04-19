// #include <stdio.h>

// int a[10][10], v[10], s[10], top = -1, n;

// void dfs(int i) {
//     v[i] = 1;
//     for (int j = 0; j < n; j++)
//         if (a[i][j] && !v[j])
//             dfs(j);
//     s[++top] = i;
// }

// int main() {
//     int i, j;

//     printf("Enter number of vertices: ");
//     scanf("%d", &n);

//     printf("Enter adjacency matrix:\n");
//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             scanf("%d", &a[i][j]);

//     for (i = 0; i < n; i++)
//         if (!v[i])
//             dfs(i);

//     printf("Topological Order: ");
//     while (top >= 0)
//         printf("%d ", s[top--]);

//     return 0;
// }


#include<stdio.h>
int main(){
    int i, j, n, indegree[10], flag[10];
    int a[10][10], count = 0;
    printf("How many vertices :");
    scanf("%d",&n);
    printf("Enter the adjacency matrix :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("The adjacency matrix is :\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d    ", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < n; i++){
        indegree[i] = 0;
        flag[i] = 0;
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            indegree[i] = indegree[i]+a[j][i];
    printf("The Topological Order is :\n");
    while(count < n){
        for(int k = 0; k < n; k++){
            if(indegree[k]== 0 && flag[k] == 0){
                printf("%d    ", k);
                flag[k] = 1;
            }
            for( i = 0; i < n; i++){
                if(a[i][k] == 1)
                    indegree[k]--;
            }
        }
        count ++;
    }
    return 0;
}