#ifndef CLASS_ABSTRACT_ENTITY_HPP
#define CLASS_ABSTRACT_ENTITY_HPP

#include "LoaderParams.hpp"

class AbstractEntity
{
public:

  virtual void render() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:

  AbstractEntity();
  virtual ~AbstractEntity();

  int m_x;
  int m_y;
  int m_width;
  int m_height;

  std::string m_textureID;

  int m_currentFrame;
  int m_currentRow;
};

#endif
