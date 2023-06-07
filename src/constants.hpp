/**
 * @file constants.hpp
 */

#ifndef ENGINE_CONSTANTS_H
#define ENGINE_CONSTANTS_H

#include <SDL2/SDL.h>

// Window clear color

const Uint8 WINDOW_CLEAR_RED = 0x64;
const Uint8 WINDOW_CLEAR_GREEN = 0x95;
const Uint8 WINDOW_CLEAR_BLUE = 0xED;
const Uint8 WINDOW_CLEAR_ALPHA = 0xFF;

const int TIGER_FRAME_WIDTH = 128;
const int TIGER_FRAME_HEIGHT = 82;
const int TIGER_NUM_FRAMES = 6;

const std::string WIN_TITLE = "Engine";
const int         WIN_WIDTH = 640;
const int         WIN_HEIGHT = 480;

const Uint32 FRAME_RATE_FPS = 60;
const Uint32 FRAME_TIME_MSPF = 1000.0 / FRAME_RATE_FPS;

#endif
