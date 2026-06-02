#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate ascending data (A)
void ascend(int A[], int N) {
    for (int i = 0; i < N; i++) A[i] = i + 1;
}

// Function to generate descending data (D)
void descend(int A[], int N) {
    for (int i = 0; i < N; i++) A[i] = N - i;
}

// Function to generate random data (R)
void random_fill(int A[], int N) {
    for (int i = 0; i < N; i++) A[i] = (rand() % N) + 1;
}

// Function to generate shuffled permutation (S)
void shuffle(int A[], int N) {
    ascend(A, N);
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

// Function to generate all ones (E)
void all_ones(int A[], int N) {
    for (int i = 0; i < N; i++) A[i] = 1;
}

// Function to print the array
void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");
}

// Insertion Sort (I) 
long insertSort(int A[], int N) {
    long comparisons = 0;
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
            comparisons++;
        }
        A[j + 1] = key;
        comparisons++;
    }
    return comparisons;
}

// QuickSort (Q) 
long quickSort(int A[], int N) {
    long comparisons = 0;

    if (N < 2) return comparisons; // Base case dont need to sort if array is already sorted

    int low = 0, high = N - 1;

    
    if (low < high) {
        int pivot = A[low];  // First element as pivot
        int left = low + 1, right = high;

        while (left <= right) {
            while (left <= high && A[left] < pivot) { comparisons++; left++; }
            while (right > low && A[right] > pivot) { comparisons++; right--; }

            if (left < right) {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                left++;
                right--;
            }
        }

        // Swap the pivot 
        A[low] = A[right];
        A[right] = pivot;

        // Recursively sort the two subarrays
        comparisons += quickSort(A, right);          
        comparisons += quickSort(A + right + 1, N - right - 1); 
    }

    return comparisons;
}

// MergeSort (M) 
long mergeSort(int A[], int N) {
    long assignments = 0;
    if (N > 1) {
        int mid = N / 2;
        int left[mid], right[N - mid];

        for (int i = 0; i < mid; i++) left[i] = A[i];
        for (int i = mid; i < N; i++) right[i - mid] = A[i];

        
        assignments += mergeSort(left, mid);
        assignments += mergeSort(right, N - mid);

        int i = 0, j = 0, k = 0;
        while (i < mid && j < N - mid) {
            if (left[i] <= right[j]) {
                A[k++] = left[i++];
            } else {
                A[k++] = right[j++];
            }
            assignments++;  
        }

        while (i < mid) {
            A[k++] = left[i++]; assignments++; 
            
        }
        while (j < N - mid) { 
            A[k++] = right[j++]; assignments++; 
            
        }
    }

    return assignments;
}

int main() {
    srand(time(NULL));
    int N;
    char inputType, sortType;

    while (scanf("%d %c %c", &N, &inputType, &sortType) == 3) {
        int A[N];

     
        switch (inputType) {
            case 'A': ascend(A, N); break;
            case 'D': descend(A, N); break;
            case 'R': random_fill(A, N); break;
            case 'S': shuffle(A, N); break;
            case 'E': all_ones(A, N); break;
        }

     
        long result = 0;
        switch (sortType) {
            case 'P': printArray(A, N); break;
            case 'I': result = insertSort(A, N); printf("%d %c %c %ld\n", N, inputType, sortType, result); break;
            case 'i': insertSort(A, N); printArray(A, N); break;
            case 'Q': result = quickSort(A, N); printf("%d %c %c %ld\n", N, inputType, sortType, result); break;
            case 'q': quickSort(A, N); printArray(A, N); break;
            case 'M': result = mergeSort(A, N); printf("%d %c %c %ld\n", N, inputType, sortType, result); break;
            case 'm': mergeSort(A, N); printArray(A, N); break;
        }
    }
    return 0;
}

