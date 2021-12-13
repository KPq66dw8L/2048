#include "functions.h"

/***********************************************
*
* @Purpose: Frees the memory of previous cells
            of a two dimensional array if when 
            allocating the memory of a new one 
            failed.
* @Parameters: in: A two dimensional array.
               in: Position of the last cell.
* @Return: ---.
*
************************************************/
void freeMemoryIfFailed (int** matrix, int i) {
    int j = 0;
    
    for (j = 0; j < i; j++) {
        free(matrix[j]);
    }
}
/***********************************************
*
* @Purpose: Allocate the memory of a two dimensional
            array.
* @Parameters: in: A two dimensional array.
* @Return: The two dimensional array with the memory
           allocated.
*
************************************************/
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
                freeMemoryIfFailed(matrix, i);
                free(matrix);
                exit(1);
            }
        }
    }
    return matrix;
}
/***********************************************
*
* @Purpose: Generate either a two or a four.
* @Parameters: ---.
* @Return: ---.
*
************************************************/
int generateTwoOrFour () {
    int number = 0;

    //Generate a random number between 0 and 4 and return the number if it's either two or four. Four has less chances to appear.
    number = (rand() % 5) ? 2 : 4;
    return number;
}
/***********************************************
*
* @Purpose: Initiate all the cells of the two
            dimensional array to zero.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void initMatrix (int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
}
/***********************************************
*
* @Purpose: Print a two dimensional array.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void printMatrix (int** matrix, int newX, int newY, int first) {
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == newX && j == newY && first == 0){
                printf(KGRN "%d\t", matrix[i][j]);
            } else {
                if (matrix[i][j] == 2 && first == 0){
                    printf(KCYN "%d\t", matrix[i][j]);
                } else {
                    if (matrix[i][j] == 4 && first == 0) {
                        printf(KBLU "%d\t", matrix[i][j]);
                    } else {
                        if (matrix[i][j] == 8) {
                            printf(KYEL "%d\t", matrix[i][j]);
                        } else {
                            if (matrix[i][j] == 16) {
                                printf(KYEL "%d\t", matrix[i][j]);
                            } else {
                                if (matrix[i][j] == 32) {
                                    printf(KMAG "%d\t", matrix[i][j]);
                                } else {
                                    if (matrix[i][j] == 64) {
                                        printf(KMAG "%d\t", matrix[i][j]);
                                    } else {
                                        if (matrix[i][j] == 128) {
                                            printf(KRED "%d\t", matrix[i][j]);
                                        } else {
                                            if (matrix[i][j] == 256) {
                                                printf(KRED "%d\t", matrix[i][j]);
                                            } else {
                                                if (matrix[i][j] == 512) {
                                                    printf(KRED "%d\t", matrix[i][j]);
                                                } else {
                                                    if (matrix[i][j] == 1024) {
                                                        printf(KRED "%d\t", matrix[i][j]);
                                                    } else {
                                                        if (matrix[i][j] == 2048) {
                                                            printf(KRED "%d\t", matrix[i][j]);
                                                        } else {
                                                            printf(KWHT "%d\t", matrix[i][j]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }

}
/***********************************************
*
* @Purpose: Generate a random number that goes
            from 0 to 3 since SIZE is 4.
* @Parameters: ---.
* @Return: The number generated.
*
************************************************/
int generateSpot () {
    int spot = 0;

    spot = rand() % SIZE;
    return spot;
}
/***********************************************
*
* @Purpose: Generate the inital state of our
            game. The game will start with two
            cells that have a value different
            than zero, those values can be either
            two or four. It also prints the two
            dimensional array.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void startGame (int** matrix) {
    int first_spot = 0, second_spot = 0;

    initMatrix(matrix);
    first_spot = generateSpot();
    matrix[first_spot][first_spot] = generateTwoOrFour();
    do {
        second_spot = generateSpot();
        matrix[second_spot][second_spot] = generateTwoOrFour();
    } while (second_spot == first_spot);
    printMatrix(matrix, first_spot, second_spot, 1);
}
/***********************************************
*
* @Purpose: Reads the key that the user inputs and
            tranforms it into a numerical value.
            There are only five valid keys and the
            function will wait for a valid key before
            returning a numerical value.
* @Parameters: ---.
* @Return: The numerical value of the key.
*
************************************************/
int readKeys () {
    char keys[DIRECTIONAL_KEYS] = {'g', 'h', 'b', 'd', 'q'}; // g = 0, h = 1, b = 2, d = 3, q = 4
    char c = 0;
    int i = 0;

    do {
        isspace(c = getchar());        
        for (i = 0; i < DIRECTIONAL_KEYS; i++) {
            if (c == keys[i]) {
                return i;
            }
        }
    } while ((c != 'd') || (c != 'g') || (c != 'h') || (c != 'b') || (c != 'q'));
    return -1;
}
/***********************************************
*
* @Purpose: Slides every cell to the right if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
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
/***********************************************
*
* @Purpose: Slides every cell to up if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
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
/***********************************************
*
* @Purpose: Slides every cell to the left if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
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
/***********************************************
*
* @Purpose: Slides every cell down if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
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
/***********************************************
*
* @Purpose: Merges two cells to the left if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeLeft (int** matrix) {
    int i = 0, j = 0;
    int score = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i][j - 1] == matrix[i][j]) {
                matrix[i][j - 1] += matrix[i][j];
                score += matrix[i][j - 1];
                matrix[i][j] = 0;
            }
        }
    }
    return score;
}
/***********************************************
*
* @Purpose: Merges two cells to the right if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeRight (int** matrix) {
    int i = 0, j = 0;
    int score = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = SIZE - 1; j > 0; j--) {
            if (matrix[i][j] && matrix[i][j - 1] == matrix[i][j]) {
                matrix[i][j] += matrix[i][j - 1];
                score += matrix[i][j];
                matrix[i][j - 1] = 0;
            }
        }
    }
    return score;
}
/***********************************************
*
* @Purpose: Merges two cells upwards if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeUp (int** matrix) {
    int i = 0, j = 0;
    int score = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i + 1][j] == matrix[i][j]) {
                matrix[i][j] += matrix[i + 1][j];
                score += matrix[i][j];
                matrix[i + 1][j] = 0;
            }
        }
    }
    return score;
}
/***********************************************
*
* @Purpose: Merges two cells downwards if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeDown (int** matrix) {
    int i = 0, j = 0;
    int score = 0;

    for (i = SIZE - 1; i > 0; i--) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] && matrix[i - 1][j] == matrix[i][j]) {
                matrix[i - 1][j] += matrix[i][j];
                score += matrix[i - 1][j];
                matrix[i][j] = 0;
            }
        }
    }
    return score;
}
/***********************************************
*
* @Purpose: Checks if the user has reached 2048.
* @Parameters: in: Two dimensional array.
* @Return: Returns 0 if the user hasn't won the game
           and 1 if 2048 has been reached.
*
************************************************/
int gameState (int** matrix) {
    int i = 0, j = 0;
    int state = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                state = 1;
                return state;
            }
            
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if(matrix[i][j] == 0){
                return state; // game's still going
            }
        }
    }
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if(matrix[i][j] == matrix[i + 1][j] || matrix[i][j] == matrix[i][j + 1]){
                return state; // game's still going
            }
        }
    }
    for (j = 0; j < SIZE - 1; j++) {
        if(matrix[3][j] == matrix[3][j + 1]){
            return state; // game's still going
        }
    }
    for (i = 0; i < SIZE - 1; i++) {
        if(matrix[i][3] == matrix[i + 1][3]){
            return state; // game's still going
        }
    }
    state = -1;
    return state; // game over
}
/***********************************************
*
* @Purpose: Prints the matrix, it's an auxilary
            function.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void auxprintMatrix (int** matrix) {
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(KWHT "%d\t", matrix[i][j]);
        }
        printf(KWHT "\n");
    }
}
/***********************************************
*
* @Purpose: Compare if two matrices are equal
* @Parameters: Two matrices 4x4.
* @Return: Returns 0 if equal or -1 if not equal.
*
************************************************/
int cmpMat(int** mat1, int** mat2) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(mat1[i][j] != mat2[i][j]){
                return -1;
            }
        }
    }
    return 0;
}
/***********************************************
*
* @Purpose: Copy a matrix mat1 to mat2
* @Parameters: Two matrices 4x4.
* @Return: 0.
*
************************************************/
void cpyMat(int** mat1, int** mat2) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mat2[i][j] = mat1[i][j];
        }
    }
}