#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <SDL2/SDL.h>

#include <string>

class Game
{
public:

  //
  // Constructors / destructors
  //

  Game(std::string windowTitle, int windowWidth, int windowHeight, bool windowFullScreen = false);
  ~Game();

  int run();

private:

  //
  // Accessors
  //

  bool isRunning() { return m_running; }

  //
  // Setup / teardown
  //

  /**
   *  @brief Initializes SDL libraries, creates window and creates renderer
   */
  bool init();

  /**
   *  @brief Frees objects allocated by SDL
   */
  void clean();

  //
  // Main loop
  //

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

  SDL_Window    *m_pWindow;
  SDL_Renderer  *m_pRenderer;

  // Window

private:

  std::string m_windowTitle;
  int         m_windowWidth;
  int         m_windowHeight;
  int         m_windowFullScreen;
};

#endif
