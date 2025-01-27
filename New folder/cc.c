#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_SHIPS 5

char playerGrid[GRID_SIZE][GRID_SIZE];
char computerGrid[GRID_SIZE][GRID_SIZE];
char playerGuessGrid[GRID_SIZE][GRID_SIZE];
char computerGuessGrid[GRID_SIZE][GRID_SIZE];

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

void placeShipsManually(char grid[GRID_SIZE][GRID_SIZE], int numShips) {
    int row, col;
    for (int i = 0; i < numShips; i++) {
        printf("Enter coordinates for ship %d (row and column): ", i + 1);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && grid[row][col] != 'S') {
            grid[row][col] = 'S';
        } else {
            printf("Invalid position. Try again.\n");
            i--;
        }
    }
}

void placeShipsRandomly(char grid[GRID_SIZE][GRID_SIZE], int numShips, int shipLengths[]) {
    for (int i = 0; i < numShips; i++) {
        int placed = 0;
        while (!placed) {
            int orientation = rand() % 2;
            int row = rand() % GRID_SIZE;
            int col = rand() % GRID_SIZE;
            if (orientation == 0 && col + shipLengths[i] <= GRID_SIZE) {
                int canPlace = 1;
                for (int j = 0; j < shipLengths[i]; j++) {
                    if (grid[row][col + j] != '~') {
                        canPlace = 0;
                        break;
                    }
                }
                if (canPlace) {
                    for (int j = 0; j < shipLengths[i]; j++) {
                        grid[row][col + j] = 'S';
                    }
                    placed = 1;
                }
            } else if (orientation == 1 && row + shipLengths[i] <= GRID_SIZE) {
                int canPlace = 1;
                for (int j = 0; j < shipLengths[i]; j++) {
                    if (grid[row + j][col] != '~') {
                        canPlace = 0;
                        break;
                    }
                }
                if (canPlace) {
                    for (int j = 0; j < shipLengths[i]; j++) {
                        grid[row + j][col] = 'S';
                    }
                    placed = 1;
                }
            }
        }
    }
}

void playerTurn(char computerGrid[GRID_SIZE][GRID_SIZE], char guessGrid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    printf("Enter your guess (row and column): ");
    scanf("%d %d", &row, &col);
    if (computerGrid[row][col] == 'S') {
        printf("Hit! You hit a ship at (%d, %d)!\n", row, col);
        computerGrid[row][col] = 'X';
        guessGrid[row][col] = 'X';
    } else {
        printf("Miss! No ship at (%d, %d).\n", row, col);
        guessGrid[row][col] = 'O';
    }
}

void computerTurn(char playerGrid[GRID_SIZE][GRID_SIZE], int *lastHitRow, int *lastHitCol, int *hitMode) {
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
        computerGuessGrid[row][col] = 'X'; // Update computer's guess grid with 'X' for hit
        *lastHitRow = row;
        *lastHitCol = col;
        *hitMode = 1;
    } else {
        printf("Computer missed at (%d, %d).\n", row, col);
        playerGrid[row][col] = 'O';
        computerGuessGrid[row][col] = 'O'; // Update computer's guess grid with 'O' for miss
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

int main() {
    srand(time(NULL));

    initializeGrid(playerGrid);
    initializeGrid(computerGrid);
    initializeGrid(playerGuessGrid);
    initializeGrid(computerGuessGrid);

    int shipLengths[] = {5, 4, 3, 3, 2};
    int numShips = sizeof(shipLengths) / sizeof(shipLengths[0]);

    placeShipsManually(playerGrid, numShips);
    placeShipsRandomly(computerGrid, numShips, shipLengths);

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

        computerTurn(playerGrid, &lastHitRow, &lastHitCol, &hitMode);
        if (checkWin(playerGrid)) {
            printf("\nGame Over! Computer wins!\n");
            break;
        }
    }

    return 0;
}
