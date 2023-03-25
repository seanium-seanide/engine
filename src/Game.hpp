#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

class Game
{
public:

  //
  // Constructors / destructors
  //

  Game();
  ~Game();

  //
  // Accessors
  //

  bool isRunning() { return m_running; }

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

private:

  bool m_running; // Main loop sentinel

};

#endif
