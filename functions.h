#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE 4
#define DIRECTIONAL_KEYS 5
//These variable will enable coloring the text in the terminal
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
void freeMemoryIfFailed(int** matrix, int i);

/***********************************************
*
* @Purpose: Allocate the memory of a two dimensional
            array.
* @Parameters: in: A two dimensional array.
* @Return: The two dimensional array with the memory
           allocated.
*
************************************************/
int** matrixGenerator(int** matrix);

/***********************************************
*
* @Purpose: Generate either a two or a four.
* @Parameters: ---.
* @Return: ---.
*
************************************************/
int generateTwoOrFour();

/***********************************************
*
* @Purpose: Initiate all the cells of the two
            dimensional array to zero.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void initMatrix(int** matrix);

/***********************************************
*
* @Purpose: Print a two dimensional array.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void printMatrix (int** matrix, int newX, int newY, int first);

/***********************************************
*
* @Purpose: Generate a random number that goes
            from 0 to 3 since SIZE is 4.
* @Parameters: ---.
* @Return: The number generated.
*
************************************************/
int generateSpot();

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
void startGame (int** matrix);

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
int readKeys ();

/***********************************************
*
* @Purpose: Slides every cell to the right if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void slideRight (int** matrix);

/***********************************************
*
* @Purpose: Slides every cell to up if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void slideUp (int** matrix);

/***********************************************
*
* @Purpose: Slides every cell to the left if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void slideLeft (int** matrix);

/***********************************************
*
* @Purpose: Slides every cell down if
            possible.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void slideDown (int** matrix);

/***********************************************
*
* @Purpose: Merges two cells to the left if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeLeft (int** matrix);

/***********************************************
*
* @Purpose: Merges two cells to the right if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeRight (int** matrix);

/***********************************************
*
* @Purpose: Merges two cells upwards if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeUp (int** matrix);

/***********************************************
*
* @Purpose: Merges two cells downwards if they have
            the same value.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
int mergeDown (int** matrix);

/***********************************************
*
* @Purpose: Checks if the user has reached 2048.
* @Parameters: in: Two dimensional array.
* @Return: Returns 0 if the user hasn't won the game
           and 1 if 2048 has been reached.
*
************************************************/
int gameState (int** matrix);

/***********************************************
*
* @Purpose: Prints the matrix, it's an auxilary
            function.
* @Parameters: in: A two dimensional array.
* @Return: ---.
*
************************************************/
void auxprintMatrix (int** matrix);

/***********************************************
*
* @Purpose: Compare if two matrices are equal
* @Parameters: Two matrices 4x4.
* @Return: Returns 0 if equal or -1 if not equal.
*
************************************************/
int cmpMat(int** mat1, int** mat2);

/***********************************************
*
* @Purpose: Copy a matrix mat1 to mat2
* @Parameters: Two matrices 4x4.
* @Return: 0.
*
************************************************/
void cpyMat(int** mat1, int** mat2);

/***********************************************
*
* @Purpose: Clear the above content in the terminal, in a different way whether compiled on unix or windows.
* @Parameters: in: ---.
* @Return: ---.
*
************************************************/
void clearTerm();

/***********************************************
*
* @Purpose: Print the score and the game into a file.
* @Parameters: in: A two dimensional array.
               in: A file.
               in: The score.
* @Return: ---.
*
************************************************/
void printInFile (int** matrix, FILE* file, int score);

/***********************************************
*
* @Purpose: Read from a file.
* @Parameters: in: A two dimensional array.
               in: A file.
* @Return: The score.
*
************************************************/
int readFromFile (int** matrix, FILE* file);

/***********************************************
*
* @Purpose: Start a new game.
* @Parameters: in: A two dimensional array.
               in: A two dimensional array.
* @Return: The score.
*
************************************************/
void newGame (int** matrix, int** tmpMat);

/***********************************************
*
* @Purpose: Load a previous game.
* @Parameters: in: A two dimensional array.
               in: A two dimensional array.
* @Return: The score.
*
************************************************/
void loadGame (int** matrix, int** tmpMat);

#endif