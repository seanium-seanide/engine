#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

#include <SDL2/SDL.h>

class Player : public Entity
{
public:

  Player(const LoaderParams *pParams);
  ~Player();

  /*
   * @brief Teardown the entity.
   */
  virtual void clean();

  /*
   * @brief Update the state of the entity.
   *
   * Designed to be called once per frame in a game loop.
   */
  virtual void update();

  /*
   * @brief Render the entity.
   *
   * Designed to be called once per frame in a game loop.
   */
  virtual void render();
};

#endif
