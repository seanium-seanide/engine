#include "Entity.hpp"

Entity::Entity()
: m_x(0)
, m_y(0)
, m_width(0)
, m_height(0)
, m_textureID()
{
}

Entity::~Entity()
{
}

void Entity::update()
{
  m_currentFrame = static_cast<int>(SDL_GetTicks() / 100 % 6);
  m_x = m_x + 1;
}

void Entity::load(int x, int y, int width, int height, std::string textureID)
{
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  m_textureID = textureID;

  m_currentFrame = 0;
  m_currentRow = 0;
}

void Entity::render(SDL_Renderer *pRenderer)
{
  TextureManager::Instance()->drawFrame(pRenderer, m_textureID, m_x, m_y, m_width, m_height,
      m_currentFrame, m_currentRow);
}

void Entity::clean()
{
}
