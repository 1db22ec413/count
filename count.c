#include <stdio.h>

// Function prototypes
void quick_sort(int arr[], int low, int high);
void selection_sort(int arr[], int size);
void heap_sort(int arr[], int size);
void print_array(int arr[], int size);

int partition(int arr[], int low, int high);
void heapify(int arr[], int size, int i);

int main() {
    int choice, arr[10];

    // Getting input from the user
    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting method:\n");
    printf("1. Quick Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Heap Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Original Array: ");
    print_array(arr, 10);

    // Calling the chosen sorting function
    switch (choice) {
        case 1:
            quick_sort(arr, 0, 9);
            printf("Sorted Array (Quick Sort): ");
            break;
        case 2:
            selection_sort(arr, 10);
            printf("Sorted Array (Selection Sort): ");
            break;
        case 3:
            heap_sort(arr, 10);
            printf("Sorted Array (Heap Sort): ");
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    print_array(arr, 10);
    return 0;
}
