#include "Entity.hpp"

#include "Game.hpp"

Entity::Entity(const LoaderParams *pParams)
: AbstractEntity()
, m_currentFrame(0)
, m_currentRow(0)
{
  m_x = pParams->getX();
  m_y = pParams->getY();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureID = pParams->getTextureID();

  delete pParams;
}

Entity::~Entity()
{
}

void Entity::update()
{
}

void Entity::render()
{
  TextureManager::Instance()->drawFrame(
    TheGame::Instance()->getRenderer()
    , m_textureID
    , m_x, m_y
    , m_width, m_height
    , m_currentFrame, m_currentRow
  );
}

void Entity::clean()
{
}
