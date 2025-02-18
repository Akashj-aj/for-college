#include <stdio.h>
#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

void convertToTriplet(int rows, int cols, int matrix[rows][cols], Triplet triplet[], int *size) {
    int k = 1; // First index after the header
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].value = matrix[i][j];
                k++;
            }
        }
    }
    triplet[0].row = rows;
    triplet[0].col = cols;
    triplet[0].value = k - 1; // Number of non-zero elements
    *size = k;
}

void transposeTriplet(Triplet triplet[], int size, Triplet transpose[]) {
    int k = 1; // First index after the header
    for (int i = 0; i < triplet[0].col; i++) { // Traverse column-wise
        for (int j = 1; j < size; j++) {
            if (triplet[j].col == i) {
                transpose[k].row = triplet[j].col;
                transpose[k].col = triplet[j].row;
                transpose[k].value = triplet[j].value;
                k++;
            }
        }
    }
    transpose[0].row = triplet[0].col;
    transpose[0].col = triplet[0].row;
    transpose[0].value = triplet[0].value; // Number of non-zero elements remains the same
}

int isTriplet(Triplet triplet[], int size) {
    if (triplet[0].row > 0 && triplet[0].col > 0 && triplet[0].value == size - 1) {
        return 1; // True
    }
    return 0; // False
}

void displayTriplet(Triplet triplet[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Triplet triplet[MAX], transpose[MAX];
    int size;

    // Convert to triplet representation
    convertToTriplet(rows, cols, matrix, triplet, &size);
    printf("\nTriplet Representation:\n");
    displayTriplet(triplet, size);

    // Transpose the triplet
    transposeTriplet(triplet, size, transpose);
    printf("\nTransposed Triplet Representation:\n");
    displayTriplet(transpose, size);

    // Check if the matrix is already in triplet form
    if (isTriplet(triplet, size)) {
        printf("\nThe given matrix is in triplet form.\n");
    } else {
        printf("\nThe given matrix is not in triplet form.\n");
    }

    return 0;
}
