/*Write a C program to multiply two matrices using dynamic memory allocation. Each
two-dimensional array should be processed as array of pointers to a set of 1-
dimensional integer arrays. Read, access and display the matrix elements using pointers
instead of subscript notation. Use three functions i) To read input matrix ii) To compute
the product and iii) To display the resultant matrix.*/

#include <stdio.h>
#include<stdlib.h>

struct matrix {
    int** cells;
    int row;
    int col;
} A, B, M;

void multiplier() {
    M.row = A.row;
    M.col = B.col;
    M.cells = (int*)calloc(M.row, sizeof(int));
    for(int i = 0; i < M.row; i++) {
        M.cells[i] = (int*)calloc(M.col, sizeof(int));
        for(int j = 0; j < M.col; j++) {
            M.cells[i][j] = 0;
            for(int k = 0; k < A.col; k++) {
                M.cells[i][j] += A.cells[i][k] * B.cells[k][j];
            }
        }
    }
}

void main() {
    printf("Enter no. of rows in matrix A: ");
    scanf("%d", &A.row);
    printf("Enter no. of columns in matrix A: ");
    scanf("%d", &A.col);
    A.cells = (int*)calloc(A.row, sizeof(int));
    for(int i = 0; i < A.row; i++) {
        A.cells[i] = (int*)calloc(A.col, sizeof(int));
        for(int j = 0; j < A.col; j++) {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &A.cells[i][j]);
        }
    }
    
    printf("\n");
    printf("Enter no. of rows in matrix B: ");
    scanf("%d", &B.row);
    printf("Enter no. of columns in matrix B: ");
    scanf("%d", &B.col);
    B.cells = (int*)calloc(B.row, sizeof(int));
    for(int i = 0; i < B.row; i++) {
        B.cells[i] = (int*)calloc(B.col, sizeof(int));
        for(int j = 0; j < B.col; j++) {
            printf("Enter B[%d][%d]: ", i, j);
            scanf("%d", &B.cells[i][j]);
        }
    }
    
    printf("\n");
    printf("Matrix A:\n");
    for(int i = 0; i < A.row; i++) {
        for(int j = 0; j < A.col; j++) {
            printf("%d ", A.cells[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("Matrix B:\n");
    for(int i = 0; i < B.row; i++) {
        for(int j = 0; j < B.col; j++) {
            printf("%d ", B.cells[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Multiplication\n");
    if(A.col != B.row) {
        printf("Given matrices cannot be multiplied\n");
    } else {
        multiplier();
        for(int i = 0; i < M.row; i++) {
            for(int j = 0; j < M.col; j++) {
                printf("%d ", M.cells[i][j]);
            }
            printf("\n");
            free(M.cells[i]);
        }
        free(M.cells);
    }
    
    for(int i = 0; i < A.row; i++) {
        free(A.cells[i]);
    }
    for(int i = 0; i < B.row; i++) {
        free(B.cells[i]);
    }
    free(A.cells);
    free(B.cells);
}
