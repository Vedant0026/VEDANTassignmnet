#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrices(int n, int m, int A[n][m], int B[n][m], int C[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to find saddle point
void saddlePoint(int n, int m, int A[n][m]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        int minRow = A[i][0], colIndex = 0;
        for (int j = 1; j < m; j++) {
            if (A[i][j] < minRow) {
                minRow = A[i][j];
                colIndex = j;
            }
        }
        int k;
        for (k = 0; k < n; k++) {
            if (A[k][colIndex] > minRow)
                break;
        }
        if (k == n) {
            printf("Saddle point at (%d,%d) = %d\n", i, colIndex, minRow);
            found = 1;
        }
    }
    if (!found) printf("No saddle point found.\n");
}

// Function to calculate inverse (only for 2x2 matrix)
void inverse2x2(int A[2][2]) {
    int det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if (det == 0) {
        printf("Matrix is singular, no inverse.\n");
        return;
    }
    printf("Inverse matrix:\n");
    printf("%.2f %.2f\n", (float)A[1][1]/det, (float)-A[0][1]/det);
    printf("%.2f %.2f\n", (float)-A[1][0]/det, (float)A[0][0]/det);
}

// Function to check magic square
int isMagicSquare(int n, int A[n][n]) {
    int sum = 0;
    for (int j = 0; j < n; j++) sum += A[0][j];

    // Check rows
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) rowSum += A[i][j];
        if (rowSum != sum) return 0;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) colSum += A[i][j];
        if (colSum != sum) return 0;
    }

    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += A[i][i];
        diag2 += A[i][n-i-1];
    }
    if (diag1 != sum || diag2 != sum) return 0;

    return 1;
}

int main() {
    int n, m;
    printf("Enter rows and columns of matrices: ");
    scanf("%d %d", &n, &m);

    int A[n][m], B[n][m], C[n][m];
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    // Addition
    addMatrices(n, m, A, B, C);
    printf("Sum of matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    // Saddle point
    saddlePoint(n, m, A);

    // Inverse (only if 2x2)
    if (n == 2 && m == 2) inverse2x2(A);

    // Magic square check (only if square matrix)
    if (n == m) {
        if (isMagicSquare(n, A))
            printf("Matrix A is a Magic Square.\n");
        else
            printf("Matrix A is not a Magic Square.\n");
    }

    return 0;
}