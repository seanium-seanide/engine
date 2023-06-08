#include "LoaderParams.hpp"

LoaderParams::LoaderParams(int x, int y, int width, int height, std::string textureID)
: m_x(x)
, m_y(y)
, m_width(width)
, m_height(height)
, m_textureID(textureID)
{
  (void) m_x;
  (void) m_y;
  (void) m_width;
  (void) m_height;
  (void) m_textureID;
}

LoaderParams::~LoaderParams()
{
}
