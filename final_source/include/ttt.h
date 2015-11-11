#ifndef ttt_h
#define ttt_h

#include "GLCD.h"


#define LETTERDIM 35
#define SPACER 10
#define BOARD_WIDTH (SPACER * 2 + LETTERDIM) * 3 + 2
#define BOARD_HEIGHT BOARD_WIDTH
#define H_OFFSET 0
#define W_OFFSET 0

#define ROW1 H_OFFSET + SPACER * 1
#define COL1 W_OFFSET + SPACER * 1
#define ROW2 H_OFFSET + SPACER * 3 + LETTERDIM + 1
#define COL2 W_OFFSET + SPACER * 3 + LETTERDIM + 1
#define ROW3 H_OFFSET + SPACER * 5 + LETTERDIM * 2 + 2
#define COL3 W_OFFSET + SPACER * 5 + LETTERDIM * 2 + 2


// starts at 0, 0
extern void GLCD_DrawBoard(void);

// 3 rows, 3 columns
extern void GLCD_DrawX(int row, int col);
// extern void GLCD_DrawO(int row, int col);
extern void GLCD_DrawSelection(int row, int col);
extern void GLCD_ClearSelection(int row, int col);

#endif
