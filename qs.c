#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 32000

int quickSort(int[], int, int);
int* partition(int[], int, int);
void swap(int*, int*);

int main() {
    int n, i, ch, a[MAX], x;
    printf("Enter choice: 1.Correctness 2.Complexity - ");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            printf("Enter the size of the array: ");
            scanf("%d", &n);
            printf("Enter %d array elements:\n", n);
            for(i = 0; i < n; i++)
                scanf("%d", &a[i]);
            x = quickSort(a, 0, n - 1);
            printf("Sorted array is:\n");
            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
            break;

        case 2: {
            int arr[MAX], size, j, t1, t2, t3;
            float ln;
            printf("Enter initial array size: ");
            scanf("%d", &size);
            printf("Size\tAscending\tn^2\tDescending\tn^2\tRandom\t\t3nlogn\n");
            for(i = 1; i <= 5; i++, size *= 2) {
                ln = 3 * size * log(size) / log(2);
                for(j = 0; j < size; j++) arr[j] = j;
                t1 = quickSort(arr, 0, size - 1);
                for(j = 0; j < size; j++) arr[j] = size - j;
                t2 = quickSort(arr, 0, size - 1);
                for(j = 0; j < size; j++) arr[j] = rand() % MAX;
                t3 = quickSort(arr, 0, size - 1);
                printf("%d\t%d\t\t%d\t%d\t\t%d\t\t%.0f\n", size, t1, size * size, t2, size * size, t3, ln);
            }
            break;
        }

        default:
            exit(0);
    }
    return 0;
}

int quickSort(int a[], int l, int r) {
    if(l >= r) return 0;
    int count = 0;
    int* result = partition(a, l, r);
    int s = result[0];
    count = result[1];
    free(result);
    int c1 = quickSort(a, l, s - 1);
    int c2 = quickSort(a, s + 1, r);
    return count + c1 + c2;
}

int* partition(int a[], int l, int r) {
    int i = l + 1, j = r, count = 0;
    int pivot = a[l];
    while(i <= j) {
        while(i <= r && a[i] < pivot) i++, count++;
        while(j >= l && a[j] > pivot) j--, count++;
        if(i < j) swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = j;
    res[1] = count;
    return res;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
