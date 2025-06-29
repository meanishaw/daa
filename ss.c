#include <stdio.h>
#define MAX 10

int s[MAX], x[MAX];
int d;
int found = 0;

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;
    if ((p + s[k]) == d) {
        found = 1;
        for (i = 1; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("\n");
    } else if ((p + s[k] + s[k + 1]) <= d)
        sumofsub(p + s[k], k + 1, r - s[k]);

    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d)) {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main() {
    int i, n, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in increasing order:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the target subset sum: ");
    scanf("%d", &d);

    for (i = 1; i <= n; i++)
        sum += s[i];

    if (sum < d || s[1] > d)
        printf("No subset possible.\n");
    else {
        printf("Subsets that sum to %d:\n", d);
        sumofsub(0, 1, sum);
        if (!found)
            printf("No subset found.\n");
    }

    return 0;
}
