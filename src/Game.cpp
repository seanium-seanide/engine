#include "Game.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstdlib>

#include "constants.hpp"

Game::Game(std::string windowTitle, int windowWidth, int windowHeight)
: m_running(false)
, m_pWindow(nullptr)
, m_pRenderer(nullptr)
, m_windowTitle(windowTitle)
, m_windowWidth(windowWidth)
, m_windowHeight(windowHeight)
  // ### TEMP ###
, m_rider()
{
}

Game::~Game()
{
  // Free assets
  this->freeAssets();

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

  // Draw rider

  SDL_RenderCopy(m_pRenderer, m_rider.pTexture, &m_rider.srcRect, &m_rider.dstRect);

  // Flip framebuffer

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

// ### TEMP ###
bool Game::loadAssets()
{
  if (!loadTexture(&m_rider.pTexture, "assets/rider.bmp"))
  {
    return false;
  }

  // Source rectangle

  m_rider.srcRect.x = 0;
  m_rider.srcRect.y = 0;
  SDL_QueryTexture(m_rider.pTexture, nullptr, nullptr, &m_rider.srcRect.w, &m_rider.srcRect.h);

  // Destination rectangle

  m_rider.dstRect.x = 0;
  m_rider.dstRect.y = 0;
  m_rider.dstRect.w = m_rider.srcRect.w;
  m_rider.dstRect.h = m_rider.srcRect.h;

  return true;
}

int Game::run()
{
  // Setup

  if (!(this->init()))
  {
    return -1;
  }

  if (!(this->loadAssets()))
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

bool Game::loadTexture(SDL_Texture **ppTexture, std::string filename)
{
  SDL_Surface *pTempSurface = SDL_LoadBMP(filename.c_str());
  if (pTempSurface == nullptr)
  {
    fprintf(stderr, "Failed to load BMP file %s: %s\n", filename.c_str(), SDL_GetError());
    return false;
  }

  *ppTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  return true;
}

void Game::freeAssets()
{
  SDL_DestroyTexture(m_rider.pTexture);
}
