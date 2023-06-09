#ifndef CLASS_VECTOR2D_HPP
#define CLASS_VECTOR2D_HPP

class Vector2D
{
public:

  Vector2D();
  Vector2D(int x, int y);
  ~Vector2D();

  // Accessors

  double x() { return m_x; }
  double y() { return m_y; }

  void x(double _x) { m_x = _x; }
  void y(double _y) { m_y = _y; }

  // Operators

  Vector2D operator+(Vector2D &v);
  Vector2D operator-(Vector2D &v);
  Vector2D operator*(double a);
  Vector2D operator/(double a);

private:

  double m_x;
  double m_y;
};

#endif
