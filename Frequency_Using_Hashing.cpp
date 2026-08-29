#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];
int frequency[SIZE];

void initialize(){
    for(int i = 0;i<SIZE;i++) {
        hashTable[i]=-1;
        frequency[i]=0;
    }
}

void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != -1 && hashTable[index] != key){
        index=(index + 1) % SIZE;
    }
    if(hashTable[index] == key)
        frequency[index]++;
    else{
        hashTable[index] = key;
        frequency[index] = 1;
    }
}

void display() {
    printf("\nElement\tFrequency\n");
    for (int i = 0;i<SIZE;i++) {
        if(hashTable[i] != -1)
            printf("%d\t%d\n", hashTable[i], frequency[i]);
    }
}

int main() {
    int n, a[50];
    initialize();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    display();
    return 0;
}
