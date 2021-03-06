#include "delay.h"
#include "gpio.h"
#include <stdlib.h>


typedef unsigned char uchar;
typedef unsigned int  uint;


//////////////////// Define
#define E_DELAY 3
//////////////////// Define


//////////////////// Font
uchar font[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //0/ -->
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //1/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //2/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //3/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //4/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //5/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //6/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //7/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //8/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //9/ -->
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //10/ -->
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //11/ -->
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //12/ -->
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //13/ -->  Problem 2
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //14/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //15/ --> 
0x20,0x20,0x28,0x28,0x68,0xB0,0x60,0x20, //16/ --> 
0x20,0x20,0x28,0x2A,0x28,0x30,0x20,0x20, //17/ --> 
0x00,0x80,0x80,0x44,0x32,0x24,0x20,0x20, //18/ --> 
0x00,0x24,0x24,0x24,0x38,0x20,0x20,0x20, //19/ --> 
0x20,0x20,0x20,0x20,0x24,0x2A,0x11,0x00, //20/ --> 
0x20,0x20,0x20,0x24,0x2A,0x11,0x20,0x20, //21/ --> 
0x30,0x20,0x20,0x20,0x24,0x2A,0x11,0x20, //22/ --> 
0x20,0x20,0x30,0x20,0x30,0x28,0x28,0x18, //23/ --> 
0x20,0x24,0x22,0x21,0x24,0x2A,0x11,0x00, //24/ --> 
0x24,0x22,0x21,0x24,0x2A,0x11,0x20,0x20, //25/ --> 
0x30,0x24,0x22,0x21,0x24,0x2A,0x11,0x20, //26/ --> SUB
0x00,0x80,0x80,0x40,0x30,0x20,0x20,0x20, //27/ --> 
0x20,0x20,0x20,0x60,0xA0,0x60,0x28,0x30, //28/ --> 
0x20,0x20,0x20,0x60,0xB0,0x60,0x20,0x20, //29/ --> 
0x00,0x30,0x28,0x60,0xA0,0x60,0x30,0x20, //30/ --> 
0x00,0x04,0x06,0x1D,0x25,0x24,0x20,0x20, //31/ --> 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //32/ -->
0x00,0x00,0x4F,0x00,0x00,0x00,0x00,0x00, //33/ --> !
0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00, //34/ --> "
0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00, //35/ --> #
0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00, //36/ --> $
0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00, //37/ --> %
0x00,0x36,0x49,0x55,0x22,0x40,0x00,0x00, //38/ --> &
0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00, //39/ --> '
0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00, //40/ --> (
0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00, //41/ --> )
0x00,0x14,0x08,0x3E,0x08,0x14,0x00,0x00, //42/ --> *
0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00, //43/ --> +
0x00,0x00,0x28,0x18,0x00,0x00,0x00,0x00, //44/ --> ,
0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x00, //45/ --> -
0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00, //46/ --> .
0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00, //47/ --> /
0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00, //48/ --> 0
0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00, //49/ --> 1
0x00,0x42,0x61,0x51,0x49,0x46,0x00,0x00, //50/ --> 2
0x00,0x21,0x41,0x45,0x4B,0x31,0x00,0x00, //51/ --> 3
0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00, //52/ --> 4
0x00,0x00,0x27,0x45,0x45,0x45,0x39,0x00, //53/ --> 5
0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00, //54/ --> 6
0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00, //55/ --> 7
0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00, //56/ --> 8
0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00, //57/ --> 9
0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00, //58/ --> :
0x00,0x00,0x56,0x36,0x00,0x00,0x00,0x00, //59/ --> ;
0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00, //60/ --> <
0x00,0x24,0x24,0x24,0x24,0x24,0x00,0x00, //61/ --> =
0x00,0x00,0x41,0x22,0x14,0x08,0x00,0x00, //62/ --> >
0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00, //63/ --> ?
0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00, //64/ --> @
0x00,0x7E,0x11,0x11,0x11,0x7E,0x00,0x00, //65/ --> A
0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00, //66/ --> B
0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00, //67/ --> C
0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00, //68/ --> D
0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00, //69/ --> E
0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00, //70/ --> F
0x00,0x3E,0x41,0x49,0x49,0x3A,0x00,0x00, //71/ --> G
0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00, //72/ --> H
0x00,0x00,0x41,0x7F,0x41,0x00,0x00,0x00, //73/ --> I
0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00, //74/ --> J
0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00, //75/ --> K
0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00, //76/ --> L
0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00, //77/ --> M
0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00, //78/ --> N
0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00, //79/ --> O
0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00, //80/ --> P
0x3E,0x41,0x51,0x21,0x5E,0x00,0x00,0x00, //81/ --> Q
0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00, //82/ --> R
0x00,0x46,0x49,0x49,0x49,0x31,0x00,0x00, //83/ --> S
0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00, //84/ --> T
0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00, //85/ --> U
0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00, //86/ --> V
0x00,0x3F,0x40,0x60,0x40,0x3F,0x00,0x00, //87/ --> W
0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00, //88/ --> X
0x00,0x07,0x08,0x70,0x08,0x07,0x00,0x00, //89/ --> Y
0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00, //90/ --> Z
0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00, //91/ --> [
0x00,0x15,0x16,0x7C,0x16,0x15,0x00,0x00, //92/ --> '\'
0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00, //93/ --> ]
0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00, //94/ --> ^
0x00,0x40,0x40,0x40,0x40,0x40,0x00,0x00, //95/ --> _
0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00, //96/ --> `
0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00, //97/ --> a
0x00,0x7F,0x44,0x44,0x44,0x38,0x00,0x00, //98/ --> b
0x00,0x38,0x44,0x44,0x44,0x00,0x00,0x00, //99/ --> c
0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00, //100/ --> d
0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00, //101/ --> e
0x00,0x10,0x7E,0x11,0x01,0x02,0x00,0x00, //102/ --> f
0x00,0x0C,0x52,0x52,0x52,0x3E,0x00,0x00, //103/ --> g
0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00, //104/ --> h
0x00,0x00,0x44,0x7D,0x40,0x00,0x00,0x00, //105/ --> i
0x00,0x20,0x40,0x40,0x3D,0x00,0x00,0x00, //106/ --> j
0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00, //107/ --> k
0x00,0x00,0x41,0x7F,0x40,0x00,0x00,0x00, //108/ --> l
0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00, //109/ --> m
0x00,0x7C,0x08,0x04,0x04,0x78,0x00,0x00, //110/ --> n
0x00,0x38,0x44,0x44,0x44,0x38,0x00,0x00, //111/ --> o
0x00,0x7C,0x14,0x14,0x14,0x08,0x00,0x00, //112/ --> p
0x00,0x08,0x14,0x14,0x18,0x7C,0x00,0x00, //113/ --> q
0x00,0x7C,0x08,0x04,0x04,0x08,0x00,0x00, //114/ --> r
0x00,0x48,0x54,0x54,0x54,0x20,0x00,0x00, //115/ --> s
0x00,0x04,0x3F,0x44,0x40,0x20,0x00,0x00, //116/ --> t
0x00,0x3C,0x40,0x40,0x20,0x7C,0x00,0x00, //117/ --> u
0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00, //118/ --> v
0x00,0x1E,0x20,0x10,0x20,0x1E,0x00,0x00, //119/ --> w
0x00,0x22,0x14,0x08,0x14,0x22,0x00,0x00, //120/ --> x
0x00,0x06,0x48,0x48,0x48,0x3E,0x00,0x00, //121/ --> y
0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00, //122/ --> z
0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00, //123/ --> {
0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00, //124/ --> |
0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00, //125/ --> }
0x00,0x08,0x08,0x2A,0x1C,0x08,0x00,0x00, //126/ --> ~
0x00,0x08,0x1C,0x2A,0x08,0x08,0x00,0x00, //127/ --> 
0x00,0x3C,0x42,0x41,0x42,0x3C,0x00,0x00, //128/ --> ???
0x00,0x30,0x28,0x60,0xA0,0x60,0x28,0x30, //129/ --> ??
0x20,0x20,0x20,0x20,0xA0,0x20,0x28,0x30, //130/ --> ???
0x20,0x20,0x20,0x20,0xB0,0x20,0x20,0x20, //131/ --> ??
0x00,0x30,0x28,0x20,0xA0,0x20,0x30,0x20, //132/ --> ???
0x20,0x20,0x20,0x22,0x20,0x22,0x28,0x30, //133/ --> ???
0x20,0x20,0x20,0x22,0x30,0x22,0x20,0x20, //134/ --> ???
0x00,0x30,0x28,0x22,0x20,0x22,0x30,0x20, //135/ --> ???
0x20,0x20,0x20,0x22,0x21,0x22,0x28,0x30, //136/ --> ??
0x20,0x20,0x20,0x22,0x31,0x22,0x20,0x20, //137/ --> ???
0x00,0x30,0x28,0x22,0x21,0x22,0x30,0x20, //138/ --> ??
0x20,0x20,0x28,0x28,0x28,0xB0,0x20,0x20, //139/ --> ???
0x20,0x20,0x28,0x28,0x28,0x30,0x20,0x20, //140/ --> ??
0x00,0xC0,0xA8,0x28,0x68,0xB0,0x60,0x20, //141/ --> ??
0x00,0x00,0x80,0x80,0x44,0x32,0x04,0x00, //142/ --> ??
0x00,0x24,0x25,0x24,0x38,0x20,0x20,0x20, //143/ --> ??
0x30,0x24,0x22,0x21,0x24,0x2A,0x11,0x00, //144/ --> ??
0x00,0x80,0x80,0x40,0x34,0x20,0x20,0x20, //145/ --> ???
0x20,0x20,0x20,0x38,0x20,0x38,0x20,0x18, //146/ --> ???
0x20,0x20,0x38,0x20,0x38,0x20,0x38,0x20, //147/ --> ???
0x60,0x80,0x80,0x78,0x20,0x38,0x20,0x18, //148/ --> ???
0x20,0x20,0x20,0x38,0x22,0x39,0x22,0x18, //149/ --> ???
0x20,0x20,0x38,0x22,0x39,0x22,0x38,0x20, //150/ --> ???
0x60,0x80,0x80,0x78,0x22,0x39,0x22,0x18, //151/ --> ???
0x30,0x20,0x20,0x20,0x24,0x2A,0x11,0x00, //152/ --> ??
0x20,0x30,0x20,0x30,0x28,0x28,0x38,0x20, //153/ --> ???
0x60,0x80,0x80,0x60,0x30,0x28,0x28,0x38, //154/ --> ??
0x20,0x20,0x30,0x20,0x30,0x28,0x2A,0x18, //155/ --> ???
0x20,0x30,0x20,0x30,0x28,0x2A,0x38,0x20, //156/ --> ??
0x60,0x80,0x80,0x60,0x30,0x28,0x2A,0x38, //157/ --> ???
0x20,0x20,0x3E,0x30,0x28,0x28,0x38,0x20, //158/ --> ???
0x20,0x20,0x3E,0x30,0x28,0x2A,0x38,0x20, //159/ --> ??
0x20,0x20,0x20,0x20,0x30,0x28,0x28,0x00, //160/ -->
0x20,0x20,0x20,0x30,0x28,0x28,0x20,0x20, //161/ --> ??
0x00,0x40,0xA0,0xB0,0x28,0x28,0x20,0x20, //162/ --> ??
0x20,0x20,0x20,0x20,0x30,0x28,0x2A,0x00, //163/ --> ??
0x20,0x20,0x20,0x30,0x28,0x2A,0x20,0x20, //164/ --> ??
0x00,0x40,0xA0,0xB0,0x28,0x2A,0x20,0x20, //165/ --> ??
0x20,0x20,0x20,0x20,0x30,0x28,0x2A,0x30, //166/ --> ??
0x20,0x20,0x30,0x28,0x2A,0x30,0x20,0x20, //167/ --> ??
0x00,0x18,0x20,0x20,0x30,0x28,0x2A,0x30, //168/ --> ??
0x20,0x20,0x20,0x20,0x30,0x2A,0x28,0x32, //169/ --> ??
0x20,0x20,0x30,0x2A,0x28,0x32,0x20,0x20, //170/ --> ??
0x60,0x80,0x80,0xB2,0xA8,0x7A,0x20,0x20, //171/ --> ??
0x22,0x25,0x25,0x25,0x25,0x25,0x25,0x19, //172/ --> ??
0x20,0x20,0x20,0x1C,0x22,0x21,0x20,0x20, //173/ --> ??
0x30,0x28,0x2C,0x2A,0x20,0x3F,0x20,0x20, //174/ --> ??
0x20,0x20,0x20,0x20,0x20,0x20,0x1F,0x00, //175/ --> ??
0x20,0x20,0x20,0x20,0x1F,0x20,0x20,0x20, //176/ --> ??
0x00,0x30,0x40,0x40,0x3F,0x20,0x20,0x20, //177/ --> ??
0x20,0x20,0x20,0x20,0x30,0x48,0x48,0x30, //178/ --> ??
0x20,0x20,0x30,0x48,0x48,0x30,0x20,0x20, //179/ --> ??
0x80,0x40,0x30,0x48,0x48,0x30,0x20,0x20, //180/ --> ??
0x20,0x20,0x20,0x20,0x22,0x20,0x18,0x00, //181/ --> ??
0x20,0x20,0x20,0x20,0x1A,0x20,0x20,0x20, //182/ --> ??
0x30,0x40,0x44,0x40,0x30,0x20,0x20,0x20, //183/ --> ??
0x20,0x20,0x20,0x30,0x28,0x3A,0x2C,0x18, //184/ --> ??
0x20,0x20,0x30,0x28,0x3A,0x2C,0x38,0x20, //185/ --> ??
0x00,0x18,0x14,0x14,0x18,0x20,0x20,0x20, //186/ --> ??
0x00,0x21,0x22,0x24,0x28,0x10,0x0F,0x00, //187/ --> ??
0x00,0xB0,0xA8,0x78,0x20,0x20,0x20,0x20, //188/ --> ??
0x20,0x20,0x20,0xA0,0x20,0xA0,0x28,0x30, //189/ --> ??
0x20,0x20,0x20,0xA0,0x30,0xA0,0x20,0x20, //190/ --> ??
0x00,0x60,0x80,0x80,0xA0,0x50,0x10,0x20, //191/ --> ??
0x00,0x1E,0x20,0x20,0x20,0x20,0x20,0x20, //192/ --> ??
0x00,0x20,0x30,0x28,0x28,0x20,0x00,0x00, //193/ --> ??
0x00,0x04,0x02,0x02,0x3A,0x02,0x02,0x01, //194/ --> ??
0x00,0x00,0x04,0x06,0x3D,0x05,0x04,0x00, //195/ --> ??
0x00,0x00,0x04,0xB6,0xAD,0x7D,0x04,0x00, //196/ --> ??
0x00,0x00,0x80,0xC0,0xBF,0xA0,0x80,0x00, //197/ --> ??
0x04,0x66,0x85,0x95,0xA8,0xA8,0x48,0x00, //198/ --> ??
0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00, //199/ --> ??
0x00,0x30,0x28,0x20,0xA0,0x20,0x28,0x30, //200/ --> ??
0x00,0x00,0x30,0x2A,0x28,0x32,0x00,0x00, //201/ --> ??
0x00,0x30,0x28,0x22,0x20,0x22,0x28,0x30, //202/ --> ??
0x00,0x30,0x28,0x22,0x21,0x22,0x28,0x30, //203/ --> ??
0x00,0xC0,0xA8,0xA8,0x28,0xB0,0x20,0x20, //204/ --> ??
0x00,0xC0,0xA8,0xA8,0xA8,0x30,0x20,0x20, //205/ --> ??
0x00,0xC0,0xA8,0xAA,0x28,0x30,0x20,0x20, //206/ --> ??
0x00,0x00,0x24,0x24,0x24,0x38,0x00,0x00, //207/ --> ??
0x00,0x00,0x24,0x25,0x24,0x38,0x00,0x00, //208/ --> ??
0x00,0x80,0x80,0x40,0x30,0x00,0x00,0x00, //209/ --> ??
0x00,0x00,0x80,0x80,0x40,0x34,0x00,0x00, //210/ --> ??
0x60,0x80,0x80,0x78,0x20,0x38,0x20,0x18, //211/ --> ??
0x60,0x80,0x80,0x78,0x22,0x39,0x22,0x18, //212/ --> ??
0x60,0x80,0x80,0x60,0x30,0x28,0x28,0x18, //213/ --> ??
0x60,0x80,0x80,0x60,0x30,0x28,0x2A,0x18, //214/ --> ??
0x00,0x22,0x14,0x08,0x14,0x22,0x00,0x00, //215/ --> ??
0x20,0x20,0x3E,0x30,0x28,0x28,0x18,0x00, //216/ --> ??
0x20,0x20,0x3E,0x30,0x28,0x2A,0x18,0x00, //217/ --> ??
0x00,0x00,0x40,0xA0,0xB0,0x28,0x28,0x00, //218/ --> ??
0x00,0x00,0x40,0xA0,0xB0,0x2A,0x28,0x00, //219/ --> ??
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20, //220/ --> ??
0x00,0x18,0x20,0x20,0x30,0x28,0x2A,0x30, //221/ --> ??
0x00,0x60,0x80,0x80,0xB2,0xA8,0x7A,0x00, //222/ --> ??
0x00,0x30,0x28,0x2C,0x2A,0x20,0x3F,0x00, //223/ --> ??
0x00,0x40,0xA9,0xAA,0xA8,0xF0,0x00,0x00, //224/ --> ??
0x00,0x00,0x60,0x80,0x80,0x7E,0x00,0x00, //225/ --> ??
0x00,0x40,0xAA,0xA9,0xAA,0xF0,0x00,0x00, //226/ --> ??
0x00,0x00,0xC0,0x20,0x30,0x28,0x28,0x30, //227/ --> ??
0x00,0x00,0x60,0x80,0x88,0x80,0x60,0x00, //228/ --> ??
0x00,0x00,0x30,0x28,0x28,0x30,0x00,0x00, //229/ --> ??
0x00,0x00,0x00,0xB0,0xA8,0x78,0x00,0x00, //230/ --> ??
0x04,0x26,0x25,0x25,0x28,0x10,0x0F,0x00, //231/ --> ??
0x04,0x22,0x22,0x26,0x29,0x10,0x0F,0x00, //232/ --> ??
0x00,0x21,0x22,0x24,0xA8,0xD0,0xAF,0xA0, //233/ --> ??
0x00,0x70,0xAA,0xA9,0xAA,0x30,0x00,0x00, //234/ --> ??
0x00,0x70,0xAA,0xA8,0xAA,0x30,0x00,0x00, //235/ --> ??
0x00,0x30,0x40,0x40,0x50,0x28,0x08,0x00, //236/ --> ??
0x00,0x30,0xC0,0x40,0xD0,0x28,0x08,0x00, //237/ --> ??
0x00,0x00,0x02,0x79,0x02,0x00,0x00,0x00, //238/ --> ??
0x00,0x00,0x02,0x78,0x02,0x00,0x00,0x00, //239/ --> ??
0x00,0x00,0x00,0x00,0x00,0x05,0x05,0x05, //240/ --> ??
0x00,0x00,0x00,0x04,0x03,0x0B,0x06,0x06, //241/ --> ??
0xA0,0xA0,0xA0,0x00,0x00,0x00,0x00,0x00, //242/ --> ??
0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00, //243/ --> ??
0x00,0x21,0x22,0x24,0x28,0x10,0x2F,0x20, //244/ --> ??
0x00,0x00,0x00,0x00,0x00,0x04,0x03,0x03, //245/ --> ??
0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00, //246/ --> ??
0x00,0x00,0x10,0x10,0x54,0x10,0x10,0x00, //247/ --> ??
0x00,0x00,0x02,0x04,0x02,0x04,0x02,0x00, //248/ --> ??
0x20,0x24,0x26,0x25,0x25,0x20,0x28,0x30, //249/ --> ??
0x20,0x24,0x26,0x25,0x35,0x20,0x20,0x20, //250/ --> ??
0x08,0x6C,0x8A,0x8A,0xA0,0x50,0x10,0x20, //251/ --> ??
0x04,0xB6,0xAD,0x7D,0x24,0x20,0x20,0x20, //252/ --> ??
0x00,0x19,0x14,0x15,0x18,0x20,0x20,0x20, //253/ --> ???
0x04,0x02,0x02,0x1A,0x22,0x22,0x21,0x20, //254/ --> ???
0x00,0x40,0x60,0x50,0x48,0x50,0x40,0x40 //255/ --> ??
};
uchar map[62][6] = {
{193,193,193,193,0,0},
{194,194,254,254,1,0},
{195,195,31,31,1,0},
{196,196,252,252,1,0},
{197,197,197,197,1,1},
{198,189,191,190,1,1},
{199,199,192,192,1,0},
{200,130,132,131,1,1},
{201,201,253,253,1,0},
{202,133,135,134,1,1},
{203,136,138,137,1,1},
{204,139,204,139,1,1},
{205,140,205,140,1,1},
{206,17,206,17,1,1},
{207,207,19,19,1,0},
{208,208,143,143,1,0},
{209,209,27,27,1,0},
{210,210,145,145,1,0},
{211,146,148,147,1,1},
{212,149,151,150,1,1},
{213,23,154,153,1,1},
{214,155,157,156,1,1},
{215,215,215,215,0,0},
{216,216,158,158,1,1},
{217,217,159,159,1,1},
{218,160,162,161,1,1},
{219,163,165,164,1,1},
{220,220,220,220,0,0},
{221,166,168,167,1,1},
{222,169,171,170,1,1},
{223,172,174,173,1,1},
{224,224,224,224,0,0},
{225,175,177,176,1,1},
{226,226,226,226,0,0},
{227,178,180,179,1,1},
{228,181,183,182,1,1},
{229,184,186,185,1,1},
{230,230,188,188,1,0},
{231,231,231,231,0,0},
{232,232,232,232,0,0},
{233,233,233,233,0,0},
{234,234,234,234,0,0},
{235,235,235,235,0,0},
{236,189,191,190,1,1},
{237,189,191,190,1,1},
{238,238,238,238,0,0},
{239,239,239,239,0,0},
{240,240,240,240,0,0},
{241,241,241,241,0,0},
{242,242,242,242,0,0},
{243,243,243,243,0,0},
{245,245,245,245,0,0},
{246,246,246,246,0,0},
{247,247,247,247,0,0},
{248,248,248,248,0,0},
{251,249,251,250,1,1},
{187,187,244,244,1,0},
{129,28,30,29,1,1},
{144,24,26,25,1,1},
{152,20,22,21,1,1},
{142,142,18,18,1,0},
{141,16,141,16,1,1}
};
//////////////////// Font


//////////////////// Variable
uchar _DB0, _DB1, _DB2, _DB3, _DB4, _DB5, _DB6, _DB7, _RW, _EN, _CS1, _CS2, _DI_RS;
//--------Arabic
static int prevLet = 193;
static uchar stat = 0;
static uchar prevX = 0;
static uchar prevY = 0;
//--------Arabic
//////////////////// Variable


//////////////////// Function Define
uchar strlen( uchar *Value );
uchar max( uchar Val1, uchar Val2 );
uchar min( uchar Val1, uchar Val2 );
double powerOfTen(int num);
double sqrt(double a);

void setDataPinValue( uchar Value );
void setDataPinMode( uchar Value );
uchar getDataPinValue( void );

void glcd_on( uchar DI_RS, uchar RW, uchar EN, uchar DB0, uchar DB1, uchar DB2, uchar DB3, uchar DB4, uchar DB5, uchar DB6, uchar DB7, uchar CS1, uchar CS2 );
void glcd_off(void);
void trigger(void);
void set_start_line( uchar line );
void goto_col( uint x );
void goto_row( uint y );
void goto_xy( uint x, uint y );
void glcd_write( uchar b );
void glcd_clrln( uchar ln );
void glcd_clear( void );
uchar is_busy(void);
uchar glcd_read( uchar column );
uchar get_point(uint x,uint y);
void point_at( uint x, uint y, uchar color );
void h_line( uint x, uint y, uchar l, uchar s, uchar c );
void v_line( uint x, uint y, uint l, uchar s, uchar c );
void line( uint x1, uint y1, uint x2, uint y2, uchar s, uchar c );
void rectangle( uint x1, uint y1, uint x2, uint y2, uchar s, uchar c, uchar EorF/*empty(0) or full(1) circle*/ );
void cuboid( uint x11, uint y11, uint x12, uint y12, uint x21, uint y21, uint x22, uint y22, uchar s, uchar c );
void h_parallelogram( uint x1, uint y1, uint x2, uint y2, uchar l, uchar s, uchar c );
void v_parallelogram( uint x1, uint y1, uint x2, uint y2, uchar l, uchar s, uchar c );
void h_parallelepiped( uint x11, uint y11, uint x12, uint y12, uchar l1, uint x21, uint y21, uint x22, uint y22, uchar l2, uchar s, uchar c );
void v_parallelepiped( uint x11, uint y11, uint x12, uint y12, uchar l1, uint x21, uint y21, uint x22, uint y22, uchar l2, uchar s, uchar c );
void circle( uint x0, uint y0, uint r, uchar s, uchar c );
void putIt( int c, int x, int y );
void enlarge( char *large, uchar c, uchar size );
void putItSz( int c, int x, int y, uchar sz );
void glcd_putchar( uchar c, int x, int y, uchar l, uchar sz );
void glcd_puts( uchar *c, int x, int y, uchar l, uchar sz, signed char space );
void glcd_printNumber( uint data, uint base, uint x, uint y, uchar l, uchar sz, char space );
void bmp_disp( uchar *bmp, uint x1, uint y1, uint x2, uint y2 );
//////////////////// Function Define


//////////////////// Function
uchar strlen( uchar *Value ) {
	uchar i;
	for( i=0; Value[i] != '\0'; i++ );
	return (i+1);
}
uchar max( uchar Val1, uchar Val2 ) {
	return ( 1 ? Val1>Val2 : 0);
}
uchar min( uchar Val1, uchar Val2 ) {
	return ( 0 ? Val1>Val2 : 1);
}
double powerOfTen(int num) {
	double rst = 1.0;
	int i;
	
	if(num >= 0) {
		for(i = 0; i < num ; i++) rst *= 10.0;
	}
	else {
		for(i = 0; i < (0 - num ); i++) rst *= 0.1;
	}
	
	return rst;
}
double sqrt(double a) {
	double z = a, rst = 0.0, j = 1.0; 
	int max = 8, i;     // to define maximum digit 

	for(i = max ; i > 0 ; i--) {   
		if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0) // value must be bigger then 0
		{
			while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
			{
				j++;
				if(j >= 10) break;
			}
			
			j--; //correct the extra value by minus one to j
			z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z
			rst += j * powerOfTen(i);     // find sum of a
			j = 1.0;
		}
	}

	for(i = 0 ; i >= 0 - max ; i--) {
		if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0) {
			while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0) j++;
			j--;
			z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z
			rst += j * powerOfTen(i);     // find sum of a
			j = 1.0;
		}
	}
	
	// find the number on each digit
	return rst;
}
void setDataPinValue( uchar Value ) {
	digitalWrite( _DB0, Value&0x01 );
	digitalWrite( _DB1, Value&0x02 );
	digitalWrite( _DB2, Value&0x04 );
	digitalWrite( _DB3, Value&0x08 );
	digitalWrite( _DB4, Value&0x10 );
	digitalWrite( _DB5, Value&0x20 );
	digitalWrite( _DB6, Value&0x40 );
	digitalWrite( _DB7, Value&0x80 );
}
void setDataPinMode( uchar Value ) { // 1 = OutPut, 0 = InPut
	pinMode( _DB0, Neither, Value );
	pinMode( _DB1, Neither, Value );
	pinMode( _DB2, Neither, Value );
	pinMode( _DB3, Neither, Value );
	pinMode( _DB4, Neither, Value );
	pinMode( _DB5, Neither, Value );
	pinMode( _DB6, Neither, Value );
	pinMode( _DB7, Neither, Value );
}
uchar getDataPinValue( void ) {
	return ( (digitalRead(_DB7)<<7) | (digitalRead(_DB6)<<6) | (digitalRead(_DB5)<<5) | (digitalRead(_DB4)<<4) | (digitalRead(_DB3)<<3) | (digitalRead(_DB2)<<2) | (digitalRead(_DB1)<<1) | (digitalRead(_DB0)<<0) );
}
void glcd_on( uchar DI_RS, uchar RW, uchar EN, uchar DB0, uchar DB1, uchar DB2, uchar DB3, uchar DB4, uchar DB5, uchar DB6, uchar DB7, uchar CS1, uchar CS2 ) {

	_DB0 = DB0;
	_DB1 = DB1;
	_DB2 = DB2;
	_DB3 = DB3;
	_DB4 = DB4;
	_DB5 = DB5;
	_DB6 = DB6;
	_DB7 = DB7;
	_RW  = RW;
	_EN  = EN;
	_CS1 = CS1;
	_CS2 = CS2;
	_DI_RS = DI_RS;

	pinMode( _DI_RS,	Neither, 1 );
	pinMode( _RW, 		Neither, 1 );
	pinMode( _EN, 		Neither, 1 );
	pinMode( _DB0, 		Neither, 1 );
	pinMode( _DB1, 		Neither, 1 );
	pinMode( _DB2, 		Neither, 1 );
	pinMode( _DB3, 		Neither, 1 );
	pinMode( _DB4, 		Neither, 1 );
	pinMode( _DB5, 		Neither, 1 );
	pinMode( _DB6, 		Neither, 1 );
	pinMode( _DB7, 		Neither, 1 );
	pinMode( _CS1, 		Neither, 1 );
	pinMode( _CS2, 		Neither, 1 );

	//Activate both chips
	digitalWrite( _CS1, 1 );
	digitalWrite( _CS2, 1 );

	digitalWrite( _DI_RS, 0 ); 	//RS low --> command
	digitalWrite( _RW, 0 ); 		//RW low --> write
	setDataPinValue(0x3F); // ON command
	trigger();
}
void glcd_off( void ) {
	//Activate both chips
	digitalWrite( _CS1, 1 );
	digitalWrite( _CS2, 1 );

	digitalWrite( _DI_RS, 0 ); 	//RS low --> command
	digitalWrite( _RW, 0 ); 		//RW low --> write
	setDataPinValue(0x3E); //OFF command
	trigger();
}
void trigger( void ) {
  digitalWrite( _EN, 1 ); //EN high
	delayUs_Timer0(E_DELAY);
	digitalWrite( _EN, 0 ); //EN low
	delayUs_Timer0(E_DELAY);
}
void set_start_line( uchar line ) {
	digitalWrite( _DI_RS, 0 ); 	//RS low --> command
	digitalWrite( _RW, 0 ); 		//RW low --> write
	
	//Activate both chips
	digitalWrite( _CS1, 1 );
	digitalWrite( _CS2, 1 );

	setDataPinValue( 0xC0 | line ); //Set Start Line command
	trigger();
}
void goto_col( uint x ) {
	uchar pattern;

	digitalWrite( _DI_RS, 0 ); 	//RS low --> command
	digitalWrite( _RW, 0 ); 		//RW low --> write

	if(x<64) //left section
	{
		//Activate both chips
		digitalWrite( _CS1, 1 );
		digitalWrite( _CS2, 0 );

		pattern = x; //put column address on data port
	}
	else //right section
	{
		digitalWrite( _CS1, 0 );
		digitalWrite( _CS2, 1 );
		
		pattern = x-64;   //put column address on data port
	}
	
	pattern = (pattern | 0x40) & 0x7F;  //Command format
	setDataPinValue( pattern );
	trigger();
}
void goto_row( uint y ) {
	uchar pattern;
	
	digitalWrite( _DI_RS, 0 ); 	//RS low --> command
	digitalWrite( _RW, 0 ); 		//RW low --> write

	pattern = (y | 0xB8) & 0xBF; //put row address on data port set command
	setDataPinValue( pattern );
	trigger();
}
void goto_xy( uint x, uint y ) {
    goto_col(x);
    goto_row(y);
}
void glcd_write( uchar b ) {
   digitalWrite( _DI_RS, 1 ); //RS high --> data
   digitalWrite( _RW, 0 ); 		//RW low  --> write
   setDataPinValue( b ); //put data on data port
   delayUs_Timer0(1);
   trigger();
}
void glcd_clrln( uchar ln ) {
	int i;
	
	goto_xy(0,ln);      //At start of line of left side
	goto_xy(64,ln);     //At start of line of right side (Problem)
	
	digitalWrite( _CS1, 1 );
	
	for(i=0;i<65;i++) glcd_write(0);
}
void glcd_clear( void ) {
	int i;
	
	for(i=0;i<8;i++) glcd_clrln(i);
}
uchar is_busy(void) {
	uchar status = 0; //Read data here

	/*
	digitalWrite( _EN, 0 ); //Low Enable
	delayUs_Timer0(1); //tf
	digitalWrite( _RW, 1 ); //Read
	digitalWrite( _DI_RS, 0 ); //Status
	delayUs_Timer0(1); //tasu
	digitalWrite( _EN, 1 ); //High Enable
	delayUs_Timer0(5); //tr + max(td,twh)->twh

	//Dummy read
	digitalWrite( _EN, 0 ); //Low Enable
	delayUs_Timer0(5); //tf + twl + chineese error

	digitalWrite( _EN, 1 ); //High Enable
	delayUs_Timer0(1); //tr + td

	status = DATAPIN;    //Input data
	digitalWrite( _EN, 0 ); //Low Enable
	delayUs_Timer0(1); //tdhr
	*/

	return (status & 0x80);
}
uchar glcd_read( uchar column ) {
	uchar read_data = 0; //Read data here

	setDataPinMode(0); //Input

	//while(is_busy());
	digitalWrite( _RW, 1 ); //Data
	digitalWrite( _DI_RS, 1 ); //Read
	digitalWrite( _CS1, (column<64) ); // Enable/Disable CS1
	digitalWrite( _CS2, !digitalRead(_CS1) ); //Disable/Enable CS2
	delayUs_Timer0(1); //tasu
	digitalWrite( _EN, 1 ); //Latch RAM data into ouput register
	delayUs_Timer0(1); //twl + tf

	//Dummy read
	//while(is_busy());
	digitalWrite( _EN, 0 ); //Low Enable
	delayUs_Timer0(20); //tf + twl + chineese error

	digitalWrite( _EN, 1 ); //latch data from output register to data bus
	delayUs_Timer0(1); //tr + td(twh)

	read_data = getDataPinValue(); //Input data
/*	uart3_printNumberln( read_data, 10 );
	uart3_printNumberln( digitalRead(_DB0), 10 );
	uart3_printNumberln( digitalRead(_DB1), 10 );
	uart3_printNumberln( digitalRead(_DB2), 10 );
	uart3_printNumberln( digitalRead(_DB3), 10 );
	uart3_printNumberln( digitalRead(_DB4), 10 );
	uart3_printNumberln( digitalRead(_DB5), 10 );
	uart3_printNumberln( digitalRead(_DB6), 10 );
	uart3_printNumberln( digitalRead(_DB7), 10 );
	uart3_printNumberln( (digitalRead(_DB7)<<7) | (digitalRead(_DB6)<<6) | (digitalRead(_DB5)<<5) | (digitalRead(_DB4)<<4) | (digitalRead(_DB3)<<3) | (digitalRead(_DB2)<<2) | (digitalRead(_DB1)<<1) | (digitalRead(_DB0)<<0), 10 );
*/

	digitalWrite( _EN, 0 ); //Low Enable to remove data from the bus
	delayUs_Timer0(1); //tdhr

	setDataPinMode(1); //Output again

	return read_data;
}

uchar get_point(uint x,uint y) {
    uchar data;
    goto_xy( x, ((int)(y/8)) );
    data = glcd_read(x);
    return data;
}
void point_at( uint x, uint y, uchar color ) {
	uchar pattern;

	goto_xy( x, (int)(y/8) );

	switch (color)
	{
		//case 0: pattern = ~(1<<(y%8)) & glcd_read(x); break; //Light spot
		case 1: pattern = (1<<(y%8)) | glcd_read(x); break; //Dark spot
	}
	
	goto_xy(x,(int)(y/8));

	glcd_write(pattern);
}
void h_line( uint x, uint y, uchar l, uchar s, uchar c ) {
	int i;

	for(i=x; i<(l+x); i += (uchar)(s+1)) point_at(i,y,c);
}
void v_line( uint x, uint y, uint l, uchar s, uchar c ) {
 uint i;

 for( i=y; i<(y+l); i+=(s+1)) point_at(x,i,c);
}
void line( uint x1, uint y1, uint x2, uint y2, uchar s, uchar c ) {
	uchar i, y01, temp, y00, y010;
	float a, b;

	if(x1==x2) v_line(x1,min(y1,y2),abs(y2-y1)+1,s,c);
	else if(y1==y2) h_line(min(x1,x2),y1,abs(x2-x1)+1,s,c);
	else
	{
		if(x1>x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		a = (float)(signed)(y2-y1)/(x2-x1);
		b = y1 - a*x1;
		y00 = a*x1 + b;
		y010 = y00;

		for(i=(x1+1); i<=x2; i ++)
		{
			y01 = a*i + b + 0.5; //+ 0.5 to approximate to the nearest integer

			if( (signed char)(y01 - y010) > 1 ) v_line((i-1),(uchar)(y010+1),(y01-y010-1),s,c); //-------Subject to error
			else if( (signed char)(y010 - y01) > 1 ) v_line((i-1),(uchar)(y01+1),(y010-y01-1),s,c); //-------Subject to error

			if((i==x2) && (y00 == y01)) h_line(x1,y01,(x2-x1),0,c);
			
			y010 = y01;
			
			if( y00 ==  y01) continue;
			
			h_line(x1,y00,(i-x1),0,c);
			x1 = i;
			y00 = y01;
		}
		point_at(x2,y2,c);
	}
}
void rectangle( uint x1, uint y1, uint x2, uint y2, uchar s, uchar c, uchar EorF/*empty(0) or full(1) circle*/ ) {
	if( EorF ) {
		int i;		
		for( i=y1; i<=y2; i++ ) h_line(x1,i,(x2-x1),s,c);
	}
	else {
		h_line(x1,y1,(x2-x1),s,c);
		h_line(x1,y2,(x2-x1),s,c);
		v_line(x1,y1,(y2-y1),s,c);
		v_line(x2,y1,(y2-y1+1),s,c);
	}
}
void cuboid( uint x11, uint y11, uint x12, uint y12, uint x21, uint y21, uint x22, uint y22, uchar s, uchar c ) {
	rectangle(x11,y11,x12,y12,s,c, 0);
	rectangle(x21,y21,x22,y22,s,c, 0);
	line(x11,y11,x21,y21,s,c);
	line(x12,y11,x22,y21,s,c);
	line(x11,y12,x21,y22,s,c);
	line(x12,y12,x22,y22,s,c);
}
void h_parallelogram( uint x1, uint y1, uint x2, uint y2, uchar l, uchar s, uchar c ) {
	h_line(x1,y1,l,s,c);
	h_line((x2-l+1),y2,l,s,c);
	line(x1,y1,(x2-l+1),y2,s,c);
	line((x1+l-1),y1,x2,y2,s,c);
}
void v_parallelogram( uint x1, uint y1, uint x2, uint y2, uchar l, uchar s, uchar c ) {
	v_line(x1,y1,l,s,c);
	v_line(x2,(y2-l+1),l,s,c);
	line(x1,y1,x2,(y2-l+1),s,c);
	line(x1,(y1+l-1),x2,y2,s,c);
}
void h_parallelepiped( uint x11, uint y11, uint x12, uint y12, uchar l1, uint x21, uint y21, uint x22, uint y22, uchar l2, uchar s, uchar c ) {
	h_parallelogram(x11,y11,x12,y12,l1,s,c);
	h_parallelogram(x21,y21,x22,y22,l2,s,c);
	line(x11,y11,x21,y21,s,c);
	line(x12,y12,x22,y22,s,c);
	line((x11+l1-1),y11,(x21+l2-1),y21,s,c);
	line((x12-l1+1),y12,(x22-l2+1),y22,s,c);
}
void v_parallelepiped( uint x11, uint y11, uint x12, uint y12, uchar l1, uint x21, uint y21, uint x22, uint y22, uchar l2, uchar s, uchar c ) {
	v_parallelogram(x11,y11,x12,y12,l1,s,c);
	v_parallelogram(x21,y21,x22,y22,l2,s,c);
	line(x11,y11,x21,y21,s,c);
	line(x12,y12,x22,y22,s,c);
	line(x11,(y11+l1-1),x21,(y21+l2-1),s,c);
	line(x12,(y12-l1+1),x22,(y22-l2+1),s,c);
}
void circle( uint x0, uint y0, uint r, uchar s, uchar c ) {
	uchar i,y, y00 = r/*Point (0,r) is the 1st point*/;

	for(i=0; i<r; i++)
	{
		y = sqrt(r*r - i*i);
		
		point_at((x0+i),(y0+y),c);
		point_at((x0+i),(y0-y),c);
		point_at((x0-i),(y0+y),c);
		point_at((x0-i),(y0-y),c);

		if( abs(y00-y) > 1 )
		{
			v_line( x0+(i-1), y0+min(y00,y)+1,  abs(y00-y), s, c );
			v_line( x0+(i-1), y0-max(y00,y),    abs(y00-y), s, c );
			v_line( x0-(i-1), y0+min(y00,y)+1,  abs(y00-y), s, c );
			v_line( x0-(i-1), y0-max(y00,y),    abs(y00-y), s, c );
		}

		y00 = y;
	}

	v_line( x0+(i-1), y0,   y, s, c );
	v_line( x0+(i-1), y0-y, y, s, c );
	v_line( x0-(i-1), y0,   y, s, c );
	v_line( x0-(i-1), y0-y, y, s, c );
}
/*void ellipse(uint x0,uint y0,uint a,uint b,uchar s,uchar c) {
    uchar i,y,y00;
    y00 = 1;
    for(i=0; i < a; i++)
    {
        y = sqrt((int)a*a - (int)i*i);
        point_at((x0+i)*(a+x0)/a,(y0+y)*(b+y0)/b,c);
        point_at((x0+i)*(a+x0)/a,(y0-y)*(b+y0)/b,c);
        point_at((x0-i)*(a+x0)/a,(y0+y)*(b+y0)/b,c);
        point_at((x0-i)*(a+x0)/a,(y0-y)*(b+y0)/b,c);
        //if(abs(y00-y)>1)
        //{
        //    v_line(x0+(i-1),y0+min(y00,y)+1,abs(y00-y),s,c);
        //    v_line(x0+(i-1),y0-max(y00,y),abs(y00-y),s,c);
        //    v_line(x0-(i-1),y0+min(y00,y)+1,abs(y00-y),s,c);
        //    v_line(x0-(i-1),y0-max(y00,y),abs(y00-y),s,c);
        //
        //    printf("y=%u y00=%u\n\r",y,y00);
        //}
        y00 = y;
    }
    //v_line(x0+(i-1) ,y0,y ,s,c);
    //v_line(x0+(i-1) ,y0-y ,y,s,c);
    //v_line(x0-(i-1) ,y0,y ,s,c);
    //v_line(x0-(i-1) ,y0-y ,y,s,c);
}*/
void putIt( int c, int x, int y ) {
	uchar i;
	
  goto_col(x);
  goto_row(y);
	
  for(i=0;i<8;i++) glcd_write(font[(8*c)+i]);
}
void enlarge( char *large, uchar c, uchar size ) {
	uchar i, j, temp, k = 0;

	for(i=0;i<size;i++)
	{
		for(j=0;j<8;j++)
		{
			large[i] >>= 1;
			temp = c & 0x01;

			if(temp) large[i] |= 0x80;

			if(++k == size)
			{
				c >>= 1;
				k = 0;
			}
		}
	}
}
void putItSz( int c, int x, int y, uchar sz ) {
	uchar i,j,k;
  //char large[8][sz];
  char large[8][8];

	goto_col(x);
  goto_row(y);
	
  for(i=0;i<8;i++) enlarge(large[i],font[(8*c)+i],sz); //c here;GCC (c-1)
	
  for(j=0;j<sz;j++) {
	  for(i=0;i<8;i++) {
		  for(k=0;k<sz;k++) {
			  if(x+k+(sz*i) == 64) goto_xy(64,y);		//Problem 1: Forgot to change 3 to sz
			  glcd_write(large[i][j]);
		  }
	  }
	  goto_xy(x,++y);
  }
}
void glcd_putchar( uchar c, int x, int y, uchar l, uchar sz ) {
	if(l == 1)
	{
		switch(c)
		{
			case 129: c = 250; break;
    	case 144: c = 251; break;
    	case 152: c = 252; break;
    	case 142: c = 253; break;
    	case 141: c = 254; break;
		}
		
		if((c >= 193) && (prevLet >= 193) && (map[prevLet-193][5]) && (map[c-193][4]))
		{
			putIt(map[prevLet-193][stat+1],prevX,prevY);
			stat = 2;
		}
		else stat = 0;

		if(c >= 193) putItSz(map[c-193][stat],x,y,sz);
		else putItSz(c,x,y,sz);

		prevLet = c;
		prevX = x;
		prevY = y;
	}
	else putItSz(c,x,y,sz);
}
void glcd_puts( uchar *c, int x, int y, uchar l, uchar sz, signed char space ) {
	char i = 0, special = 0;

	while( (i<strlen(c)) && l==0 )
	{
		glcd_putchar(*(c+i),x,y,0,sz);

		x += (8+space)*sz;

		if(x>128-8*sz)
		{
			x=0;
			y += sz;
		}

		i++;
	}

	while( ((i<strlen(c)) && l) == 1 )
	{
		if((*(c+i) == 225) && (*(c+i+1) == 199)) special = 249;
		else if((*(c+i) == 225) && (*(c+i+1) == 195)) special = 231;
		else if((*(c+i) == 225) && (*(c+i+1) == 194)) special = 232;
		else if((*(c+i) == 225) && (*(c+i+1) == 197)) special = 233;
      
		if(special)
		{
			glcd_putchar(special,x-8*sz,y,1,sz);
			i+=2;
			x -= 8*sz;
			special = 0;
		}
		else
		{
		  glcd_putchar(*(c+i),x-8*sz,y,l,sz);
			
		  if(*(c+i) == 32)						//If space (i.e. new word)
		  {
			  x -= (8+space)*sz;				//Space between words
		  }
		  else
		  {
			  x -= 8*sz;
		  }
		  
			i++;
		}
		if(x < 8*sz+1)
		{
			x=128-8*sz;
			y += sz;
		}
	}
	
	prevLet = 193;
}
void glcd_printNumber( uint data, uint base, uint x, uint y, uchar l, uchar sz, char space ) {
  char buf[8 * sizeof(long) + 1];
  char *str = &buf[sizeof(buf) - 1];
	char c;
	unsigned long m;
  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
    m = data;
    data /= base;
    c = m - base * data;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(data);

  glcd_puts( (uchar*)str, x, y, l, sz, space );
}
void bmp_disp( uchar *bmp, uint x1, uint y1, uint x2, uint y2 ) {
	uint i,j;
	
	for(i=y1;i<=y2;i++)
	{
		for(j=x1;j<=x2;j++)
		{
			goto_xy(j,i);
			glcd_write(bmp[(128*i)+j]);
		}
	}
}
//////////////////// Function
