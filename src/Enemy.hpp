#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Entity.hpp"

#include <SDL2/SDL.h>

class Enemy : public Entity
{
public:

  Enemy(const LoaderParams *pParams);
  ~Enemy();

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

  /*
   * @brief Teardown the entity.
   */
  virtual void clean();

private:
};

#endif
