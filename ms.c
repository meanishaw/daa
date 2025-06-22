#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 32000

int mergeSort(int[], int);
int merge(int[], int, int[], int, int[]);

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
            x = mergeSort(a, n);
            printf("Sorted array is:\n");
            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
            break;

        case 2: {
            int arr[MAX], size, j, t1, t2, t3;
            float ln;
            printf("Enter initial array size: ");
            scanf("%d", &size);
            printf("Size\tAscending\tcnlogn\tDescending\tcnlogn\tRandom\t\tcnlogn\n");
            for(i = 1; i <= 5; i++, size *= 2) {
                ln = 2 * size * log(size) / log(2);
                for(j = 0; j < size; j++) arr[j] = j;
                t1 = mergeSort(arr, size);
                for(j = 0; j < size; j++) arr[j] = size - j;
                t2 = mergeSort(arr, size);
                for(j = 0; j < size; j++) arr[j] = rand() % MAX;
                t3 = mergeSort(arr, size);
                printf("%d\t%d\t\t%.0f\t%d\t\t%.0f\t%d\t\t%.0f\n", size, t1, ln, t2, ln, t3, ln);
            }
            printf("(Assuming c = 2)\n");
            break;
        }

        default:
            exit(0);
    }
    return 0;
}

int mergeSort(int a[], int n) {
    if(n <= 1) return 0;
    int mid = n / 2, i, count = 0;
    int b[mid], c[n - mid];

    for(i = 0; i < mid; i++) b[i] = a[i];
    for(i = mid; i < n; i++) c[i - mid] = a[i];

    int c1 = mergeSort(b, mid);
    int c2 = mergeSort(c, n - mid);
    int c3 = merge(b, mid, c, n - mid, a);

    return c1 + c2 + c3;
}

int merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0, count = 0;
    while(i < p && j < q) {
        a[k++] = (b[i] <= c[j]) ? b[i++] : c[j++];
        count++;
    }
    while(i < p) a[k++] = b[i++], count++;
    while(j < q) a[k++] = c[j++], count++;
    return count;
}
