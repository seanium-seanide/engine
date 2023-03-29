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

  Game(std::string windowTitle, int windowWidth, int windowHeight);
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

  // ### TEMP ###
  /**
   *  @brief Load SDL assets
   */
  bool loadAssets();

  // ### TEMP ###
  /**
   *  @brief Free SDL assets
   */
  void freeAssets();

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

  //
  // Utilities
  //

  bool loadTexture(SDL_Texture **ppTexture, std::string filename);

private:

  // Window

  // resources
  SDL_Window    *m_pWindow;
  SDL_Renderer  *m_pRenderer;

  // Parameters
  std::string m_windowTitle;
  int         m_windowWidth;
  int         m_windowHeight;

  // Media

  // ### TEMP ###
  struct Rider
  {
    SDL_Texture *pTexture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    Rider() : pTexture(nullptr) {}
    ~Rider() {}
  }
  m_rider;
};

#endif
