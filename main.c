#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

#define SIZE 4

void freeMemoryIfFailed (int** matrix, int i) {
    int j = 0;
    
    for (j = 0; j < i; j++) {
        free(matrix[j]);
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
                freeMemoryIfFailed(matrix, i);
                free(matrix);
                exit(1);
            }
        }
    }
    return matrix;
}

int generateTwoOrFour () {
    int number = 0;

    //Generate a random number between 0 and 4 and return the number if it's either two or four. Four has less chances to appear.
    number = (rand() % 5) ? 2 : 4;
    return number;
}

void initMatrix (int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix (int** matrix) {
    int i = 0, j = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

int generateSpot () {
    int spot = 0;

    spot = rand() % SIZE;
    return spot;
}

void startGame (int** matrix) {
    int first_spot = 0, second_spot = 0;

    initMatrix(matrix);
    first_spot = generateSpot();
    matrix[3][first_spot] = generateTwoOrFour();
    do {
        second_spot = generateSpot();
        matrix[3][second_spot] = generateTwoOrFour();
    } while (second_spot == first_spot);
    printMatrix(matrix);
}

void sliding (char direction, int** matrix){
    int key_value = -1; // g = 0, h = 1, b = 2, d = 3
    int x = 0, y = 0, buff;
    
    if (direction == 'g') {
        key_value = 0;
    }
    else {
        if (direction == 'h') {
            key_value = 1;
        }
        else {
            if (direction == 'b') {
                key_value = 2;
            }
            else {
                if (direction == 'd') {
                    key_value = 3;
                }
            }
        }
    }
    
    switch (key_value) {
        case 0:
            for (x = 0; x < SIZE; x++) {
                for (y = 1; y < SIZE; y++) {
                    if (matrix[x][y] != 0) { //initiate the shift
                        for (buff = y; buff > 0; buff--) {
                            //simple shift
                            if (matrix[x][buff - 1] == 0) {
                                matrix[x][buff - 1] = matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                            //add and shift
                            else if (matrix[x][buff] == matrix[x][buff - 1]){
                                matrix[x][buff - 1] = matrix[x][buff - 1] + matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                        }
                    }
                }
            }
            
            break;
        case 1:
            for (x = 1; x < SIZE; x++) {
                for (y = 0; y < SIZE; y++) {
                    if (matrix[x][y] != 0) {
                        for (buff = x; buff > 0; buff--) {
                            if (matrix[buff - 1][y] == 0) {
                                matrix[buff - 1][y] = matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                            else if (matrix[x][buff] == matrix[buff - 1][y]){
                                matrix[buff - 1][y] = matrix[buff - 1][y] + matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            for (x = (SIZE - 2); x >= 0; x--) {
                for (y = 0; y < SIZE; y++) {
                    if (matrix[x][y] != 0) {
                        for (buff = x; buff < (SIZE - 1); buff++) {
                            if (matrix[buff + 1][y] == 0) {
                                matrix[buff + 1][y] = matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                            else if (matrix[x][buff] == matrix[buff + 1][y]){
                                matrix[buff + 1][y] = matrix[buff + 1][y] + matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 3:
            for (x = 0; x < SIZE; x++) {
                for (y = (SIZE - 2); y >= 0; y--) {
                    if (matrix[x][y] != 0) {
                        for (buff = y; buff < (SIZE - 1); buff++) {
                            if (matrix[x][buff + 1] == 0) {
                                matrix[x][buff + 1] = matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                            else if (matrix[x][buff] == matrix[x][buff + 1]){
                                matrix[x][buff + 1] = matrix[x][buff + 1] + matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                        }
                    }
                }
            }
            break;
    }
    //Spawn new random acceptable value at random spot 
    int newX = generateSpot(), newY = generateSpot();
    while (matrix[newX][newY] != 0){
        newX = generateSpot();
        newY = generateSpot();
    }
    matrix[newX][newY] = generateTwoOrFour();
}

int main () {
    int** matrix = NULL;
    
    srand(time(NULL));
    matrix = matrixGenerator(matrix);
    startGame(matrix);

    char userInput=0;
    printf("\nInput a direction: ");
    scanf("%c", &userInput);
    //g=left ; h=up; b=down; d=right ; q=quit
    while (userInput!='g' && userInput!='h' && userInput!='b' && userInput!='d' && userInput!='q') {
        scanf("%c", &userInput);
    }
    if(userInput=='q'){
        exit(0);
    }
    sliding(userInput, matrix);
    printMatrix(matrix);
    

    return 0;
}