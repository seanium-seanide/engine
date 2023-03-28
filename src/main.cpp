#include <SDL2/SDL.h>

#include <cstdio>

#include <string>

#include "Game.hpp"

// Window constants

const std::string WIN_TITLE = "Engine";
const int         WIN_WIDTH = 640;
const int         WIN_HEIGHT = 480;

// Entry Point

int main()
{
  Game game(WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);

  return game.run();
}
