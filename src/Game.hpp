#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <SDL2/SDL.h>

#include <string>

class Game
{
public:

  Game(std::string windowTitle, int windowWidth, int windowHeight);
  ~Game();

  int run();

private:

  bool isRunning() { return m_running; }

  /**
   *  @brief Initializes SDL libraries, creates window and creates renderer
   */
  bool init();

  /**
   *  @brief Frees objects allocated by SDL
   */
  void clean();

  /**
   *  @brief Load SDL assets
   */
  bool loadAssets();

  /**
   *  @brief Free SDL assets
   */
  void freeAssets();

  /**
   *  @brief Process events.
   */
  void handleEvents();

  /**
   *  @brief Update state of game entities.
   */
  void update();

  /**
   *  @brief Draw current state of game entities to the game window.
   */
  void render();

  bool m_running; // Main loop sentinel

  bool loadTexture(SDL_Texture **ppTexture, std::string filename);

private:

  SDL_Window    *m_pWindow;
  SDL_Renderer  *m_pRenderer;

  std::string m_windowTitle;
  int         m_windowWidth;
  int         m_windowHeight;

  // Tiger animation
  SDL_Texture *m_pTigerAnimationTexture;
  int m_tigerFrameWidth;
  int m_tigerFrameHeight;
  int m_tigerNumFrames;
  int m_tigerCurrentFrame;
  SDL_Rect m_tigerSrcRect;
  SDL_Rect m_tigerDstRect;
};

#endif
