/***********************************************
*
* @Purpose: Create the game 2048.
* @Author: Axel Expósito Ragaigne && Julien Herbaux
* @Creation date: 02/12/2021
*
************************************************/
#include "functions.h"

/***********************************************
*
* @Purpose: Calls all the functios in order to
            play the game and also reminds the
            user the directional keys.
* @Parameters: ---.
* @Return: Returns 0.
*
************************************************/
int main () {
    int** matrix = NULL;
    int** tmpMat=NULL;
    int key_value = -1;
    int score = 0;

    tmpMat = matrixGenerator(tmpMat);

    srand(time(NULL));
    matrix = matrixGenerator(matrix);
    int start = 1;
    // Clear everything above in the terminal
    system("cls");
    startGame(matrix);
    printf(KMAG "\nScore: %d\n", score);

    while(gameState(matrix) != -1 || gameState(matrix) != 1) {
        printf(KBLU "\nDIRECTIONAL KEYS: D = RIGHT, G = LEFT, H = UP, B = DOWN. Press ENTER once you enter the desired key.");
        printf("\nAfter the first round, the new number spawning each round will appear in green.\n");
        printf("Press Q to QUIT.\n");
        key_value = readKeys();

        // to be able to check if we can spawn a new number later
        cpyMat(matrix, tmpMat);

        switch(key_value) {
            case 0:
                system("cls");
                slideLeft(matrix);
                score += mergeLeft(matrix);
                slideLeft(matrix);
                break;
            case 1:
                system("cls");
                slideUp(matrix);
                score += mergeUp(matrix);
                slideUp(matrix);
                break;
            case 2:
                system("cls");
                slideDown(matrix);
                score += mergeDown(matrix);
                slideDown(matrix);
                break;
            case 3:
                system("cls");
                slideRight(matrix);
                score += mergeRight(matrix);
                slideRight(matrix);
                break;
            case 4:
                printf(KRED "Goodbye!\n");
                printf(KWHT "\n");
                exit(0);
                break;

        }
        // check if we can spawn a new number
        if(cmpMat(matrix, tmpMat) == -1){
            //Spawn new random acceptable value at random spot 
            int newX = generateSpot(), newY = generateSpot();
            while (matrix[newX][newY] != 0){
                newX = generateSpot();
                newY = generateSpot();
            }
            matrix[newX][newY] = generateTwoOrFour();
            printMatrix(matrix, newX, newY, 0);
            printf(KMAG "\nScore: %d", score);
            printf(KWHT "\n");
        } else {
            auxprintMatrix(matrix);
            printf(KMAG "\nScore: %d", score);
            printf(KWHT "\n");
        }
        if (gameState(matrix) == -1) {
            printf(KRED "Game Over!\n");
            freeMemoryIfFailed(matrix, SIZE);
            freeMemoryIfFailed(tmpMat, SIZE);
            free(matrix);
            matrix = NULL;
            free(tmpMat);
            tmpMat = NULL;
            exit(0);
        }
        else {
            if (gameState(matrix) == 1) {
                printf(KRED "You won!\n");
                freeMemoryIfFailed(matrix, SIZE);
                freeMemoryIfFailed(tmpMat, SIZE);
                free(matrix);
                matrix = NULL;
                free(tmpMat);
                tmpMat = NULL;
                exit(0);
            }
        }
    }
    return 0;
}

