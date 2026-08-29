#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];

void initialize(){
    for(int i = 0;i <SIZE;i++)
        hashTable[i] = -1;
}

int main() {
    int n, T, a[50];
    int i, index, complement;
    initialize();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target T: ");
    scanf("%d", &T);
    
    for (i = 0; i < n; i++) {
        complement = T - a[i];
        index = complement % SIZE;
        if (index < 0)
            index += SIZE;
        if (hashTable[index] == complement) {
            printf("Yes, two elements exist: %d and %d\n",
                   complement, a[i]);
            return 0;
        }
        index = a[i] % SIZE;
        if (index < 0)
            index += SIZE;
        hashTable[index] = a[i];
    }
    printf("No, such two elements do not exist.\n");
    return 0;
}
