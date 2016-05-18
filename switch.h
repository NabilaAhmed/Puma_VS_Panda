
#define PORTE 0x10

// PE0
#define MOVE_LEFT 0x01

// PE1
#define MOVE_RIGHT 0x02

// Initialize switches on PE0 - move o left, PE1 - move to right
 
void Switch_Init(void);

// Returns !0, if PE0 is pushed (high), otherwise returns 0
 
unsigned char Switch_is_MOVE_LEFT_Pushed(void) ;

// Returns !0, if PE1 is pushed (high), otherwise returns 0
 
unsigned char Switch_is_MOVE_RIGHT_Pushed(void) ;




