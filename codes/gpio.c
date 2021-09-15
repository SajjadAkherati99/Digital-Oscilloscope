#include <lpc213x.h>
#include "stdutils.h"
#include "gpio.h"

void GPIO_PinFunction(uint8_t v_pinNumber_u8, uint8_t v_pinFunction_u8)
{
    uint8_t v_portNumber_u8;

    v_portNumber_u8 =  (v_pinNumber_u8>>5);  //Divide the pin number by 32 go get the PORT number
    v_pinNumber_u8  =   v_pinNumber_u8 & 0x1f;  //lower 5-bits contains the bit number of a 32bit port  



    v_portNumber_u8 = v_portNumber_u8*2;
    if(v_pinNumber_u8>=16)
    {
        v_portNumber_u8++; 
        v_pinNumber_u8 = v_pinNumber_u8-16;
    }

    v_pinNumber_u8 = v_pinNumber_u8*2;

    switch(v_portNumber_u8)
    {
    case 0:  PINSEL0 &= ~(0x03UL << v_pinNumber_u8);
    PINSEL0 |= (((uint32_t)v_pinFunction_u8) << v_pinNumber_u8);
    break;
          
    case 1:  PINSEL1 &= ~(0x03UL << v_pinNumber_u8);
    PINSEL1 |= (((uint32_t)v_pinFunction_u8) << v_pinNumber_u8);
    break;

    case 2:  PINSEL2 &= ~(0x03UL << v_pinNumber_u8);
    PINSEL2 |= (((uint32_t)v_pinFunction_u8) << v_pinNumber_u8);
    break;                 

    }    
}


void GPIO_PinDirection(uint8_t v_pinNumber_u8, uint8_t v_pinDirn_u8)
{

    uint8_t v_portNumber_u8;

    v_portNumber_u8 =  (v_pinNumber_u8>>5);
    v_pinNumber_u8  =   v_pinNumber_u8 & 0x1f; 

    switch(v_portNumber_u8)
    {
    case 0:  util_UpdateBit(IO0DIR,v_pinNumber_u8,v_pinDirn_u8);
    break;
           
    case 1:  util_UpdateBit(IO1DIR,(v_pinNumber_u8+16),v_pinDirn_u8);
    break;               

    }

}


void GPIO_PinWrite(uint8_t v_pinNumber_u8, uint8_t v_pinValue_u8)
{

    uint8_t v_portNumber_u8;

    v_portNumber_u8 =  (v_pinNumber_u8>>5); 
    v_pinNumber_u8  =   v_pinNumber_u8 & 0x1f;

    switch(v_portNumber_u8)
    {
    case 0:  util_UpdateBit(IO0PIN,v_pinNumber_u8,v_pinValue_u8);
    break;
       
    case 1:  util_UpdateBit(IO1PIN,(v_pinNumber_u8+16),v_pinValue_u8);
    break;              

    }                
}


uint8_t GPIO_PinRead(uint8_t v_pinNumber_u8)
{
    uint8_t returnStatus = 0;
    uint8_t v_portNumber_u8;

    v_portNumber_u8 =  (v_pinNumber_u8>>5);
    v_pinNumber_u8  =   v_pinNumber_u8 & 0x1f;  

    switch(v_portNumber_u8)
    {
    case 0:  returnStatus = util_IsBitSet(IO0PIN,v_pinNumber_u8);
    break; 

    case 1:  returnStatus = util_IsBitSet(IO1PIN,(v_pinNumber_u8+16));
    break;           

    }        
    return returnStatus;
}
