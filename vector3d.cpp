#include "vector3d.h"

#include <math.h>

Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D(const Vector3D &other)
{
    operator =(other);
}

Vector3D& Vector3D::operator =(const Vector3D& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}

Vector3D Vector3D::cross(const Vector3D &a, const Vector3D &b)
{
    return Vector3D(a.y * b.z - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - b.x * a.y);
}

Vector3D Vector3D::operator -(const Vector3D& other) const
{
    return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D& Vector3D::operator +=(const Vector3D& other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

Vector3D& Vector3D::operator -=(const Vector3D& other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

void Vector3D::mul(double k)
{
    this->x *= k;
    this->y *= k;
    this->z *= k;
}

double Vector3D::getLenght() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector3D::normalize()
{
    double d = getLenght();
    if (d != 0)
    {
        mul(1 / d);
    }
}
