#include <stdio.h>
#define SIZE 10
int hash(int key) {
    return key % SIZE;
}
void insert(int hashTable[], int key) {
    int index = hash(key);
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}
void display(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d -> %d\n", i, hashTable[i]);
        else
            printf("Slot %d -> Empty\n", i);
    }
}
int main() {
    int hashTable[SIZE];
    int n, key;
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        insert(hashTable, key);
    }
    display(hashTable);
    return 0;
}
