#include "GlobalVariables.h"
#include "view.h"
#include"Nokia5110.h"
void Init(void){ int i;
  for(i=0;i<3;i++){
    PumaStruct[i].x = 30 * i;
    PumaStruct[i].y = 16-PUMAH;
    PumaStruct[i].image[0] = Puma;
    PumaStruct[i].image[1] = Puma;
    PumaStruct[i].life = 1;
    Nokia5110_PrintBMP(PumaStruct[i].x, PumaStruct[i].y, Puma, 0);
   }
}
void pandaInit(void){ 
    PandaStruct.x = 60;
    PandaStruct.y = 47-PANDAH;
    PandaStruct.image[0] = Panda;
    PandaStruct.image[1] = Panda;
    PandaStruct.life = 1;
   // Nokia5110_PrintBMP(PandaStruct.x, PandaStruct.y, Panda, 0);
   }

