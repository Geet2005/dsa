include <stdio.h>
#include <math.h>

int binarySearch(int arr[], int n, int key, int *steps) {
    int low = 0, high = n - 1;

    while (low <= high) {
        (*steps)++; // count comparisons
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; // found
        else if (arr[mid] < key)
            low = mid + 1; // right half
        else
            high = mid - 1; // left half
    }

    return -1; // not found
}

int main() {
    int n, key, steps = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key, &steps);

    if (result != -1)
        printf("\nElement found at index %d\n", result);
    else
        printf("\nElement not found in array.\n");

    // Display analysis
    printf("\n--- Analysis ---\n");
    printf("Number of comparisons (steps): %d\n", steps);
    printf("Time Complexity (Worst Case): O(log n) ≈ O(log2(%d)) = %.2f\n", n, log2(n));
    printf("Space Complexity: O(1) (Iterative method uses constant memory)\n");

    return 0;
}
