#include <stdio.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) { // Start from the second element
        int key = a[i];
        int j = i - 1;

        // Move elements that are greater than 'key' one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key; // Place 'key' in its correct position
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    insertionSort(a, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
