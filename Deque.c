#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void insertFront(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = data;
    printf("Inserted %d at front\n", data);
}
void insertRear(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
    printf("Inserted %d at rear\n", data);
}
void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element: %d\n", deque[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}
void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element: %d\n", deque[rear]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, data;
    while (1) {
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            insertFront(data);
        } else if (choice == 2) {
            printf("Enter data: ");
            scanf("%d", &data);
            insertRear(data);
        } else if (choice == 3) {
            deleteFront();
        } else if (choice == 4) {
            deleteRear();
        } else if (choice == 5) {
            display();
        } else if (choice == 6) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
