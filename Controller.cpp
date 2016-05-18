
#include "GlobalVariables.h"
#include "view.h"
#include "Nokia5110.h"
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

void MovePuma(void){ int i;


for(i=0;i<3;i++){

if(PumaStruct[i].x==PandaStruct.x && PumaStruct[i].y-PandaStruct.y <=16){


}
else{
if(PumaStruct[i].y < MAX_Y  ){
PumaStruct[i].y += 1; // move to down
}else {
PumaStruct[i].life = 0;

}}
}
if(Move_Left&&( PandaStruct.x <= 60 && PandaStruct.x >0)){

PandaStruct.x-=30;


}
if(Move_Right && !(PandaStruct.x >=60) )
{

PandaStruct.x += 30;
}
}
unsigned long FrameCount=0;
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
FrameCount = (FrameCount+1)&0x01; // 0,1,0,1,...
}}
