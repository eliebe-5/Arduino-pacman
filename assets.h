// This file was generated with the command-line:
//    /usr/local/bin/gd2asset -f assets.gd2 -o assets.h pacman.jpg blinky.jpg pinky.jpg inky.jpg clyde.jpg map.jpg spooked.jpg eyes.jpg waka.wav

#define PACMAN_HANDLE 0
#define PACMAN_WIDTH 16
#define PACMAN_HEIGHT 128
#define PACMAN_CELLS 1
#define BLINKY_HANDLE 1
#define BLINKY_WIDTH 16
#define BLINKY_HEIGHT 16
#define BLINKY_CELLS 1
#define PINKY_HANDLE 2
#define PINKY_WIDTH 16
#define PINKY_HEIGHT 16
#define PINKY_CELLS 1
#define INKY_HANDLE 3
#define INKY_WIDTH 16
#define INKY_HEIGHT 16
#define INKY_CELLS 1
#define CLYDE_HANDLE 4
#define CLYDE_WIDTH 16
#define CLYDE_HEIGHT 16
#define CLYDE_CELLS 1
#define MAP_HANDLE 5
#define MAP_WIDTH 300
#define MAP_HEIGHT 280
#define MAP_CELLS 1
#define SPOOKED_HANDLE 6
#define SPOOKED_WIDTH 16
#define SPOOKED_HEIGHT 32
#define SPOOKED_CELLS 1
#define EYES_HANDLE 7
#define EYES_WIDTH 16
#define EYES_HEIGHT 16
#define EYES_CELLS 1
#define WAKA 175680UL
#define WAKA_LENGTH 7896
#define WAKA_FREQ 22050
#define ASSETS_END 183576UL
#define LOAD_ASSETS()  (GD.safeload("assets.gd2"), GD.loadptr = ASSETS_END)

static const shape_t PACMAN_SHAPE = {0, 16, 128, 0};
static const shape_t BLINKY_SHAPE = {1, 16, 16, 0};
static const shape_t PINKY_SHAPE = {2, 16, 16, 0};
static const shape_t INKY_SHAPE = {3, 16, 16, 0};
static const shape_t CLYDE_SHAPE = {4, 16, 16, 0};
static const shape_t MAP_SHAPE = {5, 300, 280, 0};
static const shape_t SPOOKED_SHAPE = {6, 16, 32, 0};
static const shape_t EYES_SHAPE = {7, 16, 16, 0};
struct {
  Bitmap pacman;
  Bitmap blinky;
  Bitmap pinky;
  Bitmap inky;
  Bitmap clyde;
  Bitmap map;
  Bitmap spooked;
  Bitmap eyes;
} bitmaps = {
 /*           pacman */  {{ 16, 128}, {  8,  64},      0x0UL,  6,  0},
 /*           blinky */  {{ 16,  16}, {  8,   8},   0x1000UL,  6,  1},
 /*            pinky */  {{ 16,  16}, {  8,   8},   0x1200UL,  6,  2},
 /*             inky */  {{ 16,  16}, {  8,   8},   0x1400UL,  6,  3},
 /*            clyde */  {{ 16,  16}, {  8,   8},   0x1600UL,  6,  4},
 /*              map */  {{300, 280}, {150, 140},   0x1800UL,  6,  5},
 /*          spooked */  {{ 16,  32}, {  8,  16},  0x2a840UL,  6,  6},
 /*             eyes */  {{ 16,  16}, {  8,   8},  0x2ac40UL,  6,  7}
};
