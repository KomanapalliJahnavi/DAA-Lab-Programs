#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low;
    int j;
    for(j = low; j < high; j++){
        if(a[j] < pivot){
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[high]);
    return i;
}

int kthSmallest(int a[], int low, int high, int k){
    int pos;
    if(low <= high){
        pos = partition(a, low, high);
        if(pos == k - 1)
            return a[pos];
        if(pos > k - 1)
            return kthSmallest(a, low, pos - 1, k);
        else
            return kthSmallest(a, pos + 1, high, k);
    }
    return -1;
}

int main(){
    int a[100], n, k, i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    result = kthSmallest(a, 0, n - 1, k);
    printf("%dth smallest element = %d", k, result);
    return 0;
}
