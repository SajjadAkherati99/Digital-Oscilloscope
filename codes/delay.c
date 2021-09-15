#include <lpc213x.h>
#include "delay.h"

void DELAY_us(unsigned int count)
{
  unsigned int j=0,i=0;

  for(j=0;j<count;j++)
  {
    for(i=0;i<10;i++);
  }
}


void DELAY_ms(unsigned int count)
{
    unsigned int i;
    for (i=0;i<count;i++)
    {
        DELAY_us(1000);
    }
}

