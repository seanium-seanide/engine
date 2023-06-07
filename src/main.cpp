/**
 * @file main.cpp
 */

#include <SDL2/SDL.h>

#include <string>
#include <cstdio>

#include "Game.hpp"
#include "constants.hpp"

int main()
{
  // TODO: Set title via singleton Game instance
  //Game game(WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);

  int retVal = TheGame::Instance()->run();

  return retVal;
}
