#include "vector2d.h"

//template<class T>
Vector2D::Vector2D()
{
    this->x = 0;
    this->y = 0;
}

//template<class T>
Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2D Vector2D::operator -(const Vector2D& other)
{
    return Vector2D(this->x - other.x, this->y - other.y);
}

double Vector2D::getLenght() const
{
    return sqrt(x * x + y * y);
}

/*template class Vector2D<__int64>;
template class Vector2D<double>;
template class Vector2D<Radix>;
template class Vector2D<mpq_class>;*/
