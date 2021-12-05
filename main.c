/***********************************************
*
* @Purpose: Create the game 2048.
* @Author: Axel Expósito Ragaigne && Julien Herbaux
* @Creation date: 02/12/2021
* @Date of last modification: 04/12/2021
*
************************************************/
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
    matrix[3][first_spot] = generateTwoOrFour();
    do {
        second_spot = generateSpot();
        matrix[3][second_spot] = generateTwoOrFour();
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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[])
{
   int i, j;
   for (i = 0; i < SIZE-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < SIZE-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
}

int cntPairs(int** arr, char rc, int rcNum) //rl means row-column, it indicates whether we were passed a row or a column
    {
        // To store the required count
        int count = 0, i;
        int* arr1D = malloc(SIZE * sizeof(int));

        if (rc == 'r')
        {
            for (i = 0; i < SIZE; ++i)
            {
                arr1D[i] = arr[rcNum][i];
            }
        } else 
        {
            if (rc == 'c')
            {
                for (i = 0; i < SIZE; ++i)
                {
                    arr1D[i] = arr[i][rcNum];
                }
            }
        }
        // for (int i = 0; i < SIZE; ++i)
        // {
        //     printf("arr1D[%d] = %d\n", i, arr1D[i]);
        // }
 
        // Sort the array
        bubbleSort(arr1D);
 
        for (int i = 0; i < SIZE - 1;) {
 
            // A valid pair is found
            if (arr1D[i] == arr1D[i + 1] && arr1D[i] != 0) {
                count++;
 
                // Skip the elements of
                // the current pair
                i = i + 2;
            }
 
            // Current elements doesn't make
            // a valid pair with any other element
            else {
                if (arr1D != 0)
                {
                    i++;
                }
            }
        }
        return count;
    }
/***********************************************
*
* @Purpose: Depending of the directional key
            selected the cells will "slide"
            in that direction. If two numbers
            have the same value they can be "fused"
            when they make contact.
* @Parameters: in: Numerical value of the key.
               in: A two dimensional array.
* @Return: ---.
*
************************************************/
void slideAndFusion (int key_value, int** matrix){
    // g = 0, h = 1, b = 2, d = 3
    int x = 0, y = 0, buff, nbFusion = 0;
     
    switch (key_value) {
        case 0: //gauche
            for (x = 0; x < SIZE; x++) {
                for (y = 1; y < SIZE; y++) {
                    if (matrix[x][y] != 0) { //initiate the shift
                        
                        for (buff = y; buff > 0; buff--) {
                            //simple shift
                            printf("\nLigne %d nb de pairs: %d\n", x, cntPairs(matrix, 'r', x));
                            if (matrix[x][buff - 1] == 0) {
                                matrix[x][buff - 1] = matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                            //fusion
                            else if ( (matrix[x][buff] == matrix[x][buff - 1]) && ( (cntPairs(matrix, 'r', x) == 2 && nbFusion < 3) || (cntPairs(matrix, 'r', x) == 1 && nbFusion <= 1) )){
                                matrix[x][buff - 1] = matrix[x][buff - 1] + matrix[x][buff];
                                matrix[x][buff] = 0;
                                nbFusion++;
                            }

                        }
                    }
                }
                nbFusion = 0;
            }
            
            break;
        case 1: //haut
            for (x = 0; x < SIZE; x++) {
                for (y = 0; y < SIZE; y++) {
                    if (matrix[x][y] != 0) {
                        for (buff = x; buff > 0; buff--) {
                            if (matrix[buff - 1][y] == 0) {
                                matrix[buff - 1][y] = matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                            else if (matrix[buff][y] == matrix[buff - 1][y]){
                                matrix[buff - 1][y] = matrix[buff - 1][y] + matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 2: //bas
            for (x = (SIZE - 2); x >= 0; x--) {
                for (y = 0; y < SIZE; y++) {
                    if (matrix[x][y] != 0) {
                        for (buff = x; buff < (SIZE - 1); buff++) {
                            if (matrix[buff + 1][y] == 0) {
                                matrix[buff + 1][y] = matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                            else if (matrix[buff][y] == matrix[buff + 1][y]){
                                matrix[buff + 1][y] = matrix[buff + 1][y] + matrix[buff][y];
                                matrix[buff][y] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 3: //droite
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
    printMatrix(matrix, newX, newY, 0);
}
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
    int key_value = -1;

    srand(time(NULL));
    matrix = matrixGenerator(matrix);
    int start = 1;
    // Clear everything above in the terminal
    system("cls");
    startGame(matrix);
    
    while(start == 1){
        printf(KBLU "\nDIRECTIONAL KEYS: D = RIGHT, G = LEFT, H = UP, B = DOWN. \nAfter the first round, the new number spawning each round will appear in green.\n");
        printf("Press Q to QUIT.\n");
        key_value = readKeys();
        if (key_value == 4) {
            printf(KRED "Goodbye !\n");
            // "\n" in white so that the user's prompt appear in white(only for the first prompt afterwards),
            //which is the Windows terminal default prompt color 
            printf(KWHT "\n");
            exit(0);
        }
        else {
            // Each round, clear everything above in the terminal
            //system("cls");
            slideAndFusion(key_value, matrix);
        }
    }
    return 0;
}