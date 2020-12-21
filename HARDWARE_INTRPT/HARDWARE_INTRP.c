/*
 * File:   HARDWARE_INTRP.c
 * Author: Divyanshu
 *
 * Created on 16 December, 2020, 7:16 PM
 */


#include <xc.h>
#include "HARDWARE_INTRP.h"
#define _XTAL_FREQ 20000000

void INITH()
{
    TRISB = (1<<0);
    OPTION_REG =0x00;
    OPTION_REGbits.INTEDG = 1;
    INTE = 1;
    GIE = 1;
    PEIE = 1;
}
