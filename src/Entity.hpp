#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP

#include <string>

#include <SDL2/SDL.h>

#include "TextureManager.hpp"
#include "AbstractEntity.hpp"

class Entity : public AbstractEntity
{
public:

  Entity(const LoaderParams *pParams);
  ~Entity();

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
  //virtual void render(SDL_Renderer *pRenderer);
  virtual void render();

  /*
   * @brief Teardown the entity.
   */
  virtual void clean();

protected:

  int m_x;
  int m_y;
  int m_width;
  int m_height;

  std::string m_textureID;

  int m_currentFrame;
  int m_currentRow;
};

#endif
