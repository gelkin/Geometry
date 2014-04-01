#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D& other);
    Vector3D& operator =(const Vector3D& other);
    Vector3D& operator+=(const Vector3D& other);
    Vector3D& operator-=(const Vector3D& other);
    Vector3D operator -(const Vector3D& other) const;

    static Vector3D cross(const Vector3D& a, const Vector3D& b);
    static double scalar(const Vector3D &a, const Vector3D &b);
    static double angleBetween(const Vector3D &a, const Vector3D &b);

    double getLenght() const;
    void normalize();
    void mul(double k);
    double x;
    double y;
    double z;
};

#endif // VECTOR3D_H
