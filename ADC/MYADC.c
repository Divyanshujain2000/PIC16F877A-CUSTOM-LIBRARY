/*
 * File:   MYADC.c
 * Author: Divyanshu
 *
 * Created on 17 December, 2020, 3:08 PM
 */
#define _XTAL_FREQ 1000000

#include <xc.h>
#include "MYADC.h"

void init_adc()
{   
    TRISA = 0xff;       // for analog input
    ADCON0 = 0x00;
    ADCON1 = 0x00;      //port config yet not set
    ADCON1bits.ADFM = 1;
    ADCON0bits.ADON = 1;
}

unsigned int readADC(int cha)
{
    
    ADCON0 |= cha<<3;   //set the required channel
    __delay_ms(3);      //wait for cap charge
    ADCON0bits.GO_nDONE =1;
    while(ADCON0bits.GO_nDONE);
    
return((ADRESH<<8)+ADRESL);
   
}