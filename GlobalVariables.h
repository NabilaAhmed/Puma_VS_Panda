unsigned long TimerCount;
unsigned long Semaphore;
unsigned char Move_Left;
unsigned char Move_Right;

// *************************** Capture image dimensions out of BMP**********
#define PUMAW    ((unsigned char)Puma[16])
#define PUMAH    ((unsigned char)Puma[16])
#define PANDAW   ((unsigned char)Panda[16])
#define PANDAH   ((unsigned char)Panda[16])
	
struct State {
  unsigned long x;      // x coordinate
  unsigned long y;      // y coordinate
  const unsigned char *image[2]; // two pointers to images
  long life;            // 0=dead, 1=alive
};         
typedef struct State STyp;
STyp PumaStruct [3];
STyp PandaStruct ;
