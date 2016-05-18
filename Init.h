//Panda
// width=16 x height=16
extern const unsigned char Panda[];
 
// Puma
// width=16 x height=16
extern const unsigned char Puma[];

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

extern STyp PumaStruct [3];
extern STyp PandaStruct ;

void Init(void);
void pandaInit(void);
