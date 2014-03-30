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

Vector2D::Vector2D(const Vector2D &other)
{
    operator =(other);
}

Vector2D& Vector2D::operator =(const Vector2D& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

bool Vector2D::operator ==(const Vector2D& other) const
{
    return (fabs(this->x - other.x) < 1e-32) && (fabs(this->y - other.y) < 1e-32);
}

Vector2D Vector2D::operator -(const Vector2D& other) const
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
