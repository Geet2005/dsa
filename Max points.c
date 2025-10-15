#include <stdio.h>

void sortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, k, i, sum = 0;
    int A[100];

    printf("Enter number of events: ");
    scanf("%d", &n);

    printf("Enter activity points for each event:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter the maximum number of events you can participate in (k): ");
    scanf("%d", &k);

    sortDescending(A, n);

    for (i = 0; i < k; i++)
        sum += A[i];

    printf("Maximum activity points you can earn = %d\n", sum);

    return 0;
}