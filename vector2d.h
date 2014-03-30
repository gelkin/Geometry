#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

//template <class T>
class Vector2D
{
public:
    Vector2D();
    Vector2D(double x, double y);
    Vector2D operator -(const Vector2D& other);
    double getLenght() const;
    double x;
    double y;
};

#endif // VECTOR2D_H
