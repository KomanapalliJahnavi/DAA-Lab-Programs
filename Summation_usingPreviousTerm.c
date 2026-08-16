#include <stdio.h>

int sumSeries(int x, int n){
    int i,sum = 0,term = 1;
    for(i = 0; i <= n; i++){
        sum = sum + term;
        term = term * x;
    }
    return sum;
}

int main(){
    int x, n, sum;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    sum = sumSeries(x, n);
    printf("Sum = %d", sum);
    return 0;
}
