#include "geometryview.h"

#include "console.h"

GeometryView::GeometryView(double radius)
{
    this->radius = radius;
    this->type = 0;
    this->line_segments = 20;
    this->space_segments = 30;
    this->angle = 0;
}

void GeometryView::setLineSegments(int line_segments)
{
    this->line_segments = line_segments;
}

int GeometryView::getLineSegments() const
{
    return line_segments;
}

void GeometryView::setSpaceSegments(int space_segments)
{
    this->space_segments = space_segments;
}

int GeometryView::getSpaceSegments() const
{
    return space_segments;
}

Vector3D GeometryView::map(const Vector2D &v)
{
    return Vector3D(radius * sin(v.x) * cos(v.y),
                    radius * sin(v.x) * sin(v.y),
                    radius * cos(v.x));
}

void GeometryView::setRadius(double radius)
{
    this->radius = radius;
}

double GeometryView::getRadius() const
{
    return radius;
}

/**
 * @brief GeometryView::addLine Add line at the sphere
 * @param a start of line
 * @param b end of line
 */
void GeometryView::addLine(const Vector2D& a, const Vector2D& b)
{
    lines.push_back(std::make_pair(a,b));
}

/**
 * @brief GeometryView::addPoint Add point at the sphere
 * @param p point(colatitude, azimuth)
 */
void GeometryView::addPoint(const Vector2D& p)
{
    QTextStream cout(stdout);
    points.push_back(p);
    cout << "INFO: Added " << "[" << QVariant(p.x).toString() << ", " << QVariant(p.y).toString() << "]\n";
}

/**
 * @brief GeometryView::addPoint Remove point from the sphere
 * @param p point(colatitude, azimuth)
 */
void GeometryView::removePoint(const Vector2D& p)
{
    QTextStream cout(stdout);
    for (int i = 0; i < points.size(); ++i)
    {
       if (points[i] == p)
        {
            cout << "INFO: Removed " << "[" << QVariant(points[i].x).toString() << ", " << QVariant(points[i].y).toString() << "]\n";
            points[i] = points[points.size() - 1];
            points.pop_back();
            --i;
        }
    }
}

void GeometryView::clear()
{
    points.clear();
    lines.clear();
}

void GeometryView::drawPoint(const Vector2D& p)
{
    int k = (p.y == 0 ? 0 : floor(p.y / (2 * M_PI)));
    if (k == 0)
    {
        glColor3ub(245, 181, 56);
    }
    else if (k == 1)
    {
        glColor3ub(231, 112, 0);
    }
    else
    {
        glColor3ub(0, 181, 56);
    }

    float x = radius * sin(p.x) * cos(p.y);
    float y = radius * sin(p.x) * sin(p.y);
    float z = radius * cos(p.x);
    glVertex3d(x, y, z);
}

void GeometryView::drawLine(const Vector2D &a, const Vector2D &b)
{
    glBegin(GL_LINE_STRIP);

    Vector3D c = map(a);
    Vector3D d = map(b);

    Vector3D v = Vector3D::cross(c, d);
    double full_angle = Vector3D::angleBetween(c, d);
    v.normalize();
    double dp = full_angle / line_segments;
    double p = 0;
    while (p <= full_angle + dp / 2)
    {
        double cosa = cos(-p);
        double sina = sin(-p);
        double cx = c.x * (cosa + (1 - cosa) * v.x * v.x) + c.y * ((1 - cosa) * v.y * v.x + sina * v.z) + c.z * ((1 - cosa) * v.z * v.x - sina * v.y);
        double cy = c.x * ((1 - cosa) * v.x * v.y - sina * v.z) + c.y * (cosa + (1 - cosa) * v.y * v.y) + c.z * ((1 - cosa) * v.z * v.y + sina * v.x);
        double cz = c.x * ((1 - cosa) * v.x * v.z + sina * v.y) + c.y * ((1 - cosa) * v.y * v.z - sina * v.x) + c.z * (cosa + (1 - cosa) * v.z * v.z);

        glVertex3d(cx, cy, cz);
        p += dp;
    }
    glEnd();
}

void GeometryView::render()
{
    glEnable( GL_BLEND );
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();

    if (type == 0)
    {
        glTranslated(position.x, position.y, position.z);
        glRotated(angle, 0, 0, 1);

        glPointSize(1);
        glBegin(GL_POINTS);
        glColor4f(0.5, 0.5, 0.5, 0.5);
        int n = 180 / space_segments;

        for (int a = 0; a <= 180; a += n)
        {
            for (int b = 0; b <= 360; b += n)
            {
                float x = radius * sin(a) * cos(b);
                float y = radius * sin(a) * sin(b);
                float z = radius * cos(a);
                glVertex3f(x, y, z);
            }
        }
        glEnd();

        glColor4ub(164, 31, 34, 255);
        for (int i = 0; i < lines.size(); ++i)
        {
            drawLine(lines[i].first, lines[i].second);
        }

        glPointSize(3);
        glBegin(GL_POINTS);
        for (int i = 0; i < points.size(); ++i)
        {
            drawPoint(points[i]);
        }
        glEnd();
    }
    else if (type == 1)
    {
        for (int i = 0; i < lines.size(); ++i)
        {
            drawLine(lines[i].first, lines[i].second);
        }
    }

    glPopMatrix();
}
