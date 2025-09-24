#include <stdio.h>
#define MAX 11
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = data;
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front++]);
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("Dispalying %d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
        } else if (choice == 2) {
            if (front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Dequeued element: %d\n", queue[front++]);
            }
        } else if (choice == 3) {
            if (front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        } else if (choice == 4) {
            return 0;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
