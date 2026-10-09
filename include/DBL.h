#ifndef DBL_H
#define DBL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#define COLOR_COMPLEXITY 9
#define COLOR_AMOUNT 7

#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

#define ANSI_COLOR_BLACK_BG   "\x1b[40m"
#define ANSI_COLOR_RED_BG     "\x1b[41m"
#define ANSI_COLOR_GREEN_BG   "\x1b[42m"
#define ANSI_COLOR_YELLOW_BG  "\x1b[43m"
#define ANSI_COLOR_BLUE_BG    "\x1b[44m"
#define ANSI_COLOR_MAGENTA_BG "\x1b[45m"
#define ANSI_COLOR_CYAN_BG    "\x1b[46m"
#define ANSI_COLOR_WHITE_BG   "\x1b[47m"

#define ANSI_COLOR_BLACK_BRIGHT   "\x1b[90m"
#define ANSI_COLOR_RED_BRIGHT     "\x1b[91m"
#define ANSI_COLOR_GREEN_BRIGHT   "\x1b[92m"
#define ANSI_COLOR_YELLOW_BRIGHT  "\x1b[93m"
#define ANSI_COLOR_BLUE_BRIGHT    "\x1b[94m"
#define ANSI_COLOR_MAGENTA_BRIGHT "\x1b[95m"
#define ANSI_COLOR_CYAN_BRIGHT    "\x1b[96m"
#define ANSI_COLOR_WHITE_BRIGHT   "\x1b[97m"

#define ANSI_COLOR_BLACK_BRIGHT_BG   "\x1b[100m"
#define ANSI_COLOR_RED_BRIGHT_BG     "\x1b[101m"
#define ANSI_COLOR_GREEN_BRIGHT_BG   "\x1b[102m"
#define ANSI_COLOR_YELLOW_BRIGHT_BG  "\x1b[103m"
#define ANSI_COLOR_BLUE_BRIGHT_BG    "\x1b[104m"
#define ANSI_COLOR_MAGENTA_BRIGHT_BG "\x1b[105m"
#define ANSI_COLOR_CYAN_BRIGHT_BG    "\x1b[106m"
#define ANSI_COLOR_WHITE_BRIGHT_BG   "\x1b[107m

typedef struct {
    int width;
    int height;
    char **cells;
} Board;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    char symbol;
    char color[20];
} Piece;

typedef struct {
    Piece *pieces;
    int count;
} PieceList;

typedef struct {
    Board board;
    PieceList pieceList;
} GameState;

typedef struct {
    char *name;
    GameState gameState;
} Player;

typedef struct {
    Player *players;
    int count;
} PlayerList;

void createBoard(int width, int height);
void printBoard(Board *board);

#endif