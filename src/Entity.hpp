#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP

#include <string>

#include <SDL2/SDL.h>

#include "TextureManager.hpp"

class Entity
{
public:

  Entity();
  ~Entity();

  /**
   * @brief         Initialize the entity.
   *
   * @param x       Sprite x-coordinate
   * @param y       Sprite y-coordinate
   * @param width   Sprite width
   * @param height  Sprite height
   * @param frame   Animation frame index (sprite sheet column)
   * @param row     Sprite sheet row
   * @param ID      Texture ID
   */
  virtual void load(int x, int y, int width, int height, std::string textureID);

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
  virtual void render(SDL_Renderer *pRenderer);

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
