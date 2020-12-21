/*
 * File:   MYSTEPPER.c
 * Author: Divyanshu
 *
 * Created on 15 December, 2020, 7:33 PM
 */


#include <xc.h>
#include "MYSTEPPER.h"
#include "EXTRAS.h"
#define _XTAL_FREQ 20000000

#define STEPPER_OUT_PORT PORT(STEPPER_PORT)
#define STEPPER_OUT_TRIS TRIS(STEPPER_PORT)

#define WIRE1           PORTBIT(STEPPER_PORT,PIN1)
#define WIRE1_TRIS      TRISBIT(STEPPER_PORT,PIN1)

#define WIRE2           PORTBIT(STEPPER_PORT,PIN2)
#define WIRE2_TRIS      TRISBIT(STEPPER_PORT,PIN2)

#define WIRE3           PORTBIT(STEPPER_PORT,PIN3)
#define WIRE3_TRIS      TRISBIT(STEPPER_PORT,PIN3)

#define WIRE4           PORTBIT(STEPPER_PORT,PIN4)
#define WIRE4_TRIS      TRISBIT(STEPPER_PORT,PIN4)


#define MODE 1 //0 for full 1 for half

int flag;
void INITSTEPPER()
{
   STEPPER_OUT_TRIS = 0x00;
   STEPPER_OUT_PORT = 0x00;
   flag = 1;  
}

void SETSPEED(long unsigned int *a)
{   int y=0;
    int maxstep = 4+4*MODE;
    
    while(flag)
    {
      STEPPER_OUT_PORT = HALF_STEP[y++];
      
      y = y % maxstep;
      long unsigned int t = (3*1000)/(4*(*a));
        if(t<1)
            t=1;
        if(t>1000)
            t=1000;
      delays(t)
      
      //to  debug
      
        if(*a>9)
          PORTCbits.RC0 = 1;
        if(*a>19)
          PORTCbits.RC1 = 1; 
        if(*a>29)
          PORTCbits.RC2 = 1;
      
      
      
      //__delay_ms(200);
    }
}
void STOP()
{
    flag = 0;
    STEPPER_OUT_PORT = 0x00;
}