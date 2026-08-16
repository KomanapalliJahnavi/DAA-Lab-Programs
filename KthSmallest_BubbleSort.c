#include <stdio.h>
void sort(int a[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int kthSmallest(int a[], int n, int k){
    sort(a, n);
    return a[k - 1];
}

int main(){
    int a[100], n, k, i, result;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    result = kthSmallest(a, n, k);
    printf("Kth smallest element = %d\n", result);
    return 0;
}
