/*****************************************************
This program was produced by the
CodeWizardAVR V1.24.4 Standard
Automatic Program Generator
? Copyright 1998-2004 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com
e-mail:office@hpinfotech.com

Project : 
Version : 
Date    : 7/6/2008
Author  : Osama                           
Company : OSAMA                           
Comments: 


Chip type           : ATmega32L
Program type        : Application
Clock frequency     : 8.000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 512

All copy rights are reserved to Osama's Lab - Refer to "License.txt"
*****************************************************/
#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include "Includes/graph.h"
#include "Includes/GLCD.h"
#include "Includes/seq2.h"

void main(void)
{
#pragma used+
int i,j;
byte read_data;
byte read_arr[30];
unsigned char str[] = "WELCOME";
unsigned char str2[] = "OSAMA SALAH";
unsigned char ArStr[] = "?????";
unsigned char ArStr2[] = "????? ???? ?????";
#pragma used-

DDRB=0x1F;

DATADDR = 0xff;
DDRD=0x80;
DDRC = 0x0F;


glcd_on();
glcd_clear();

h_line(3,5,12,0,1); //X0,Y0,Length,Space,Color
h_line(3,7,12,1,1); 

delay_ms(2000);
glcd_clear();   
v_line(5,3,11,1,1); 


delay_ms(2000);
glcd_clear();
line(16,16,127,63,0,1); //X1,Y1,X2,Y2,Spacing,Color
line(60,15,15,60,0,1); //X1,Y1,X2,Y2,Spacing,Color
line(0,0,127,63,0,1);
line(63,10,100,50,0,1);

v_line(63,5,20,0,1);

delay_ms(2000);
glcd_clear();
rectangle(8,8,70,50,0,1);
rectangle(10,10,68,48,0,1);
rectangle(12,12,66,46,0,1);
rectangle(14,14,64,44,0,1);  

delay_ms(2000);
glcd_clear();    
cuboid(73,13,93,33,87,27,107,47,1,1); 

delay_ms(2000);
glcd_clear();
v_parallelogram(60,10,83,50,20,0,1);

delay_ms(2000);
glcd_clear();                         
v_parallelepiped(10,15,30,48,48, 110,30,100,20,11,0,1);

delay_ms(2000);
glcd_clear();
v_parallelepiped(10,15,30,48,48, 60,30,70,30,11,0,1);
v_parallelepiped(10,15,30,48,48, 35,30,45,30,11,0,1);
v_parallelepiped(60,30,70,30,11, 110,15,120,48,48,0,1);
v_parallelepiped(90,30,100,30,11, 110,15,120,48,48,0,1);

delay_ms(2000);
glcd_clear();
circle(63,31,28,0,1);
circle(63,31,14,0,1);
v_line(63,4,55,0,1);
h_line(37,31,53,0,1); 

delay_ms(2000);
glcd_clear();               //clear GLCD
glcd_puts(str,0,0,0,0,1);       //Put an English string at column 0,row 0
glcd_puts(str2,40,3,0,0,1);     //put another English string at column 5,row 3
delay_ms(2000);             //wait a second
glcd_off();                 //Turn off display
delay_ms(2000);             //wait a second
glcd_on();                  //Turn on display
delay_ms(2000);             //wait a second
glcd_clrln(0);              //Clear the first line
glcd_puts(ArStr,120,0,1,0,1);   //Put an Arabic string at column 15,row 6
glcd_puts(ArStr2,120,6,1,0,1);  //Put another Arabic string at column 15,row 6

//delay_ms(2000);
while(1)
{
    for(j=0;j<4;j++)
    { 
        bmp_disp(seq2[j],0,0,127,7);
        delay_ms(250);
    }
    delay_ms(250);
    for(j=3;j>=0;j--)
    { 
        bmp_disp(seq2[j],0,0,127,7);
        delay_ms(250);        
    }           
    delay_ms(250); 
    bmp_disp(arr,0,0,127,7);
    for(j=0;j<64;j++)
    {
        set_start_line(j);
        delay_ms(100);
    }
}
}
