#include <stdio.h>
int bubbleSteps = 0, insertionSteps = 0, quickSteps = 0, mergeSteps = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            bubbleSteps++;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                bubbleSteps++;
            }
        }
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            insertionSteps++;
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                insertionSteps++;
                j--;
            } else
                break;
        }
        arr[j+1] = key;
        insertionSteps++;
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        quickSteps++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            quickSteps++;
        }
    }
    swap(&arr[i+1], &arr[high]);
    quickSteps++;
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m+1+i];
    int i=0, j=0, k=l;
    while (i < n1 && j < n2) {
        mergeSteps++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            mergeSteps++;
        } else {
            arr[k++] = R[j++];
            mergeSteps++;
        }
    }
    while (i < n1) arr[k++] = L[i++], mergeSteps++;
    while (j < n2) arr[k++] = R[j++], mergeSteps++;
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void copyArray(int src[], int dest[], int n) {
    for (int i=0;i<n;i++)
        dest[i] = src[i];
}
void printArray(int arr[], int n) {
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], arrBubble[n], arrInsertion[n], arrQuick[n], arrMerge[n];
    printf("Enter %d elements: ", n);
    for (int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    copyArray(arr, arrBubble, n);
    copyArray(arr, arrInsertion, n);
    copyArray(arr, arrQuick, n);
    copyArray(arr, arrMerge, n);
    bubbleSort(arrBubble, n);
    printf("\nBubble Sort: ");
    printArray(arrBubble, n);
    printf("Steps: %d\n", bubbleSteps);
    insertionSort(arrInsertion, n);
    printf("\nInsertion Sort: ");
    printArray(arrInsertion, n);
    printf("Steps: %d\n", insertionSteps);
    quickSort(arrQuick, 0, n-1);
    printf("\nQuick Sort: ");
    printArray(arrQuick, n);
    printf("Steps: %d\n", quickSteps);
    mergeSort(arrMerge, 0, n-1);
    printf("\nMerge Sort: ");
    printArray(arrMerge, n);
    printf("Steps: %d\n", mergeSteps);
    return 0;
}
