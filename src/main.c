#include "Dbl.h"

int main(void) {
    createBoard(8, 8);
    Board *board = (Board *)malloc(sizeof(Board));
    board->width = 8;
    board->height = 8;
    board->cells = (char **)malloc(board->height * sizeof(char *));
    for (int i = 0; i < board->height; i++) {
        board->cells[i] = (char *)malloc(board->width * sizeof(char));
        memset(board->cells[i], ' ', board->width);
    }
    printBoard(board);
    return 0;
}