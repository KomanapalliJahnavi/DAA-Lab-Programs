#include <stdio.h>

int main(){
    int a[10],bucket[10][10];
    int n,i,j,k,b,count[10];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements (0-99): ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i= 0;i<10;i++)
        count[i]=0;
    for(i=0;i<n;i++){
        b=a[i]/10;
        bucket[b][count[b]] = a[i];
        count[b]++;
    }
    for(i=0;i<10;i++){
        for(j=0;j<count[i]-1;j++){
            for(k=j+1;k<count[i];k++){
                if(bucket[i][j]>bucket[i][k]){
                    int temp=bucket[i][j];
                    bucket[i][j]=bucket[i][k];
                    bucket[i][k]=temp;
                }
            }
        }
    }
    k=0;
    for(i=0;i<10;i++){
        for(j=0;j<count[i];j++){
            a[k++]=bucket[i][j];
        }
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
