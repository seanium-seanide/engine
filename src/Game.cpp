#include "Game.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstdlib>

#include "constants.hpp"

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, bool windowFullScreen)
: m_running(false)
, m_pWindow(nullptr)
, m_pRenderer(nullptr)
, m_windowTitle(windowTitle)
, m_windowWidth(windowWidth)
, m_windowHeight(windowHeight)
, m_windowFullScreen(windowFullScreen)
{
  //this->run();
}

Game::~Game()
{
  // Teardown
  this->clean();
}

void Game::handleEvents()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      m_running = false;
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_ESCAPE:
        m_running = false;
        break;

      default:
        break;
      }
      break;

    default:
      break;
    }
  }
}

void Game::update()
{
}

void Game::render()
{
  // Clear screen to black

  SDL_SetRenderDrawColor(
    m_pRenderer
    , WINDOW_CLEAR_RED
    , WINDOW_CLEAR_GREEN
    , WINDOW_CLEAR_BLUE
    , WINDOW_CLEAR_ALPHA
  );

  SDL_RenderClear(m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::init()
{
  // Initialize SDL

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    fprintf(stderr, "Failed to initialize SDL2: %s\n", SDL_GetError());
    return false;
  }

  // Create window

  // Flags
  Uint32 windowFlags = SDL_WINDOW_SHOWN;
  if (m_windowFullScreen)
  {
    windowFlags = windowFlags | SDL_WINDOW_FULLSCREEN;
  }

  m_pWindow = SDL_CreateWindow(
    m_windowTitle.c_str()
    , SDL_WINDOWPOS_CENTERED
    , SDL_WINDOWPOS_CENTERED
    , m_windowWidth
    , m_windowHeight
    , windowFlags
  );

  if (m_pWindow == nullptr)
  {
    fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
    return false;
  }

  // Create renderer

  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (m_pRenderer == nullptr)
  {
    fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void Game::clean()
{
  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}

int Game::run()
{
  // Setup

  if (!(this->init()))
  {
    return -1;
  }

  // Main loop

  m_running = true;

  while (this->isRunning())
  {
    this->handleEvents();
    this->update();
    this->render();
  }

  return 0;
}
