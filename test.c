#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 4
#define DIRECTIONAL_KEYS 5

void slideRight (int** matrix) {
    int i = 0, j = 0, buff = 0;

    for (i = 0 ; i < SIZE; i++) {
        for (j = (SIZE - 2); j >= 0; j--) {
            if (matrix[i][j] != 0) {
                for (buff = j; buff < (SIZE - 1); buff++) {
                    if (matrix[i][buff + 1] == 0) {
                        matrix[i][buff + 1] = matrix[i][buff];
                        matrix[i][buff] = 0;
                    }
                }
            }
        }
    }
}

void slideUp (int** matrix) {
    int i = 0, j = 0, buff = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] != 0) {
                for (buff = i; buff > 0; buff--) {
                    if (matrix[buff - 1][j] == 0) {
                        matrix[buff - 1][j] = matrix[buff][j];
                        matrix[buff][j] = 0;
                    }
                }
            }
        }
    }
}

void slideLeft (int** matrix) {
    int i = 0, j = 0, buff = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] != 0) {
                for (buff = j; buff > 0; buff--) {
                    if (matrix[i][buff - 1] == 0) {
                        matrix[i][buff - 1] = matrix[i][buff];
                        matrix[i][buff] = 0;
                    }
                }
            }
        }
    }
}

void slideDown (int** matrix) {
    int i = 0, j = 0, buff = 0;

    for (i = (SIZE - 2); i >= 0; i--) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] != 0) {
                for (buff = i; buff < (SIZE - 1); buff++) {
                    if (matrix[buff + 1][j] == 0) {
                        matrix[buff + 1][j] = matrix[buff][j];
                        matrix[buff][j] = 0;
                    }
                }
            }
        }
    }
}

int readKeys () {
    char keys[DIRECTIONAL_KEYS] = {'g', 'h', 'b', 'd', 'q'}; // g = 0, h = 1, b = 2, d = 3, q = 4
    char c = 0;
    int i = 0;

    do {
        while (isspace(c = getchar())) {
        }
        for (i = 0; i < DIRECTIONAL_KEYS; i++) {
            if (c == keys[i]) {
                return i;
            }
        }
    } while ((c != 'd') || (c != 'g') || (c != 'h') || (c != 'b') || (c != 'q'));
    return -1;
}

void printMatrix (int** matrix, int rows, int columns) {
    int i = 0, j = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

int** matrixGenerator (int** matrix) {
    int i = 0;

    matrix = (int**) malloc(sizeof(int*) * SIZE);
    if (NULL == matrix) {
        exit(1);
    }
    else {
        for (i = 0; i < SIZE; i++) {
            matrix[i] = (int*) malloc(sizeof(int) * SIZE);
            if (NULL == matrix[i]) {
                exit(1);
            }
        }
    }
    return matrix;
}

void initMatrix (int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
}

void mergeLeft(int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i][j - 1] == matrix[i][j]) {
                matrix[i][j - 1] += matrix[i][j];
                matrix[i][j] = 0;
            }
        }
    }
}

void mergeRight (int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = SIZE - 1; j > 0; j--) {
            if (matrix[i][j] && matrix[i][j - 1] == matrix[i][j]) {
                matrix[i][j] += matrix[i][j - 1];
                matrix[i][j - 1] = 0;
            }
        }
    }
}

void mergeUp (int** matrix) {
    int i = 0, j = 0;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i + 1][j] != matrix[i][j]) {
                matrix[i][j] += matrix[i + 1][j];
                matrix[i + 1][j] = 0;
            }
        }
    }
}

void mergeDown (int** matrix) {
    int i = 0, j = 0;

    for (i = SIZE - 1; i > 0; i--) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i - 1][j] == matrix[i][j]) {
                matrix[i][j] += matrix[i - 1][j];
                matrix[i - 1][j] = 0;
            }
        }
    }
}

int main () {
    int** matrix;
    int key = -1;

    matrix = matrixGenerator(matrix);
    initMatrix(matrix);
    matrix[1][0] = 4;
    matrix[1][1] = 2;
    matrix[1][2] = 4;
    matrix[1][3] = 4;
    printMatrix(matrix, SIZE, SIZE);
    key = readKeys();
    switch (key) {
        case 0:
            slideLeft(matrix);
            
                mergeLeft(matrix);
                slideLeft(matrix);
            
            break;
        case 1:
            slideUp(matrix);
                mergeUp(matrix);
                slideUp(matrix);
        
            break;

        case 2:
            slideDown(matrix);
            mergeDown(matrix);
            slideDown(matrix);
            break;
        
        case 3:
            slideRight(matrix);
           
                mergeRight(matrix);
                slideRight(matrix);
            
            break;
    }

    printMatrix(matrix, SIZE, SIZE);
    return 0;
}