// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// // Function to swap two elements
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Heapify function (to maintain max heap)
// void heapify(int arr[], int n, int i) {
//     int largest = i;        // root
//     int left = 2*i + 1;     // left child
//     int right = 2*i + 2;    // right child

//     // If left child is larger
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child is larger
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);

//         // Recursively heapify affected subtree
//         heapify(arr, n, largest);
//     }
// }

// // Heap Sort function
// void heapSort(int arr[], int n) {
//     // Build max heap
//     for (int i = n/2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // Extract elements from heap
//     for (int i = n - 1; i > 0; i--) {
//         swap(&arr[0], &arr[i]);   // Move root to end
//         heapify(arr, i, 0);       // Heapify reduced heap
//     }
// }

// int main() {
//     int n, i;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     // Generate random numbers
//     srand(time(0));
//     for (i = 0; i < n; i++) {
//         arr[i] = rand() % 100;   // random numbers (0–99)
//     }

//     printf("\nOriginal Array:\n");
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);

//     // Perform Heap Sort
//     heapSort(arr, n);

//     printf("\n\nSorted Array (Heap Sort):\n");
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);

//     return 0;
// }




// #include <stdio.h>

// // Function to swap two elements
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Heapify function to maintain max heap
// void heapify(int arr[], int n, int i) {
//     int largest = i;        // Assume root is largest
//     int left = 2*i + 1;     // Left child
//     int right = 2*i + 2;    // Right child

//     // Check if left child is larger
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // Check if right child is larger
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If root is not largest, swap and heapify again
//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         heapify(arr, n, largest);
//     }
// }

// // Heap Sort function
// void heapSort(int arr[], int n) {
//     // Step 1: Build max heap
//     for (int i = n/2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // Step 2: Extract elements from heap
//     for (int i = n - 1; i > 0; i--) {
//         swap(&arr[0], &arr[i]);  // Move largest to end
//         heapify(arr, i, 0);      // Heapify reduced heap
//     }
// }

// int main() {
//     int n;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     printf("\nOriginal Array:\n");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
        
//     heapSort(arr, n);

//     printf("\n\nSorted Array (Heap Sort):\n");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);

//     return 0;
// }

#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        swap(&arr[largest],&arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    int i;
    for(i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int i, n;
    printf("Enter how many values :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter actual values :");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Octual array :");
    for(i = 0; i < n; i++){
        printf("%d  ",arr[i]);
    }
    
    heapsort(arr, n);

    printf("\nSorted Array :");
    for(i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    return 0;
}