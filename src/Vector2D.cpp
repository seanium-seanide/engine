#include "Vector2D.hpp"

Vector2D::Vector2D()
: m_x(0)
, m_y(0)
{
}

Vector2D::Vector2D(int x, int y)
: m_x(x)
, m_y(y)
{
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator+(Vector2D &v)
{
  return Vector2D(m_x + v.m_x, m_y + v.m_y);
}

Vector2D Vector2D::operator-(Vector2D &v)
{
  return Vector2D(m_x - v.m_x, m_y - v.m_y);
}

Vector2D Vector2D::operator*(double a)
{
  return Vector2D(a * m_x, a * m_y);
}

Vector2D Vector2D::operator/(double a)
{
  double b = 1.0 / a;

  return operator*(b);
}
