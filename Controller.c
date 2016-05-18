#include "Graph.h"
#include "Timer.h"
#include "Nokia5110.h"
#include "..//tm4c123gh6pm.h"
#include "controller.h"
#include "switch.h"

#include "timer.c"

void Move(void){ int i;
	
  for(i=0;i<3;i++){
			if(PumaStruct[i].x==PandaStruct.x && PumaStruct[i].y-PandaStruct.y <=16){
			}
			else if(PumaStruct[i].y < MAX_Y  )
      PumaStruct[i].y += 1; // move to down
			else 
			PumaStruct[i].life = 0;
		}
	if(Move_Left&&( PandaStruct.x <= 60 && PandaStruct.x >0)){
		PandaStruct.x-=30;
	}
	if(Move_Right && !(PandaStruct.x >=60) ){
		PandaStruct.x += 30;
	}
		}

void Draw(int Level){ int i;
    Nokia5110_ClearBuffer();	
	
		if(PumaStruct[i].x==PandaStruct.x && PumaStruct[i].y){
	  	Nokia5110_Clear();
	    Nokia5110_SetCursor(30, 30);
      Nokia5110_OutString("GAME OVER");
			
		}else {if(Level % 3 ==0 && PumaStruct[i].life > 0){
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
	
		}else {
					Nokia5110_ClearBuffer();
		}		
	Nokia5110_DisplayBuffer();      // draw buffer
		}
}
void Level1(int Level){int level1 ;int AnyLife = 1; int i;
for(level1 = 0 ; level1 < 10 ; level1 ++){
	//	SysTick_Init(80000000/10); //at 30 hz
		Timer2_Init(80000000/10);  // 10 Hz		
		while(AnyLife){
    while(Semaphore == 0){};
			Semaphore = 0; // run at 10 Hz
			AnyLife = 0;
			for(i=0; i<3 ; i++){
				AnyLife |= PumaStruct[i].life;
			}
			Draw(level1);
		}
		AnyLife = 1 ;
		pumaInit();
	}
}


void Timer2A_Handler(void){ 
  TIMER2_ICR_R = 0x00000001;   // acknowledge timer2A timeout
  TimerCount++;
  Move();  
  Semaphore = 1; // trigger
}

