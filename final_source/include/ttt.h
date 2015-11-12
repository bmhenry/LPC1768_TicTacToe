#ifndef ttt_h
#define ttt_h

#include "GLCD.h"


#define LETTERDIM 35
#define SPACER 10
#define BOARD_WIDTH (SPACER * 2 + LETTERDIM) * 3 + 2
#define BOARD_HEIGHT BOARD_WIDTH

// assuming landscape mode
#ifdef BOARD_CENTERED
	#define H_OFFSET 15
	#define W_OFFSET 320/2 - BOARD_WIDTH/2
#else
	#define H_OFFSET 0
	#define W_OFFSET 0
#endif

#define ROW1 H_OFFSET + SPACER * 1
#define COL1 W_OFFSET + SPACER * 1
#define ROW2 H_OFFSET + SPACER * 3 + LETTERDIM + 1
#define COL2 W_OFFSET + SPACER * 3 + LETTERDIM + 1
#define ROW3 H_OFFSET + SPACER * 5 + LETTERDIM * 2 + 2
#define COL3 W_OFFSET + SPACER * 5 + LETTERDIM * 2 + 2

// globals:
static unsigned int rows[] = {0, ROW1, ROW2, ROW3};
static unsigned int cols[] = {0, COL1, COL2, COL3};

// point struct
typedef struct Point {
	unsigned int x;
	unsigned int y;
} Point;

// board is 3 rows, 3 columns
// starts at 0, 0 on the LCD

// redraw board, clearing any and all selections, Xs, & Os
extern void GLCD_DrawBoard(void);

// draw a shape in the given row:column of the board
extern void GLCD_DrawX(int row, int col);
extern void GLCD_DrawO(int row, int col);

// set whether a given box is shown as selected
// note: this simply draws the selection, but doesn't track it
//   	 any number of spots can be drawn as selected at once
extern void GLCD_DrawSelection(int row, int col);
extern void GLCD_ClearSelection(int row, int col);

#endif
