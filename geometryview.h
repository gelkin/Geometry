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
    void removePoint(const Vector2D& p);
    void addLine(const Vector2D& a, const Vector2D& b);

    Vector3D map(const Vector2D& v);
    void setLineSegments(int line_segments);
    int getLineSegments() const;
    void setSpaceSegments(int space_segments);
    int getSpaceSegments() const;
    void setRadius(double radius);
    double getRadius() const;
    void clear();

private:
    Vector3D position;
    double angle;
    double radius;
    int type;
    int line_segments;
    int space_segments;
    std::vector<Line2D> lines;
    std::vector<Vector2D> points;

    void drawPoint(const Vector2D& p);
    void drawLine(const Vector2D& a, const Vector2D& b);
};

#endif // SPHERE_H
