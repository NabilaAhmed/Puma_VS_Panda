// SpaceInvaders.c
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the edX Lab 15
// In order for other students to play your game
// 1) You must leave the hardware configuration as defined
// 2) You must not add/remove any files from the project
// 3) You must add your code only this this C file
// I.e., if you wish to use code from sprite.c or sound.c, move that code in this file
// 4) It must compile with the 32k limit of the free Keil

// This virtual Nokia project only runs on the real board, this project cannot be simulated
// Instead of having a real Nokia, this driver sends Nokia
//   commands out the UART to TExaSdisplay
// The Nokia5110 is 48x84 black and white
// pixel LCD to display text, images, or other information.

// April 19, 2014
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
"Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2013

"Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2013

Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
You may use, edit, run or distribute this file
as long as the above copyright notice remains
THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
For more information about my classes, my research, and my books, see
http://users.ece.utexas.edu/~valvano/
*/
// ******* Required Hardware I/O connections*******************
// PA1, PA0 UART0 connected to PC through USB cable
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PE2/AIN1
// Slide pot pin 3 connected to +3.3V
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

#include "..//tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "Random.h"
#include "TExaS.h"
#include "switch.h"
#include "Init.h"
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Timer2_Init(unsigned long period);
void SysTick_Init(unsigned long period);
void Delay100ms(unsigned long count); // time delay in 0.1 seconds
void Switch_Init(void);
unsigned long TimerCount;
unsigned long Semaphore;
unsigned char Move_Left;
unsigned char Move_Right;
unsigned long flage=0;


void MovePuma(void){ int i;
	for(i=0;i<3;i++){

		if(PumaStruct[i].y < MAX_Y  ){
		PumaStruct[i].y += 1; // move to down
		}else 
		PumaStruct[i].life = 0;
}
	
		if(Move_Left&&( PandaStruct.x <= 60 && PandaStruct.x >0)){
		PandaStruct.x-=30; //move to right
}
		if(Move_Right && !(PandaStruct.x >=60) ){
		PandaStruct.x += 30;}
}

unsigned long FrameCount=0;
void Draw(int Level){ int i;
Nokia5110_ClearBuffer();
if(Level % 3 ==0 && PumaStruct[i].life > 0){

Nokia5110_PrintBMP(PumaStruct[1].x, PumaStruct[1].y, Puma, 0);
Nokia5110_PrintBMP(PumaStruct[0].x, PumaStruct[0].y, Puma, 0);
	
Nokia5110_PrintBMP(PandaStruct.x, PandaStruct.y, Panda, 0);
	
}else if(Level % 2 ==0 && PumaStruct[i].life > 0){
	Nokia5110_PrintBMP(PumaStruct[2].x, PumaStruct[2].y, Puma, 0);
 Nokia5110_PrintBMP(PumaStruct[0].x, PumaStruct[0].y, Puma, 0);
	Nokia5110_PrintBMP(PandaStruct.x, PandaStruct.y, Panda, 0);

}else if (Level % 2 !=0 && PumaStruct[i].life > 0){
	Nokia5110_PrintBMP(PumaStruct[1].x, PumaStruct[1].y, Puma, 0);
Nokia5110_PrintBMP(PumaStruct[2].x, PumaStruct[2].y, Puma, 0);
Nokia5110_PrintBMP(PandaStruct.x, PandaStruct.y, Panda, 0);

}

Nokia5110_DisplayBuffer();      // draw buffer
FrameCount = (FrameCount+1)&0x01; // 0,1,0,1,...
}
int level1 ;
int main(void){ int AnyLife = 1; int i;
TExaS_Init(NoLCD_NoScope);  // set system clock to 80 MHz
// you cannot use both the Scope and the virtual Nokia (both need UART0)
Random_Init(1);
Nokia5110_Init();
EnableInterrupts(); // virtual Nokia uses UART0 interrupts
Switch_Init();
Nokia5110_ClearBuffer();
Nokia5110_DisplayBuffer();      // draw buffer
Nokia5110_ClearBuffer();
pandaInit();
Nokia5110_DisplayBuffer();   // draw buffer
	 for(level1 = 0 ; level1 < 10 ; level1 ++){
SysTick_Init(80000000/10); //at 10 hz
Timer2_Init(80000000/10);  // 10 Hz
while(AnyLife){
while(Semaphore == 0){};
Semaphore = 0; // run at 10 Hz
AnyLife = 0;
for(i=0; i<3 ; i++){
AnyLife |= PumaStruct[i].life;
}
if(level1 % 3 ==0 && PumaStruct[i].life > 0){
if((PumaStruct[1].x == PandaStruct.x && PumaStruct[1].y - PandaStruct.y <= 16 )
			||(PumaStruct[0].x == PandaStruct.x && PumaStruct[0].y - PandaStruct.y <= 16 ))
goto jump ;
}else if(level1 % 2 ==0 ){
	if((PumaStruct[2].x == PandaStruct.x && PumaStruct[2].y - PandaStruct.y <= 16 )
			||(PumaStruct[0].x == PandaStruct.x && PumaStruct[0].y - PandaStruct.y <= 16 ))
goto jump ;
	

}else if (level1 % 2 !=0 ){
	if((PumaStruct[1].x == PandaStruct.x && PumaStruct[1].y - PandaStruct.y <= 16 )
			||(PumaStruct[2].x == PandaStruct.x && PumaStruct[2].y - PandaStruct.y <= 16 ))
goto jump ;
	
}

			
Draw(level1);


}
AnyLife = 1 ;
Init();
}
jump :Nokia5110_Clear();
Nokia5110_SetCursor(1, 1);
Nokia5110_OutString("GAME OVER");
Nokia5110_SetCursor(1, 2);
Nokia5110_OutString("Nice try,");
Nokia5110_SetCursor(1, 3);
Nokia5110_OutString("Earthling!");
Nokia5110_SetCursor(2, 4);
Nokia5110_OutUDec(1234);
Nokia5110_SetCursor(0, 0); // renders screen
//while(1){
//}

}
// You can use this timer only if you learn how it works
void Timer2_Init(unsigned long period){
unsigned long volatile delay;
SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
delay = SYSCTL_RCGCTIMER_R;
TimerCount = 0;
Semaphore = 0;
TIMER2_CTL_R = 0x00000000;    // 1) disable timer2A during setup
TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
TIMER2_TAILR_R = period-1;    // 4) reload value
TIMER2_TAPR_R = 0;            // 5) bus clock resolution
TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
TIMER2_CTL_R = 0x00000001;    // 10) enable timer2A
}
void Timer2A_Handler(void){
TIMER2_ICR_R = 0x00000001;   // acknowledge timer2A timeout
TimerCount++;
MovePuma();
//MovePanda();
Semaphore = 1; // trigger
}
void Delay100ms(unsigned long count){unsigned long volatile time;
while(count>0){
time = 727240;  // 0.1sec at 80 MHz
while(time){
time--;
}
count--;
}
}
void updateInputs() {
Move_Left = Switch_is_MOVE_LEFT_Pushed();
Move_Right = Switch_is_MOVE_RIGHT_Pushed();
}

// Initialize SysTick interrupts to trigger at 10 Hz
void SysTick_Init(unsigned long period) {
NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
NVIC_ST_RELOAD_R = period-1;// reload value
NVIC_ST_CURRENT_R = 0;      // any write to current clears it
NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000; // priority 1
NVIC_ST_CTRL_R = 0x0007;  // enable SysTick with core clock and interrupts
}

// executes 10Hz
void SysTick_Handler(void) {
updateInputs();
TimerCount++;
Semaphore = 1;
}


