#include "ttt.h"


void GLCD_DrawBoard(void)
{
	int w, h;
	for (w = 0 + W_OFFSET; w < BOARD_WIDTH + W_OFFSET; w++)
	{
		for (h = 0 + H_OFFSET; h < BOARD_HEIGHT + H_OFFSET; h++)
		{
			if (w == (SPACER * 2 + LETTERDIM + 1 + W_OFFSET) || w == ((SPACER * 2 + LETTERDIM) * 2 + 1 + W_OFFSET) )
				GLCD_PutPixel(w, h);

			if (h == (SPACER * 2 + LETTERDIM + 1 + H_OFFSET) || h == ((SPACER * 2 + LETTERDIM) * 2 + 1 + H_OFFSET) )
				GLCD_PutPixel(w, h);
		}
	}
}


void GLCD_DrawX(int row, int col)
{
	int rows[] = {ROW1, ROW2, ROW3};
	int cols[] = {COL1, COL2, COL3};

	int w, h;

	for (w = 0; w < LETTERDIM; w++)
	{
		for (h = 0; h < LETTERDIM; h++)
		{
			if (w == h || w + h == LETTERDIM - 1)
				GLCD_PutPixel(w + cols[col - 1], h + rows[row - 1]);
		}
	}
}

void GLCD_DrawSelection(int row, int col)
{
	int rows[] = {ROW1, ROW2, ROW3};
	int cols[] = {COL1, COL2, COL3};

	int w, h;

	for (w = 0; w < LETTERDIM + 6; w++)
	{
		for (h = 0; h < LETTERDIM + 6; h++)
		{
			if (w == 0 || h == 0 || w == LETTERDIM + 5 || h == LETTERDIM + 5)
				GLCD_SetPixel(w + cols[col - 1] - 3, h + rows[row - 1] - 3, Red);
		}
	}
}

void GLCD_ClearSelection(int row, int col)
{
	int rows[] = {ROW1, ROW2, ROW3};
	int cols[] = {COL1, COL2, COL3};

	int w, h;

	for (w = 0; w < LETTERDIM + 6; w++)
	{
		for (h = 0; h < LETTERDIM + 6; h++)
		{
			if (w == 0 || h == 0 || w == LETTERDIM + 5 || h == LETTERDIM + 5)
				GLCD_SetPixel(w + cols[col - 1] - 3, h + rows[row - 1] - 3, GLCD_GetBgColor());
		}
	}
}
