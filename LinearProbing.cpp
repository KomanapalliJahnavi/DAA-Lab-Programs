#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initialize(){
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key){
    int index = key % SIZE;
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
    printf("%d inserted at index %d\n", key, index);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] \t Empty\n", i);
        else
            printf("[%d] \t %d\n", i, hashTable[i]);
    }
}

int main() {
    int key;
    initialize();
    insert(56);
    insert(19);
    insert(77);
    insert(12);
    insert(34);
    display();
    return 0;
}

