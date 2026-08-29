#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initialize(){
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while(hashTable[(index+i*i)%SIZE]!= -1) {
        i++;
        if (i==SIZE) {
            printf("Hash table is full!\n");
            return;
        }
    }
    int newIndex = (index + i * i) % SIZE;
    hashTable[newIndex] = key;
    printf("%d inserted at index %d\n", key, newIndex);
}

void display(){
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i]==-1)
            printf("[%d] \t Empty\n", i);
        else
            printf("[%d] \t %d\n", i, hashTable[i]);
    }
}

int main() {
    initialize();
    insert(72);
    insert(19);
    insert(64);
    insert(31);
    insert(81);
    display();
    return 0;
}
