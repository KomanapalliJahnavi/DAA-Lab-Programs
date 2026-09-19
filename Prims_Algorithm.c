#include <stdio.h>

int main(){
    int n, i, j, edges = 0;
    int min, x, y, total = 0;
    int cost[10][10];
    int visited[10] = {0};
    printf("Enter Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter Cost Matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[0] = 1;
    printf("Edges of MST:\n");
    while(edges < n - 1){
        min = 999;
        for(i = 0; i < n; i++){
            if(visited[i] == 1){
                for(j = 0; j < n; j++){
                    if(visited[j] == 0 && cost[i][j] < min){
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d = %d\n", x, y, min);
        total = total + min;
        visited[y] = 1;
        edges++;
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}
