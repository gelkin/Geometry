#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

//template <class T>
class Vector2D
{
public:
    Vector2D();
    Vector2D(double x, double y);
    Vector2D(const Vector2D& other);
    Vector2D& operator =(const Vector2D& other);

    bool operator ==(const Vector2D& other) const;
    Vector2D operator -(const Vector2D& other) const;
    double getLenght() const;
    double x;
    double y;
};

#endif // VECTOR2D_H
