/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

/*
    #define X1  RB0 
    #define X2  RB1
    #define X3  RB2
    #define X4  RB3
 
    #define Y1  RB4
    #define Y2  RB5
    #define Y3  RB6
    #define Y4  RB7
    #define KeypadPort PORTB // or any port of your choice
    #define KeypadPortDirection TRISB 
 */
char keypad[16] = 
{   '7'   ,   '8'   ,   '9'   ,   '/'   ,   
    '4'   ,   '5'   ,   '6'   ,   'x'   ,   
    '1'   ,   '2'   ,   '3'   ,   '-'   ,   
    'S'   ,   '0'   ,   '='   ,   '+'   };
char get_value();
void init_keypad();
char get_key();

void init_keypad()
{
    KeypadPortDirection = 0xf0;
    KeypadPort = 0x00;
    OPTION_REGbits.nRBPU = 0;
}





char get_value()
{
    X1=0;   X2=1;   X3=1;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[0];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[1];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[2];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[3];}
    
    X1=1;   X2=0;   X3=1;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[4];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[5];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[6];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[7];}
    
    X1=1;   X2=1;   X3=0;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[8];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[9];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[10];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[11];}
    
    X1=1;   X2=1;   X3=1;   X4=0;
    if(Y1 == 0){ while(Y1 == 0); return keypad[12];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[13];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[14];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[15];}
    
    
    return 'n';
}


char get_key()
{
    char key ='n';
    while(key=='n')
        key = get_value();
    
    return key;
}


char * get_str()
{   int i=0;
    char key1;
    char str[10];
    
    key1 = get_key();
    do{ str[i++] = key1;
        
        key1 = get_key();
            
        }while(key1!='S');
        str[i++]='\0';
    return str;    
}
