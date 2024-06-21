#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VALUE 100

void fillArrayWithRandomNo(int list[], int n);
bool seqSearch(int list[], int n, int target, int *locn, int *tests);

int main() {
    int N, target, tests, locn;
    int successfulSearches = 0, totalTests = 0;

    printf("Enter the number of integers N: ");
    scanf("%d", &N);

    srand(time(NULL));
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fillArrayWithRandomNo(array, N);

    for (int i = 0; i < N; i++) {
        target = rand() % MAX_VALUE + 1;
        printf("Target of search %d: %d\n", i, target);

        if (seqSearch(array, N, target, &locn, &tests)) {
            successfulSearches++;
            printf("Found at index %d\n", locn);
        }
        totalTests += tests;
    }

    printf("Number of searches: %d\n", N);
    printf("Successful searches: %d\n", successfulSearches);
    printf("Success percentage: %.2f%%\n", (successfulSearches / (double)N) * 100);
    printf("Average tests per search: %.2f\n", totalTests / (double)N);

    free(array);
    return 0;
}

void fillArrayWithRandomNo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE + 1;
        printf("%d\n", arr[i]);
    }
}

bool seqSearch(int list[], int n, int target, int *locn, int *tests) {
    *tests = 0;
    for (int i = 0; i < n; i++) {
        (*tests)++;
        if (list[i] == target) {
            *locn = i;
            return true;
        }
    }
    *locn = -1;
    return false;
}
