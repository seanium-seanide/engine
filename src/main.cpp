#include <SDL2/SDL.h>

#include <cstdio>
#include <string>

// Window constants

const std::string WIN_TITLE = "Engine";
const int         WIN_WIDTH = 640;
const int         WIN_HEIGHT = 480;

// Background color constants

const Uint8 BACKGROUND_RED = 0x64;
const Uint8 BACKGROUND_GREEN = 0x95;
const Uint8 BACKGROUND_BLUE = 0xED;
const Uint8 BACKGROUND_ALPHA = 0xFF;

// Globals

SDL_Window    *g_pWindow = nullptr;
SDL_Renderer  *g_pRenderer = nullptr;
bool          g_bRunning = false;

// Function Prototypes

bool init();
void events();
void update();
void render();
void exit();

// Entry Point

int main()
{
  // Initialization
  if (!init())
  {
    return -1;
  }

  g_bRunning = true;
  while (g_bRunning)
  {
    events();
    update();
    render();
  }

  // Teardown
  exit();

  return 0;
}

bool init()
{
  // Initialize SDL

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    fprintf(stderr, "Failed to initialize SDL2: %s\n", SDL_GetError());
    return false;
  }

  // Create window

  g_pWindow = SDL_CreateWindow(
    WIN_TITLE.c_str()
    , SDL_WINDOWPOS_CENTERED
    , SDL_WINDOWPOS_CENTERED
    , WIN_WIDTH
    , WIN_HEIGHT
    , SDL_WINDOW_SHOWN
  );

  if (g_pWindow == nullptr)
  {
    fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
    return false;
  }

  // Create renderer

  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (g_pRenderer == nullptr)
  {
    fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void events()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      g_bRunning = false;
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_ESCAPE:
        g_bRunning = false;
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

void update()
{
}

void render()
{
  // Clear screen to black

  SDL_SetRenderDrawColor(
    g_pRenderer
    , BACKGROUND_RED
    , BACKGROUND_GREEN
    , BACKGROUND_BLUE
    , BACKGROUND_ALPHA
  );

  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

void exit()
{
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
}
