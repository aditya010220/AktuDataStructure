#include <stdio.h>

void mergesort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub + 1]; // Temporary array

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) { // Condition fixed
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) { // Copy remaining elements from left subarray
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) { // Copy remaining elements from right subarray
        b[k] = a[j];
        j++;
        k++;
    }

    for (i = lb; i <= ub; i++) { // Copy elements back to the original array
        a[i] = b[i];
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

    int lb = 0;
    int ub = n - 1;

    mergesort(a, lb, ub);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}



