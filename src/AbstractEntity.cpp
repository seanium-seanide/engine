#include "AbstractEntity.hpp"

AbstractEntity::AbstractEntity(const LoaderParams *pParams)
: m_currentFrame(0)
, m_currentRow(0)
{
  m_x = pParams->getX();
  m_y = pParams->getY();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureID = pParams->getTextureID();
}

AbstractEntity::~AbstractEntity()
{
}
