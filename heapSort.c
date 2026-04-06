#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (to maintain max heap)
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // Move root to end
        heapify(arr, i, 0);       // Heapify reduced heap
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random numbers
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;   // random numbers (0–99)
    }

    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Perform Heap Sort
    heapSort(arr, n);

    printf("\n\nSorted Array (Heap Sort):\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}