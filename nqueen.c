#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX]; 
int n;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == n) {
        printSolution();
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1); 
            
        }
    }
}

int main() {
    printf("Enter the value of N (N <= %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input. N should be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nSolutions to %d-Queens problem:\n\n", n);
    solve(0);
    return 0;
}
