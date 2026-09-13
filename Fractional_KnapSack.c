#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main(){
    struct Item item[100];
    int n, capacity;
    int i, j;
    struct Item temp;
    float totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++){
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio =(float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (item[i].ratio < item[j].ratio){
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++){
        if (capacity >= item[i].weight){
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else{
            totalProfit = totalProfit +
                item[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}
