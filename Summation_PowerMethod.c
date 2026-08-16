#include <stdio.h>

int power(int x,int n){
    int i, result = 1;
    for(i = 1; i <= n; i++)
        result = result * x;
    return result;
}

int sumSeries(int x,int n){
    int i, sum = 0;
    for(i = 0; i <= n; i++)
        sum = sum + power(x, i);
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
