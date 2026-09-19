#include <stdio.h>
int parent[20];

int find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

int main(){
    int n, e;
    int u[20], v[20], w[20];
    int i, j, temp;
    int a, b;
    int total = 0, count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++){
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    for(i = 0; i < n; i++){
        parent[i] = i;
    }
    for(i = 0; i < e - 1; i++){
        for(j = i + 1; j < e; j++){
            if(w[i] > w[j]){
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = u[i];
                u[i] = u[j];
                u[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    printf("Edges of MST:\n");
    for(i = 0; i < e; i++){
        a = find(u[i]);
        b = find(v[i]);
        if(a != b){
            printf("%d - %d = %d\n", u[i], v[i], w[i]);
            total = total + w[i];
            parent[a] = b;
            count++;
            if(count == n - 1)
                break;
        }
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}
