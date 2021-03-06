#include "cmsis_os.h"
#include "lpc17xx.h"
#include "GLCD.h"
#include "stdio.h"
#include "ttt.h"

// center the board
//#define BOARD_CENTERED 1

int main()
{	
	GLCD_Init();
	GLCD_Clear(White);
	
	alt_drawboard();
	GLCD_DrawX(1, 1);
	GLCD_DrawX(2, 2);
	GLCD_DrawX(3, 3);
	GLCD_DrawO(1, 3);
	GLCD_DrawO(3, 1);
	
	GLCD_DrawSelection(2, 2);
	GLCD_ClearSelection(2, 2);
	GLCD_DrawSelection(1, 1);
	
	while (1){}
}
