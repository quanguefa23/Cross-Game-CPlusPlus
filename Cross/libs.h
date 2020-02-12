#include "Console.h"
using namespace std;
#define HEIGHT 40
#define WIDTH 96
#define MAX_LEVEL 5

//type == 1: move from left to right
//except dino: with type 1, the head is left top
//dino: with type 1, the head is left middle

void drawBanner();
void firstHandle();
int selection(int k);
void drawRectangle(int X, int Y, int W, int H);
void loadingBar();
void settings(int level, bool &sound, int k);