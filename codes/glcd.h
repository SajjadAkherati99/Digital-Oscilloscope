#ifndef _GLCD_H_
#define _GLCD_H_

#include <stdarg.h>
#include "stdutils.h"
#include "delay.h"
#include "gpio.h"


#define    Enable_GLCD_ScrollMessage          0
#define    Enable_GLCD_DisplayString          1

#define    Enable_GLCD_DisplayNumber   		  1
#define    Enable_GLCD_DisplayFloatNumber     0
#define    Enable_GLCD_Printf                 1
#define    Enable_GLCD_DisplayLogo            0

#define    ENABLE_GLCD_DrawHoriLine           1
#define    ENABLE_GLCD_DrawVertLine           1
#define    ENABLE_GLCD_DrawLine               1
#define    ENABLE_GLCD_DrawRect               1
#define    ENABLE_GLCD_DrawFillRect           1
#define    ENABLE_GLCD_DrawRoundRect          1
#define    ENABLE_GLCD_GetXYData              1
#define    ENABLE_GLCD_DataRead               1
#define    ENABLE_GLCD_SetDot                 1
#define    ENABLE_GLCD_DisplayHorizontalGraph 1
#define    ENABLE_GLCD_DisplayLogo            1
#define    ENABLE_GLCD_DisplayVerticalGraph   1
#define    ENABLE_GLCD_InvertRect             1
#define    ENABLE_GLCD_DrawCircle             1
#define    ENABLE_GLCD_DrawFillCircle         1

#define	BLACK 1
#define WHITE 0

#define BlankSpace ' '

#define C_DisplayDefaultDigits_U8            0xffu 
#define C_MaxDigitsToDisplay_U8              10u   
#define C_NumOfBinDigitsToDisplay_U8         16u   
#define C_MaxDigitsToDisplayUsingPrintf_U8   C_DisplayDefaultDigits_U8

#define C_GlcdFirstLine_U8 0x00u
#define C_GlcdLastLine_U8 0x07u
#define C_FirstLineNumberAddress_U8 0xB8
#define C_LastLineNumberAddress_U8  0xBF

#define C_MaxBarGraphs_U8 0x04
#define C_LookUpOffset_U8 0x20



typedef struct
{
    uint8_t PageNum;
    uint8_t LineNum;
    uint8_t CursorPos;
    uint8_t InvertDisplay;
    gpioPins_et RS;
    gpioPins_et RW;
    gpioPins_et EN;
	  gpioPins_et CS1;
    gpioPins_et CS2;
    gpioPins_et D0;
    gpioPins_et D1;
    gpioPins_et D2;
    gpioPins_et D3;
    gpioPins_et D4;
    gpioPins_et D5;
    gpioPins_et D6;
    gpioPins_et D7;
}Glcd_Config_st;



void GLCD_Init(void);
void GLCD_Clear(void);
void GLCD_SetDot(uint8_t , uint8_t , uint8_t );
void GLCD_GoToPage(uint8_t pageNumber);
void GLCD_GoToLine(uint8_t var_lineNumber_u8);
void GLCD_GoToNextLine(void);
uint8_t GLCD_DataRead(void);
void GLCD_SetCursor(uint8_t pageNumber,uint8_t lineNumber,uint8_t CursorPosition);
uint8_t GLCD_GetXYData(uint8_t x, uint8_t y);
void GLCD_DrawHoriLine(uint8_t var_x_u8, uint8_t var_y_u8, uint8_t var_length_u8,uint8_t var_color_u8);
void GLCD_DrawVertLine(uint8_t var_x_u8, uint8_t var_y_u8, uint8_t var_length_u8,uint8_t var_color_u8);

void GLCD_SetUp(
	      gpioPins_et RS,
        gpioPins_et RW,
        gpioPins_et EN,
	      gpioPins_et CS1,
        gpioPins_et CS2,
        gpioPins_et D0,
        gpioPins_et D1,
        gpioPins_et D2,
        gpioPins_et D3,
        gpioPins_et D4,
        gpioPins_et D5,
        gpioPins_et D6,
        gpioPins_et D7 );


#endif

