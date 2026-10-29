#include<stdio.h>

int max(int a, int b){
    int max=a>b ? a : b;
    return max;
}

int main(){
    int n,W,i,w;
    printf("Enter Number of Items:");
    scanf("%d",&i);
    int wt[n], val[n];
    printf("Enter Weight of Items:");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Enter Value of Items:");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Enter Knapsack Capacity:");
    scanf("%d",&W);

    int dp[n+1][w+1];
    for(i=0;i<n;i++){
        for(w=0;w<W; w++){
            if(i==0 || w==0)
                dp[i][w]=0;
        else if(wt[i-1]<=w){
            dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i - 1][w]);
        }
        else
            dp[i][w] = dp[i - 1][w];
        }
    }
}