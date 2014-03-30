#ifndef SPHERE_H
#define SPHERE_H

#include <QtOpenGL>

#include "view.h"
#include <vector>
#include "vector2d.h"
#include "vector3d.h"

class GeometryView : public View
{
    typedef std::pair<Vector2D, Vector2D> Line2D;
public:
    GeometryView(double radius);
    virtual void render();

    void addPoint(const Vector2D& p);
    void addLine(const Vector2D& a, const Vector2D& b);

    Vector3D position;
    Vector3D toDecard(const Vector2D& v);
    void drawPoint(const Vector2D& p);
    void drawLine(const Vector2D& a, const Vector2D& b);
    double getRadius() const;
    double angle;
private:
    double radius;
    int type;
    int quality;
    std::vector<Line2D> lines;
    std::vector<Vector2D> points;
};

#endif // SPHERE_H
