/**
 * @file Game.hpp
 * 
 * Singleton.
 */

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "TextureManager.hpp"
#include "constants.hpp"
#include "Entity.hpp"

class Game
{
public:

  /**
   * @brief Destructor.
   */
  ~Game();

  /**
   * @brief Main loop entry point.
   */
  int run();

  /**
   * @brief Singleton: Lazy-initialize the static instance.
   */
  static Game *Instance()
  {
    if (s_pInstance == nullptr)
    {
      s_pInstance = new Game(WIN_TITLE, WIN_WIDTH, WIN_HEIGHT);
    }

    return s_pInstance;
  }

private:

  /**
   * @brief Main loop running state accessor
   */
  bool isRunning() { return m_running; }

  /**
   * @brief Initialize engine
   */
  bool init();

  /**
   * @brief Teardown engine
   */
  void clean();

  /**
   * @brief Load game assets
   */
  bool loadAssets();

  /**
   * @brief Free game assets
   */
  void freeAssets();

  /**
   * @brief Initialize entities
   */
  void loadEntities();

  /**
   * @brief Teardown entities
   */
  void freeEntities();

  /**
   * @brief Main loop: Dispatch events
   */
  void handleEvents();

  /**
   * @brief Main loop: Update states of entities
   */
  void update();

  /**
   * @brief Main loop: Render current state of entities
   */
  void render();

  SDL_Renderer *getRenderer() { return m_pRenderer; }

private:

  /**
   * @brief Singleton: Private constructor
   */
  Game(std::string windowTitle, int windowWidth, int windowHeight);

  // Singleton: Class instance
  static Game *s_pInstance;

  // Main loop sentinel
  bool m_running; 

  SDL_Window    *m_pWindow;
  SDL_Renderer  *m_pRenderer;

  std::string m_windowTitle;
  int         m_windowWidth;
  int         m_windowHeight;

  std::vector<Entity *> m_entities;
};

typedef Game TheGame;

#endif
