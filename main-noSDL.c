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
    int new_game = 0;
    char aux;

    tmpMat = matrixGenerator(tmpMat);
    srand(time(NULL));
    matrix = matrixGenerator(matrix);
    // Clear everything above in the terminal
    clearTerm();
    //Ask the user which action wants to perform until a valid input is entered.
    do {
        printf("1. Start a new game | 2. Load a previous game | 3. Exit.");
        printf("\nSelect an option from above: ");
        scanf("%d%c", &new_game, &aux);
        if (new_game <= 0 || new_game > 3) {
            printf("ERROR. Please enter a valid number.\n");
        }
    } while (new_game <= 0 || new_game > 3);
    //Do an action depending on the input of the user.
    switch (new_game) {
        //Start a new game.
        case 1:
            newGame(matrix, tmpMat);
            break;
        //Load a previous game.
        case 2:
            loadGame(matrix, tmpMat);
            break;
        //Exit the program.
        case 3:
            printf(KRED "Goodbye!\n");
            printf(KWHT "\n");
            exit(0);
            break;
    }
    return 0;
}