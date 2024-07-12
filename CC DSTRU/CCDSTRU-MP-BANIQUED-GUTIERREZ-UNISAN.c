#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS];
bool gameOver = false;
int availablePegs[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

/* PegBoard function displays a table of rows and columns 
@return <returns nothing since return type is void>
*/
void PegBoard() {
    int i,j;
    char cLT = 201, cMT = 203, cRT = 187,
         cLH = 204, cM = 206, cRH = 185,
         cLM = 200, cMB = 202, cRB = 188, 
         cV = 186, cH = 205;
    
    printf("\n");

    printf("%c%c%c%c%c%c%c\n", cLT, cH, cMT, cH, cMT, cH, cRT);
    for(i=0; i<ROWS; i++) {
        for(j =0; j<COLS; j++){
            if (board[i][j] > 0){
                printf("%c%d", cV, board[i][j]);
            }
            else
                printf("%c ", cV);
        }
        printf("%c", cV);
        printf("\n");
        if(i < ROWS-1) {
            printf("%c%c%c%c%c%c%c", cLH, cH, cM, cH, cM, cH, cRH);
            printf("\n");
        }
    }
    printf("%c%c%c%c%c%c%c\n", cLM, cH, cMB, cH, cMB, cH, cRB);
    printf("\n");
}

/* initBoard function initializes the board contents before displaying the board itself
@return <returns nothing since return type is void>
*/
void initBoard () {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '\0';
        }
    }
}

/* isPegAvailable function checks whether the chosen peg is unused or used.
   If chosen peg is available return a bool type [true], if peg is used / input is invalid return a bool type [false]
@return true or false [bool type]
*/
bool isPegAvailable(int peg) {
    for(int i=0; i<9; i++) {
        if(availablePegs[i] == peg) {
            return true;
        }
    }
    if (peg > 0 && peg < 10) {
        printf("Peg has already been used\n");
        printf("Please try again\n");
    }
    else
        printf("Invalid Input\n");
    
    return false;
}

/* isMoveValid function checks whether the tile or peg is unused. 
   The function returns true if and only if both tile and peg are available. If not, return false.
@return true or false [bool type]
*/
bool isMoveValid(int row, int col, int peg) {
    
    if (isPegAvailable(peg)) {
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '\0') {
            return true;
        }
        else {
            printf("Tile has been already occupied!\n");
            printf("Please try again.\n");
        return false;
        }
    }

    return false;
}

/* checkWin function checks whether a horizontal or vertical array of tiles met the conditions to win
   The function returns true if and only if a vertical or horizontal array of tiles has a sum of less than or equal to 15. If not, return false.
@return true or false [bool type]
*/
bool checkWin(int player) {
    int sum = 0, index, vert = 0, hori = 0;
    // For every 
    int i;

    for(int i = 0; i < 3; i++) {
        if(board[i][0] > 0 && board[i][1] > 0 && board[i][2] > 0) {
            index = i;
            vert = 1;
        }
    }
    // Checks whether a vertical array of tiles has been occupied. If yes, save the index of the vertical array and set 'vert' variable to 1.
    for(int i = 0; i < 3; i++) {
        if(board[0][i] > 0 && board[1][i] > 0 && board[2][i] > 0) {
            index = i;
            hori = 1;
        }
    }
    // Checks whether a horizontal array of tiles has been occupied, If yes, save the index of the horizontal array and set 'hori' variable to 1.

    if(vert == 1){      
        sum = 0;
        
        for(i=0; i<3; i++) 
                sum = sum + board[index][i];         
    // If a vertical array of tiles has been occupied, check the sum of all pegs in the specific array and check whether it is equal or less than 15.
        if(sum == 15) {
            gameOver = true;
            printf("player %d wins!\n", player);
            return true;
        }
    // If the summation of all pegs are equal to 15, then the player who added the last peg wins.
        else if(sum < 15){
            gameOver = true;

            if(player == 1){
                printf("player 2 wins!\n");
            }
            else if (player == 2){
                 printf("player 1 wins!\n");
            }
            return true;
        }
    // If the summation of all pegs are less than 15, then the player who added the last peg loses.
    }

    if(hori == 1){
        sum = 0;
        for(i=0; i<3; i++) 
                sum = sum + board[i][index];
    // If a horizontal array of tiles has been occupied, check the sum of all pegs in the specific array and check whether it is equal or less than 15.
        if(sum == 15) {
            gameOver = true;
            printf("player %d wins!\n", player);
            return true;
        }
    // If the summation of all pegs are equal to 15, then the player who added the last peg wins.
        else if(sum < 15){
            gameOver = true;
            if(player == 1){
                printf("player 2 wins!\n");
            }
            else if (player == 2){
                 printf("player 1 wins!\n");
            }
            return true;
        }
    // If the summation of all pegs are less than 15, then the player who added the last peg loses.
    }

    // if no player has won yet, return false

    return false;
}

/* updateAvailablePegs function updates the remaining unused pegs to be used by both players.
@return <returns nothing since return type is void>
*/
void updateAvailablePegs(int peg) {
    for(int i=0; i<9; i++) {
        if(availablePegs[i] == peg) 
            availablePegs[i] = -1;
    }
}

/* PlayerMove function will update the board tile corresponding to the player's chosen tile position to its chosen peg.
@return <returns nothing since return type is void>
*/
void PlayerMove(int row, int col, int peg) {
    if(isMoveValid(row, col, peg)) {
        board[row][col] = peg;
        updateAvailablePegs(peg);
    }
}

int main() {
    initBoard();
    PegBoard();
    int row, col, peg, nValid = 0;
    int player = 1;

    while(!gameOver) {
        printf("\nPlayer %d's turn.\n", player);
        
        do {
            do {
                printf("Enter the row (1-3) and column (1-3) separated by spaces: ");
                scanf("%d %d", &row, &col);
                if (row < 1 || row > 3 || col < 1 || col > 3) {
                    printf("Tile is beyond boundaries\n");
                    nValid = 0;                                
                }
                else
                    nValid = 1;
            } while (nValid == 0);
            // Nested do-while loop will terminate whenever the player inputs a valid tile.

                printf("Enter the peg number (1-9): ");
                scanf("%d", &peg);
                row--;
                col--;
        } while(!isMoveValid(row, col, peg));
        

    PlayerMove(row, col, peg);
    PegBoard();
    checkWin(player);
    // Update player for next turn
    if (player == 1)
        player = 2;
    else if (player == 2)
        player = 1;
    } // The game will continue until gameOver function returns a true bool value.

    return 0;
}