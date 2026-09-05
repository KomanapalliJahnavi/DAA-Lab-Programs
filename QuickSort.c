#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int start,int end){
    int i,pi = start;
    int pivot = a[end];
    for(i=start;i<end;i++){
        if(a[i]<pivot){
            swap(&a[i], &a[pi]);
            pi++;
        }
    }
    swap(&a[pi], &a[end]);
    return pi;
}

void quickSort(int a[],int start,int end){
    if (start < end){
        int pi = partition(a,start,end);
        quickSort(a,start,pi-1);
        quickSort(a,pi+1,end);
    }
}

int main(){
    int n,i,start,end;
    int a[10];
    printf("Enter Number of Elements of an Array: ");
    scanf("%d", &n);
    start = 0;
    end=n-1;
    printf("Enter Array Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Array Before Sorting is:\n");
    for (i = 0;i<n;i++)
        printf("%d ",a[i]);
    quickSort(a,start,end);
    printf("\nArray After Sorting is:\n");
    for (i = 0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
