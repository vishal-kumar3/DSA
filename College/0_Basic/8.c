#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix of size rows x cols
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free dynamically allocated memory for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input elements of a matrix
void inputMatrix(int** matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display the elements of a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int** result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    int** matrix1 = allocateMatrix(rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    int** matrix2 = allocateMatrix(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2) {
        int** result_add = addMatrices(matrix1, matrix2, rows1, cols1);
        printf("\nMatrix Addition Result:\n");
        displayMatrix(result_add, rows1, cols1);
        freeMatrix(result_add, rows1);
    } else {
        printf("\nMatrix addition is not possible as the matrices are not of the same size.\n");
    }

    if (cols1 == rows2) {
        int** result_multiply = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);
        printf("\nMatrix Multiplication Result:\n");
        displayMatrix(result_multiply, rows1, cols2);
        freeMatrix(result_multiply, rows1);
    } else {
        printf("\nMatrix multiplication is not possible due to incompatible dimensions.\n");
    }

    int** result_transpose = transposeMatrix(matrix1, rows1, cols1);
    printf("\nTranspose of the first matrix:\n");
    displayMatrix(result_transpose, cols1, rows1);
    freeMatrix(result_transpose, cols1);

    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}
