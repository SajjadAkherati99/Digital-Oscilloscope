#include <lpc17xx.h>
#include "glcd.h"
#include "delay.h"

unsigned char photo1[6][1024] = {
	{255,255,255,3,3,3,3,227,227,227,195,131,3,7,7,31,63,255,255,255,3,3,3,3,3,3,3,127,255,255,63,3,3,131,3,3,3,3,255,255,255,255,3,3,3,3,227,227,
	227,227,227,227,255,227,227,227,225,225,225,3,3,3,7,143,255,255,159,15,15,135,3,3,3,3,3,255,255,255,255,227,227,227,225,225,225,3,3,3,7,143,
	255,255,255,255,255,255,255,255,255,255,255,3,3,3,3,255,255,255,255,3,3,3,3,227,227,227,3,3,3,7,15,255,255,255,255,255,255,255,255,255,255,
	0,0,0,0,255,255,255,127,63,0,0,0,0,192,255,255,255,0,0,0,0,254,240,0,0,7,3,0,192,252,255,0,0,0,0,255,255,255,255,0,0,0,0,241,241,241,241,241,
	255,255,127,255,241,241,240,112,32,0,2,6,15,255,255,255,255,255,255,0,0,0,0,0,255,255,255,255,127,255,241,241,240,112,32,0,2,6,15,255,127,
	63,31,63,127,255,255,255,255,255,0,0,0,0,255,255,255,255,0,0,0,0,241,241,193,0,0,4,14,255,255,255,255,255,255,255,255,255,255,255,248,248,
	248,248,248,248,248,248,248,252,252,254,255,255,255,255,255,248,248,248,248,255,255,255,248,248,248,254,255,255,255,248,248,248,248,255,255,
	255,255,248,248,248,248,255,255,255,255,255,255,255,248,248,248,248,248,248,248,248,252,252,255,255,255,255,255,255,255,248,248,248,248,248,
	255,255,255,255,248,248,248,248,248,248,248,248,252,252,255,255,255,254,252,252,254,255,255,255,255,255,248,248,248,248,255,255,255,255,248,
	248,248,248,255,255,255,252,248,248,248,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,15,7,7,3,255,255,255,255,255,255,255,255,195,205,237,231,255,63,15,7,3,63,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,15,7,3,63,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,95,31,31,47,47,15,23,7,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,127,255,255,255,255,255,255,248,0,0,0,63,
	63,63,31,7,31,63,63,59,49,32,0,3,254,0,0,0,128,255,255,255,255,255,127,31,15,31,63,63,63,63,15,15,63,63,63,15,31,63,55,3,255,254,0,0,0,128,
	255,255,255,255,255,255,255,255,255,127,31,15,31,63,63,63,55,49,32,1,3,255,255,255,255,7,3,31,31,63,63,63,63,63,63,56,56,48,0,2,6,254,255,255,
	255,255,255,255,255,255,127,31,15,31,63,63,63,63,7,3,3,99,227,199,31,255,255,255,224,128,131,7,7,7,7,7,7,131,192,240,248,248,248,184,56,126,
	60,56,248,248,248,248,252,254,255,255,248,252,255,255,255,127,127,63,31,14,12,192,248,248,248,248,252,248,248,248,252,248,248,248,252,255,255,
	255,255,248,252,255,255,255,255,255,255,255,127,127,63,31,14,12,192,248,248,248,184,24,8,156,254,255,255,255,255,255,252,252,248,248,248,248,
	248,248,248,248,248,248,252,252,255,255,255,255,255,255,255,127,127,63,31,14,12,192,248,248,248,248,252,252,248,248,248,252,254,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,
	254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,254,254,
	254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,254,254,254,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,127,63,223,15,15,255,255,195,195,129,49,241,248,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,159,143,31,255,1,0,255,255,255,127,63,255,63,255,127,63,255,255,195,195,129,49,241,248,255,255,255,255,255,
	255,127,63,127,255,255,159,143,31,255,255,255,195,1,0,255,63,127,255,207,7,31,127,255,255,159,207,205,136,29,31,63,
	63,255,255,255,255,63,127,255,247,231,247,247,255,127,127,63,255,247,51,255,255,159,15,15,15,159,255,241,192,11,255,255,
	255,255,255,255,255,255,254,252,252,254,248,248,248,248,248,248,252,255,255,255,255,255,255,225,206,159,159,159,145,145,144,208,
	224,248,248,216,216,220,255,252,248,248,248,248,248,248,248,252,248,248,248,248,248,248,248,248,252,255,255,255,255,255,191,159,
	159,142,132,224,248,248,200,200,252,255,255,255,255,248,252,255,252,248,248,248,252,252,248,248,248,248,248,248,252,254,254,254,
	255,255,255,255,255,252,248,248,248,248,248,248,248,252,252,248,248,248,252,248,248,248,248,252,248,248,248,248,248,252,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,63,63,31,31,15,207,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,223,143,223,255,255,255,
	255,255,255,255,255,127,191,127,191,255,255,255,255,255,255,255,255,223,223,223,223,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,111,255,248,253,255,231,195,15,255,255,255,231,67,7,143,
	143,143,195,143,143,140,128,192,199,143,143,143,143,195,143,143,195,129,153,153,195,255,255,255,255,31,239,255,255,255,31,31,
	15,15,15,143,143,195,129,153,153,195,255,135,137,137,9,3,143,143,137,140,204,192,225,193,137,141,143,137,136,193,255,255,
	255,63,223,255,255,255,135,153,145,3,135,137,137,9,3,143,143,129,196,132,129,143,137,140,140,200,225,225,227,243,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,248,248,248,248,248,252,254,251,249,249,248,248,254,255,
	255,253,253,253,255,255,255,255,255,255,255,255,253,253,253,255,255,255,255,255,255,255,255,255,255,254,252,249,249,249,249,249,
	249,253,254,255,255,255,255,255,255,255,251,249,249,248,248,252,255,255,255,255,255,252,252,255,255,255,255,255,255,255,255,255,
	255,252,252,248,248,248,248,248,252,250,249,249,248,248,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, 255,255,255,255,255,255,255,255,255,255,255,255,127,255,255,255,
	255,255,255,255,63,63,255,255,255,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,255,255,255,255,
	255,255,255,255,255,255,255,255,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,255,255,127,63,255,255,
	255,255,255,255,255,255,255,255,255,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,15,39,39,15,255,255,255,255,143,31,255,255,255,255,255,143,31,17,19,135,255,240,0,192,255,255,
	143,159,31,3,13,13,131,255,240,0,192,255,255,255,63,255,247,227,247,223,143,31,31,19,135,255,240,0,192,255,255,255,
	143,143,147,1,31,27,24,16,132,254,254,255,255,255,255,63,223,255,255,63,31,31,31,159,30,18,130,255,128,0,31,31,
	143,31,15,15,31,15,27,24,16,132,254,254,255,255,255,255,15,39,39,15,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,251,251,249,248,252,255,251,251,249,248,252,255,255,255,255,255,255,255,255,255,255,255,255,255,251,251,249,
	249,248,252,255,255,255,255,255,255,255,255,255,255,255,252,248,248,248,248,248,252,255,255,251,251,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,252,248,249,249,249,249,249,252,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,251,251,249,248,252,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,127,255,255,255,127,127,63,63,63,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,159,159,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,63,31,255,255,63,31,255,127,63,127,255,63,63,127,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,63,63,255,255,255,255,255,63,159,255,255,255,255,255,255,255,255,255,255,255,
	255,31,127,123,113,123,111,71,143,143,134,134,143,140,136,128,194,199,143,143,135,143,143,143,195,155,179,199,255,255,255,255,
	31,111,255,255,159,143,143,15,207,129,134,134,193,255,255,255,199,79,15,143,139,193,129,137,143,195,155,179,199,255,255,255,
	255,15,199,227,201,201,227,255,192,128,143,143,128,128,138,139,205,193,129,143,137,193,255,255,255,255,199,129,153,147,195,255,
	255,255,199,79,15,143,135,143,143,143,139,137,201,195,227,231,247,255,199,143,140,136,195,255,255,255,255,255,255,255,255,255,
	255,254,252,252,252,252,252,254,255,255,255,255,255,255,255,255,255,255,255,255,253,253,255,255,255,255,255,255,255,255,255,255,
	254,252,252,252,252,252,252,254,255,255,127,127,127,125,125,124,252,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,253,
	253,252,252,252,254,255,253,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,15,243,253,254,254,255,255,255,255,255,255,254,254,253,243,15,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,127,191,223,223,223,223,191,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,252,251,247,247,239,239,239,239,239,239,247,247,251,252,255,255,255,255,255,239,239,239,239,239,239,239,
	239,239,255,255,255,248,231,239,223,223,223,223,239,231,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
};


unsigned char gif[6][1024]={
	{255,255,255,191,191,63,63,63,63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,127,63,63,63,31,31,31,31,15,15,15,15,15,15,31,31,31,31,63,63,63,127,127,
	127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,254,252,248,240,192,129,3,3,7,15,31,63,63,127,127,255,255,255,255,255,255,255,255,255,255,127,63,31,
	15,7,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,7,7,7,15,15,15,15,15,31,31,31,63,63,127,127,127,247,193,
	1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,1,1,3,3,7,15,31,31,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,254,254,252,248,240,240,224,224,192,192,129,129,3,3,3,131,129,128,192,192,192,192,
	128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,193,225,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,31,31,63,60,56,48,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,224,224,240,248,248,252,
	252,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	252,224,0,0,0,8,248,248,248,248,248,248,240,224,128,0,0,0,8,28,60,124,252,252,254,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,
	0,128,192,224,240,240,248,248,252,252,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,30,0,0,0,0,7,255,255,255,
	255,255,255,255,255,254,248,0,0,0,0,128,195,255,255,255,255,255,63,1,0,0,0,0,128,192,192,224,240,248,252,254,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,248,248,252,252,254,255,255,255,255,255,255,255,
	255,255,255,255,255,227,193,129,129,1,1,1,0,0,0,224,240,248,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,254,240,224,224,224,224,224,225,225,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,31,31,15,
	7,7,7,3,3,3,3,3,3,3,3,3,7,7,7,7,15,15,31,31,63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,127,127,127,63,63,63,31,31,15,15,7,15,15,31,31,63,63,127,127,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,127,63,15,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,7,7,3,3,3,3,3,3,3,7,7,7,7,15,
	1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,240,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,127,127,127,127,127,127,127,63,63,63,31,31,15,7,7,3,1,129,128,192,224,192,192,128,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,240,248,248,248,248,248,248,
	248,248,248,248,248,248,252,252,252,252,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,
	252,252,252,252,252,252,252,248,248,248,248,248,248,248,252,252,252,252,254,254,254,255,255,255,255,255,255,255,31,15,6,4,0,0,0,0,0,
	0,0,0,96,240,224,128,0,0,0,0,0,0,248,240,224,224,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,240,248,252,254,254,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,254,252,252,252,248,248,240,240,240,224,224,192,192,193,128,128,0,0,0,0,31,63,31,15,3,0,128,192,224,240,
	248,252,248,240,224,192,0,0,0,0,0,2,14,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,199,135,135,7,7,7,7,7,7,131,131,130,128,192,192,224,224,224,224,192,193,193,129,1,3,7,15,63,63,31,30,12,0,0,0,0,128,227,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,252,252,248,248,248,248,248,248,248,252,252,252,254,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,63,63,63,63,31,31,31,
	15,15,7,7,7,15,15,31,63,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,63,31,
	31,15,15,7,7,7,7,3,3,3,3,3,3,3,3,3,7,7,7,7,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,240,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,15,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,240,248,248,248,252,252,252,252,252,
	252,252,252,252,252,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,191,191,127,127,127,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,127,127,63,31,31,15,7,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,192,192,128,128,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,24,60,124,126,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,252,248,248,240,240,240,224,224,
	224,224,224,224,224,224,224,224,224,240,240,248,248,252,252,254,255,255,255,254,252,252,248,248,240,128,0,0,0,0,0,0,0,0,128,128,0,0,
	0,0,0,0,255,255,255,255,255,255,255,254,254,252,252,248,248,248,248,192,128,0,0,0,0,0,0,0,252,252,252,248,248,248,240,240,240,224,224,
	224,192,192,192,128,0,1,1,3,3,7,15,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,127,63,31,7,0,0,0,192,224,240,252,254,255,255,252,240,224,224,192,128,0,3,7,7,15,31,63,63,63,103,67,131,131,135,7,7,15,7,
	0,0,128,128,192,240,255,255,255,255,255,255,255,255,255,223,143,135,7,3,3,1,129,128,192,192,224,240,252,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,248,240,224,192,128,0,3,7,31,31,63,63,63,63,63,127,
	127,255,255,255,255,255,254,252,248,240,240,224,224,224,224,224,224,225,227,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,248,240,240,240,240,240,240,248,249,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,127,127,127,127,127,255,255,255,
	255,255,127,127,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,127,127,127,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,127,127,127,127,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,127,127,127,127,127,127,63,63,63,63,31,31,15,15,15,
	15,15,15,15,15,15,31,31,31,31,31,29,24,24,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,7,7,15,15,31,31,31,31,31,31,63,255,255,255,255,255,
	255,255,255,255,255,127,63,31,15,15,135,135,195,195,225,225,225,240,240,240,240,240,240,248,248,240,240,240,240,224,224,224,64,1,1,1,1,1,
	1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,192,
	224,224,192,192,192,192,128,128,128,128,128,128,192,192,224,240,248,252,255,255,255,255,255,255,239,231,243,249,248,252,254,254,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,31,15,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,28,30,30,31,31,31,31,31,31,31,31,31,31,31,31,63,63,63,127,127,
	127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,31,31,15,15,15,7,7,7,3,3,3,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,240,248,254,255,255,255,255,255,255,255,255,255,255,254,254,252,252,248,248,240,240,240,224,224,
	224,224,224,224,224,224,224,240,240,240,240,240,248,248,248,252,252,248,240,240,224,224,224,192,192,192,192,128,128,128,0,4,14,14,30,30,
	62,62,62,124,124,120,120,120,112,112,112,112,48,49,59,63,127,255,255,255,255,255,255,143,7,15,15,15,15,7,7,3,1,0,0,128,192,224,240,248,
	252,30,6,2,0,0,0,0,128,192,192,192,192,192,224,224,224,240,240,240,248,248,252,254,254,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,252,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,252,254,
	255,255,255,255,255,255,255,255,254,252,252,252,252,252,252,254,255,255,255,255,255,7,1,0,0,0,0,240,248,252,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,252,240,224,224,192,192,192,193,193,227,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,127,127,127,63,63,63,63,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,63,63,63,127,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,127,63,63,63,63,63,63,127,127,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,254,252,252,252,248,248,240,224,224,192,128,1,3,3,7,7,3,3,3,3,1,1,1,1,1,1,
	1,1,3,3,3,3,3,7,7,7,7,7,15,15,15,15,15,15,31,31,31,15,15,15,15,15,15,15,15,15,7,15,15,15,15,15,31,31,63,63,62,62,60,60,56,56,48,0,0,0,
	0,0,1,3,3,7,3,7,7,7,7,15,15,31,63,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,129,193,227,243,
	255,255,255,255,255,255,255,255,255,255,255,127,127,127,127,127,63,63,31,15,7,1,1,128,192,64,0,0,1,1,3,3,7,7,3,1,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,128,128,192,192,224,240,240,248,248,248,248,240,224,192,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,
	224,224,240,248,248,248,252,252,252,254,254,254,254,255,255,255,255,254,254,254,254,254,254,254,254,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,252,112,32,0,0,0,0,0,0,0,128,128,192,192,224,224,224,224,224,224,224,192,192,192,192,224,224,240,240,248,248,
	252,252,252,254,254,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,252,248,248,248,240,240,
	240,240,240,240,240,240,240,240,240,240,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3,7,7,7,15,15,31,31,63,63,127,127,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,199,135,131,131,131,131,129,193,192,192,224,240,240,248,252,252,254,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,248,240,192,128,0,0,0,0,0,3,31,
	126,254,252,252,252,248,248,240,240,240,224,224,224,224,224,192,192,193,193,193,131,131,131,129,129,129,129,129,193,225,243,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,248,240,224,192,128,0,0,1,3,15,31,63,127,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,248,248,240,224,192,192,192,193,193,193,193,193,225,225,227,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255},
	
	{255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,247,243,243,249,249,249,248,248,248,240,224,225,193,129,131,3,7,7,15,31,31,
	63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,248,240,240,224,192,192,129,3,3,7,7,7,7,
	7,3,3,3,3,3,3,3,3,3,3,7,7,7,15,15,31,31,63,63,127,127,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,207,135,7,7,7,7,15,31,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,63,31,15,7,7,7,7,15,15,63,127,127,127,127,127,
	31,15,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,7,7,7,7,15,31,31,31,31,31,63,31,28,
	0,0,0,0,0,0,1,1,1,1,1,1,1,3,7,15,31,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,31,31,15,15,15,15,7,7,3,3,1,
	128,192,192,224,240,240,248,248,248,120,112,48,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,128,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,129,195,243,255,255,255,255,255,255,
	255,255,255,255,254,254,252,252,252,252,252,252,252,254,255,255,227,193,193,193,193,192,192,224,224,224,224,240,240,240,248,252,252,252,
	252,252,252,252,252,252,252,252,254,254,252,252,252,252,252,254,254,254,254,255,255,255,255,255,254,252,248,240,240,224,224,64,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,96,224,240,240,248,248,252,252,252,254,254,254,254,255,255,255,255,254,254,252,252,252,252,252,252,
	252,252,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,63,15,3,0,0,0,0,0,128,192,224,240,248,252,254,254,254,254,252,240,240,224,192,192,128,128,0,0,0,0,1,3,7,15,
	31,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,3,0,0,0,192,224,248,252,254,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,252,248,240,224,224,192,128,129,3,7,7,15,31,31,31,31,31,
	31,31,63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,240,192,192,128,128,128,129,131,207,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,254,252,252,252,252,252,252,252,252,252,255,255,255,255,255,
	255,255,255,255,255,255}
};
int main(void)
{
	int i;
	char j;

	glcd_on( P0_0/*DI_RS*/, P0_1/*RW*/, P0_2/*EN*/, P0_3/*DB0*/, P0_4/*DB1*/, P0_5/*DB2*/, P0_6/*DB3*/, P0_7/*DB4*/, P0_8/*DB5*/, P0_9/*DB6*/, P0_10/*DB7*/, P0_11/*CS1*/, P0_15/*CS2*/ );
	glcd_clear();

	
	// خوندن يه نقطه که سفيد هستش يا سياه
	point_at(0,0,1);
	glcd_printNumber( get_point(0,0),10, 20,0,0,2,0 );
	delayMs_Timer0(1000);
	glcd_clear();

	// مربع توپر و تو خالي
	rectangle(0,0,50,50,0,1, 0);
	rectangle(60,0,110,50,0,1, 1);
	delayMs_Timer0(1000);
	glcd_clear();

	// نمايش نقطه
	for(i=0; i<1000; i++) {
		point_at( ((rand()+1)/16777216)-1, ((rand()+1)/33554432)-1, 1 );
		delayMs_Timer0(10);
	}
	delayMs_Timer0(1000);
	glcd_clear();

	// نمايش عدد
	for(i=0; i<1000; i++) {
		glcd_printNumber( i,10, 0,0,0,2,0 );
		delayMs_Timer0(10);
	}
	delayMs_Timer0(1000);
	glcd_clear();
	
	// خط عمودي
	for(i=0; i<44; i+=4) {
		h_line(20,10+i, 90, 0,1);
		delayMs_Timer0(100);
	}
	delayMs_Timer0(1000);
	glcd_clear();

	// خط افقي
	for(i=0; i<110; i+=4) {
		v_line(10+i,5, 55, 0,1);
		delayMs_Timer0(100);
	}
	delayMs_Timer0(1000);
	glcd_clear();
	
	// خط زاويه دار
	for(i=0; i<64; i+=2) {
		line(0,0,63,i, 0,1);
		delayMs_Timer0(100);
	}
	for(i=0; i<64; i+=2) {
		line(0,0,i,63, 0,1);
		delayMs_Timer0(100);
	}
	delayMs_Timer0(1000);
	glcd_clear();

	// مکعب - 3بعدي !!!
	cuboid(10,10,30,30,40,40,60,60,0,1);
	delayMs_Timer0(1000);
	glcd_clear();
	
	// دايره - تابعش يکم مشکل داره
	circle(50,32,30,0,1);
	delayMs_Timer0(1000);
	glcd_clear();

	// نمايش متن
	glcd_puts((uchar*)"DMF313.IR",0,0,0,1,0);
	delayMs_Timer0(1000);
	glcd_clear();

	// نمايش کاراکتر
	for(j=33;j<=126;j++) { // 33-126
				 if( j-33 < 16  ) glcd_putchar( j,(j-33)*8,  0,  1,1 );
		else if( j-33 < 32  ) glcd_putchar( j,(j-49)*8,  9,  1,1 );
		else if( j-33 < 48  ) glcd_putchar( j,(j-65)*8,  18, 1,1 );
		else if( j-33 < 64  ) glcd_putchar( j,(j-81)*8,  27, 1,1 );
		else if( j-33 < 80  ) glcd_putchar( j,(j-97)*8,  36, 1,1 );
		else if( j-33 < 96  ) glcd_putchar( j,(j-113)*8, 45, 1,1 );
		else if( j-33 < 112 ) glcd_putchar( j,(j-129)*8, 54, 1,1 );
	}
	delayMs_Timer0(1000);

	// نمايش عکس
	for(i=0;i<3;i++) {
		bmp_disp(photo1[i],0,0,127,7);
		delayMs_Timer0(3000);
	}

	// نمايش عکس پشت سر هم!!! يا همون انيميشن!!!
	while(1) {
		for(i=0;i<=3;i++) {
			bmp_disp(gif[i],0,0,127,7);
			delayMs_Timer0(100);
		}
	}
}