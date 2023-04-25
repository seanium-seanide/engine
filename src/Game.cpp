#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
, m_pTigerAnimationTexture(nullptr)
{
}

Game::~Game()
{
  freeAssets();
  clean();
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
  // Frame updates every (1000 / 100) ms = every 10th of a second
  m_tigerCurrentFrame = static_cast<int>(SDL_GetTicks() / 100) % m_tigerNumFrames;
  m_tigerSrcRect.x = m_tigerCurrentFrame * m_tigerFrameWidth;
}

void Game::render()
{
  SDL_SetRenderDrawColor(
    m_pRenderer
    , WINDOW_CLEAR_RED
    , WINDOW_CLEAR_GREEN
    , WINDOW_CLEAR_BLUE
    , WINDOW_CLEAR_ALPHA
  );
  SDL_RenderClear(m_pRenderer);

  //SDL_RendererFlip tigerFlipFlags 
  //  = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
  SDL_RendererFlip tigerFlipFlags = SDL_FLIP_NONE;
  SDL_RenderCopyEx(
    m_pRenderer
    , m_pTigerAnimationTexture
    , &m_tigerSrcRect
    , &m_tigerDstRect
    , 0 // Ex
    , 0 // Ex
    , tigerFlipFlags // Ex
  );

  SDL_RenderPresent(m_pRenderer);
}

bool Game::init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    fprintf(stderr, "Failed to initialize SDL2: %s\n", SDL_GetError());
    return false;
  }

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

bool Game::loadAssets()
{
  // Tiger animation

  m_tigerNumFrames = 6;
  m_tigerCurrentFrame = 0;

  if (!loadTexture(&m_pTigerAnimationTexture, "assets/graphics/animate-alpha.png"))
  {
    return false;
  }

  int tigerAnimationWidth = 0;
  int tigerAnimationHeight = 0;
  SDL_QueryTexture(m_pTigerAnimationTexture, nullptr, nullptr, &tigerAnimationWidth,
    &tigerAnimationHeight);

  m_tigerFrameWidth = tigerAnimationWidth / m_tigerNumFrames;
  m_tigerFrameHeight = tigerAnimationHeight;

  m_tigerSrcRect.x = 0;
  m_tigerSrcRect.y = 0;
  m_tigerSrcRect.w = m_tigerFrameWidth;
  m_tigerSrcRect.h = m_tigerFrameHeight;

  m_tigerDstRect.x = 0;
  m_tigerDstRect.y = 0;
  m_tigerDstRect.w = m_tigerFrameWidth;
  m_tigerDstRect.h = m_tigerFrameHeight;

  return true;
}

void Game::freeAssets()
{
  // Tiger animation
  SDL_DestroyTexture(m_pTigerAnimationTexture);
}

int Game::run()
{
  if (!init())
  {
    return -1;
  }

  if (!loadAssets())
  {
    return -1;
  }

  m_running = true;
  while (isRunning())
  {
    handleEvents();
    update();
    render();
  }

  return 0;
}

bool Game::loadTexture(SDL_Texture **ppTexture, std::string filename)
{
  //SDL_Surface *pTempSurface = SDL_LoadBMP(filename.c_str());
  SDL_Surface *pTempSurface = IMG_Load(filename.c_str());
  if (pTempSurface == nullptr)
  {
    fprintf(stderr, "Failed to load BMP file %s: %s\n", filename.c_str(), SDL_GetError());
    return false;
  }

  *ppTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  return true;
}
