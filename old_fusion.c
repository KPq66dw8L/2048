
/*int slideAndFusion (int key_value, int** matrix){
    // g = 0, h = 1, b = 2, d = 3
    int x = 0, y = 0, buff, score = 0;
     
    switch (key_value) {
        case 0: //gauche
            for (x = 0; x < SIZE; x++) {
                for (y = 1; y < SIZE; y++) {
                    if (matrix[x][y] != 0) { //initiate the shift
                        for (buff = y; buff > 0; buff--) {
                            //simple shift
                            if (matrix[x][buff - 1] == 0) {
                                matrix[x][buff - 1] = matrix[x][buff];
                                matrix[x][buff] = 0;
                            }
                            //fusion
                            else if ((matrix[x][buff] == matrix[x][buff - 1]) && (matrix[x][buff] != 0)){
                                matrix[x][buff - 1] = matrix[x][buff - 1] + matrix[x][buff];
                                score += matrix[x][buff - 1];
                                matrix[x][buff] = 0;
                            }
                        }
                    }
                }
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
                            else if ((matrix[buff][y] == matrix[buff - 1][y]) && (matrix[buff][y] != 0)){
                                matrix[buff - 1][y] = matrix[buff - 1][y] + matrix[buff][y];
                                score += matrix[buff - 1][y];
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
                            else if ((matrix[buff][y] == matrix[buff + 1][y]) && (matrix[buff][y] != 0)){
                                matrix[buff + 1][y] = matrix[buff + 1][y] + matrix[buff][y];
                                score += matrix[buff + 1][y];
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
                            else if ((matrix[x][buff] == matrix[x][buff + 1]) && (matrix[x][buff] != 0)){
                                matrix[x][buff + 1] = matrix[x][buff + 1] + matrix[x][buff];
                                score += matrix[x][buff + 1];
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
    return score;
}*/