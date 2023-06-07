/**
 * @file Game.hpp
 */

#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <cstdlib>

#include "constants.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Game *Game::s_pInstance = nullptr;

Game::Game(std::string windowTitle, int windowWidth, int windowHeight)
: m_running(false)
, m_pWindow(nullptr)
, m_pRenderer(nullptr)
, m_windowTitle(windowTitle)
, m_windowWidth(windowWidth)
, m_windowHeight(windowHeight)
{
}

Game::~Game()
{
  clean();
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
  freeAssets();
  freeEntities();

  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}

bool Game::loadAssets()
{
  TheTextureManager::Instance()->loadTexture(m_pRenderer, "assets/graphics/animate-alpha.png", "animate");

  return true;
}

void Game::freeAssets()
{
}

void Game::loadEntities()
{
  Entity *entity = new Entity();
  Player *player = new Player();
  Enemy *enemy = new Enemy();

  entity->load(100, 300, 128, 82, "animate");
  player->load(300, 300, 128, 82, "animate");
  enemy->load(100, 100, 128, 82, "animate");

  m_entities.push_back(entity);
  m_entities.push_back(player);
  m_entities.push_back(enemy);
}

void Game::freeEntities()
{
  for (auto entity: m_entities)
  {
    entity->clean();
  }
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

  loadEntities();


  m_running = true;
  while (isRunning())
  {
    Uint32 startTime = SDL_GetTicks();

    handleEvents();
    update();
    render();

    Uint32 endTime = SDL_GetTicks();

    Uint32 deltaTime = endTime - startTime;
    if (deltaTime < FRAME_TIME_MSPF)
    {
      SDL_Delay(FRAME_TIME_MSPF - deltaTime);
    }
  }

  return 0;
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
  for (auto entity : m_entities)
  {
    entity->update();
  }
}

void Game::render()
{
  // Clear background
  SDL_SetRenderDrawColor(
    m_pRenderer
    , WINDOW_CLEAR_RED
    , WINDOW_CLEAR_GREEN
    , WINDOW_CLEAR_BLUE
    , WINDOW_CLEAR_ALPHA
  );
  SDL_RenderClear(m_pRenderer);

  // Draw entities
  for (auto entity : m_entities)
  {
    entity->render(m_pRenderer);
  }

  // Flip framebuffer
  SDL_RenderPresent(m_pRenderer);
}
