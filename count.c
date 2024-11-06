#include <stdio.h>

void quick_sort(int arr[], int low, int high);
void selection_sort(int arr[], int size);
void heap_sort(int arr[], int size);
void print_array(int arr[], int size);

int partition(int arr[], int low, int high);
void heapify(int arr[], int size, int i);

int main() {
    int choice, arr[10];

    
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
}void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}


void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void heap_sort(int arr[], int size) {
    
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

                heapify(arr, i, 0);
    }
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}
void print_array(int arr[], int size) {
    for (int i = 0; i < size
        printf("%d ", arr[i]);
    }
    printf("\n");
}
