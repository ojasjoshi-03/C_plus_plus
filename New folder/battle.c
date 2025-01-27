#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define GRID_SIZE 10
#define NUM_SHIPS 5

char playerGrid[GRID_SIZE][GRID_SIZE];
char computerGrid[GRID_SIZE][GRID_SIZE];
char playerGuessGrid[GRID_SIZE][GRID_SIZE];
char computerGuessGrid[GRID_SIZE][GRID_SIZE];

// Function Declarations
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int hideShips, const char* title);
int placeShip(char grid[GRID_SIZE][GRID_SIZE], int shipLength, int row, int col, char orientation);
void placeShipsManually(char grid[GRID_SIZE][GRID_SIZE], int numShips, int shipLengths[]);
void placeShipsRandomly(char grid[GRID_SIZE][GRID_SIZE], int numShips, int shipLengths[]);
void playerTurn(char computerGrid[GRID_SIZE][GRID_SIZE], char guessGrid[GRID_SIZE][GRID_SIZE]);
void computerTurn(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGuessGrid[GRID_SIZE][GRID_SIZE], int *lastHitRow, int *lastHitCol, int *hitMode);
int checkWin(char grid[GRID_SIZE][GRID_SIZE]);

int main() {
    srand(time(NULL));

    initializeGrid(playerGrid);
    initializeGrid(computerGrid);
    initializeGrid(playerGuessGrid);
    initializeGrid(computerGuessGrid);

    int shipLengths[NUM_SHIPS] = {3, 2, 3, 2, 2}; // Example ship lengths
    placeShipsManually(playerGrid, NUM_SHIPS, shipLengths);
    placeShipsRandomly(computerGrid, NUM_SHIPS, shipLengths);

    int lastHitRow = -1, lastHitCol = -1, hitMode = 0;

    while (1) {
        printf("\n");
        displayGrid(playerGrid, 0, "Your Grid");
        displayGrid(playerGuessGrid, 1, "Your Guess Grid");
        displayGrid(computerGuessGrid, 1, "Computer Guess Grid");

        playerTurn(computerGrid, playerGuessGrid);
        if (checkWin(computerGrid)) {
            printf("\nCongratulations! You win!\n");
            break;
        }

        computerTurn(playerGrid, computerGuessGrid, &lastHitRow, &lastHitCol, &hitMode);
        if (checkWin(playerGrid)) {
            printf("\nGame Over! Computer wins!\n");
            break;
        }
    }

    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '~';
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int hideShips, const char* title) {
    printf("\n%s\n", title);
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'X') {
                printf(" X");
            } else if (grid[i][j] == 'O') {
                printf(" O");
            } else if (hideShips && grid[i][j] == 'S') {
                printf(" ~");
            } else if (grid[i][j] == 'S') {
                printf(" S");
            } else {
                printf(" ~");
            }
        }
        printf("\n");
    }
}

int placeShip(char grid[GRID_SIZE][GRID_SIZE], int shipLength, int row, int col, char orientation) {
    if (orientation == 'H') {
        if (col + shipLength > GRID_SIZE) return 0;
        for (int j = col; j < col + shipLength; j++) {
            if (grid[row][j] != '~') return 0;
        }
        for (int j = col; j < col + shipLength; j++) {
            grid[row][j] = 'S';
        }
    } else if (orientation == 'V') {
        if (row + shipLength > GRID_SIZE) return 0;
        for (int i = row; i < row + shipLength; i++) {
            if (grid[i][col] != '~') return 0;
        }
        for (int i = row; i < row + shipLength; i++) {
            grid[i][col] = 'S';
        }
    } else {
        return 0;
    }
    return 1;
}

void placeShipsManually(char grid[GRID_SIZE][GRID_SIZE], int numShips, int shipLengths[]) {
    int row, col;
    char orientation;
    for (int i = 0; i < numShips; i++) {
        while (1) {
            printf("Enter starting coordinates for ship %d (length %d) (row and column): ", i + 1, shipLengths[i]);
            scanf("%d %d", &row, &col);
            printf("Enter orientation for ship %d (H for horizontal, V for vertical): ", i + 1);
            scanf(" %c", &orientation);
            orientation = toupper(orientation);
            if (orientation != 'H' && orientation != 'V') {
                printf("Invalid orientation. Please enter H or V.\n");
                continue;
            }
            if (placeShip(grid, shipLengths[i], row, col, orientation)) {
                break;
            } else {
                printf("Invalid placement. Try again.\n");
            }
        }
    }
}

void placeShipsRandomly(char grid[GRID_SIZE][GRID_SIZE], int numShips, int shipLengths[]) {
    int row, col;
    char orientation;
    for (int i = 0; i < numShips; i++) {
        while (1) {
            orientation = (rand() % 2) ? 'H' : 'V';
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
            if (placeShip(grid, shipLengths[i], row, col, orientation)) {
                break;
            }
        }
    }
}

void playerTurn(char computerGrid[GRID_SIZE][GRID_SIZE], char guessGrid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your guess (row and column): ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
            printf("Invalid input. Coordinates out of bounds. Try again.\n");
            continue;
        }
        if (guessGrid[row][col] == 'X' || guessGrid[row][col] == 'O') {
            printf("You already guessed this position. Try again.\n");
            continue;
        }
        break;
    }
    if (computerGrid[row][col] == 'S') {
        printf("Hit! You hit a ship at (%d, %d)!\n", row, col);
        computerGrid[row][col] = 'X';
        guessGrid[row][col] = 'X';
    } else {
        printf("Miss! No ship at (%d, %d).\n", row, col);
        guessGrid[row][col] = 'O';
    }
}

void computerTurn(char playerGrid[GRID_SIZE][GRID_SIZE], char computerGuessGrid[GRID_SIZE][GRID_SIZE], int *lastHitRow, int *lastHitCol, int *hitMode) {
    int row, col;
    if (*hitMode) {
        if (*lastHitRow > 0 && playerGrid[*lastHitRow - 1][*lastHitCol] == 'S') {
            row = *lastHitRow - 1;
            col = *lastHitCol;
        } else if (*lastHitRow < GRID_SIZE - 1 && playerGrid[*lastHitRow + 1][*lastHitCol] == 'S') {
            row = *lastHitRow + 1;
            col = *lastHitCol;
        } else if (*lastHitCol > 0 && playerGrid[*lastHitRow][*lastHitCol - 1] == 'S') {
            row = *lastHitRow;
            col = *lastHitCol - 1;
        } else if (*lastHitCol < GRID_SIZE - 1 && playerGrid[*lastHitRow][*lastHitCol + 1] == 'S') {
            row = *lastHitRow;
            col = *lastHitCol + 1;
        } else {
            *hitMode = 0;
        }
    }
    if (!*hitMode) {
        do {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        } while (playerGrid[row][col] == 'X' || playerGrid[row][col] == 'O');
    }
    if (playerGrid[row][col] == 'S') {
        printf("Computer hit your ship at (%d, %d)!\n", row, col);
        playerGrid[row][col] = 'X';
        computerGuessGrid[row][col] = 'X';
        *lastHitRow = row;
        *lastHitCol = col;
        *hitMode = 1;
    } else {
        printf("Computer missed at (%d, %d).\n", row, col);
        playerGrid[row][col] = 'O';
        computerGuessGrid[row][col] = 'O';
        *hitMode = 0;
    }
}

int checkWin(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                return 0;
            }
        }
    }
    return 1;
}
