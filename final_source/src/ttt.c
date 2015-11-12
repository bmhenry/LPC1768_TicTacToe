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

			else
				GLCD_ClearPixel(w, h);
		}
	}
}


void GLCD_DrawX(int row, int col)
{
	int w, h;

	for (w = 0; w < LETTERDIM; w++)
	{
		for (h = 0; h < LETTERDIM; h++)
		{
			if (w == h || w + h == LETTERDIM - 1)
				GLCD_PutPixel(w + cols[col], h + rows[row]);
		}
	}
}

void GLCD_DrawO(int row, int col)
{
	Point points[] = {
		{0,17}, {0,16}, {0,15}, {0,14}, {0,13},
		{1,12}, {1,11}, {1,10},
		{2,10}, {2, 9}, {2, 8},
		{3, 8}, {3, 7},
		{4, 6}, 
		{5, 5}, 
		{6, 4},
		{7, 3}, {8, 3},
		{8, 2}, {9, 2}, {10,2},
		{10,1}, {11,1}, {12,1},
		{13,0}, {14,0}, {15,0}, {16,0}, {17,0}
	};
	int len_points = 29;
	int i;

	for (i = 0; i < len_points; i++)
	{
		// upper left quadrant
		GLCD_PutPixel(rows[row] + points[i].x, cols[col] + points[i].y);
		// upper right
		GLCD_PutPixel(rows[row] + LETTERDIM - points[i].x, cols[col] + points[i].y);
		// lower left
		GLCD_PutPixel(rows[row] + points[i].x, cols[col] + LETTERDIM - points[i].y);
		// lower right
		GLCD_PutPixel(rows[row] + LETTERDIM - points[i].x, cols[col] + LETTERDIM - points[i].y);
	}
}

void GLCD_DrawSelection(int row, int col)
{
	int w, h;

	for (w = 0; w < LETTERDIM + 6; w++)
	{
		for (h = 0; h < LETTERDIM + 6; h++)
		{
			if (w == 0 || h == 0 || w == LETTERDIM + 5 || h == LETTERDIM + 5)
				GLCD_SetPixel(w + cols[col] - 3, h + rows[row] - 3, Red);
		}
	}
}

void GLCD_ClearSelection(int row, int col)
{
	int w, h;

	for (w = 0; w < LETTERDIM + 6; w++)
	{
		for (h = 0; h < LETTERDIM + 6; h++)
		{
			if (w == 0 || h == 0 || w == LETTERDIM + 5 || h == LETTERDIM + 5)
				GLCD_ClearPixel(w + cols[col] - 3, h + rows[row] - 3);
		}
	}
}
