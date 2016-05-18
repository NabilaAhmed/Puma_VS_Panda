/*
 * Switch handler
 *
 * Copyright 2016 by Ákos Németh
 * You may use, edit, run or distribute this file
 * as long as the above copyright notice remains.
 */

#include "switch.h"
#include "..//tm4c123gh6pm.h"



void PortE_Init(void) {
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= PORTE;     // 1) activate clock for Port F
    delay = SYSCTL_RCGC2_R;           // allow time for clock to start
    GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PF
    GPIO_PORTE_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
    GPIO_PORTE_DIR_R = 0x00;          // 5)
    GPIO_PORTE_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
	  GPIO_PORTE_PUR_R = 0x00;          // pull up disabled
    GPIO_PORTE_DEN_R = 0x1F;          // 7) enable digital I/O
}


void Switch_Init(void) {
    PortE_Init();
}

unsigned char Switch_is_MOVE_LEFT_Pushed(void) {
    return ((GPIO_PORTE_DATA_R & MOVE_LEFT) != 0x00);
}

unsigned char Switch_is_MOVE_RIGHT_Pushed(void) {
    return ((GPIO_PORTE_DATA_R & MOVE_RIGHT) != 0x00);
}