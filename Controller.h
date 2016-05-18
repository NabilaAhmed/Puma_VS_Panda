
unsigned char Move_Left;
unsigned char Move_Right;


//moving the puma with a periodic timer
void Move(void);

//Draw the puma after each time the coordinates increase
void Draw(int Level);

//timer time out interrupt handle
void Timer2A_Handler(void);




// executes 30Hz
void SysTick_Handler(void);

//uupdate inputs from push buttons
void updateInputs(void) ;


