#include "Dbl.h"

void createBoard(int width, int height) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->width = width;
    board->height = height;

    // Allocate memory for the cells
    board->cells = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        board->cells[i] = (char *)malloc(width * sizeof(char));
        memset(board->cells[i], ' ', width); // Initialize cells with spaces
    }

    printBoard(board);

    // Free allocated memory
    for (int i = 0; i < height; i++) {
        free(board->cells[i]);
    }
    free(board->cells);
    free(board);
}

void printBoard(Board *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%c ", board->cells[i][j]);
        }
        printf("\n");
    }
}