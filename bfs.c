#include <stdio.h>

#define MAX 20 // Maximum number of vertices

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to add element to queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1; // Queue is empty
    return queue[front++];
}

// Breadth-First Search function
void bfs(int adj[MAX][MAX], int n, int start) {
    int i, current;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, adj[MAX][MAX], start;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}