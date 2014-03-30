#include "geometryview.h"

#include "console.h"

GeometryView::GeometryView(double radius)
{
    this->radius = radius;
    type = 0;
    quality = 10;
    angle = 0;
}

Vector3D GeometryView::toDecard(const Vector2D &v)
{
    return Vector3D(radius * sin(v.x) * cos(v.y),
                    radius * sin(v.x) * sin(v.y),
                    radius * cos(v.x));
}

double GeometryView::getRadius() const
{
    return radius;
}

void GeometryView::addLine(const Vector2D& a, const Vector2D& b)
{
    lines.push_back(std::make_pair(a,b));
}

void GeometryView::addPoint(const Vector2D& p)
{
    points.push_back(p);
}

void GeometryView::drawPoint(const Vector2D& p)
{
    float x = (radius+0) * sin(p.x) * cos(p.y);
    float y = (radius+0) * sin(p.x) * sin(p.y);
    float z = (radius+0) * cos(p.x);
    glVertex3d(x, y, z);
}

void GeometryView::drawLine(const Vector2D &a, const Vector2D &b)
{
    glBegin(GL_LINE_STRIP);

    int n = quality;

    Vector3D c = toDecard(a);

    Vector3D d = toDecard(b);


    for (int i = 0; i <= n; ++i)
    {
        double k1 = (double)i/(double)n;
        double k2 = 1 - k1;

        Vector3D e1 = c;
        e1.mul(k1);
        Vector3D e2 = d;
        e2.mul(k2);
        e1 += e2;

        e1.normalize();
        e1.mul(radius);

        glVertex3d(e1.x, e1.y, e1.z);
    }

    glEnd();
}

void GeometryView::render()
{
    glEnable( GL_BLEND );
    //glBlendFunc( GL_SRC_ALPHA_SATURATE, GL_SRC_ALPHA );
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();

    if (type == 0)
    {
        glTranslated(position.x, position.y, position.z);
        glRotated(angle, 0, 0, 1);

        glPointSize(1);
        glBegin(GL_POINTS);
        glColor4f(0.5, 0.5, 0.5, 0.5);

        int n = quality / 2;

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


        /*drawLine(Vector2D(0.0, 0.0), Vector2D(M_PI / 2, 0.0));
        drawLine(Vector2D(M_PI / 2, 0.0), Vector2D(M_PI, 0.0));
        drawLine(Vector2D(M_PI, 0.0), Vector2D(3.0 * M_PI / 2.0, 0.0));
        drawLine(Vector2D(3.0 * M_PI / 2.0, 0.0), Vector2D(M_PI * 2, 0.0));

        drawLine(Vector2D(0.0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2));
        drawLine(Vector2D(M_PI / 2, M_PI / 2), Vector2D(M_PI, M_PI / 2));
        drawLine(Vector2D(M_PI, M_PI / 2), Vector2D(3 * M_PI / 2, M_PI / 2));
        drawLine(Vector2D(3 * M_PI / 2, M_PI / 2), Vector2D(M_PI * 2, M_PI / 2));

        drawLine(Vector2D(M_PI / 2, 0.0), Vector2D(M_PI / 2, M_PI / 2));
        drawLine(Vector2D(M_PI / 2, M_PI / 2), Vector2D(M_PI / 2, M_PI));
        drawLine(Vector2D(M_PI / 2, M_PI), Vector2D(M_PI / 2, 3 * M_PI / 2));
        drawLine(Vector2D(M_PI / 2, 3 * M_PI / 2), Vector2D(M_PI / 2, M_PI * 2));*/

        glColor4f(1, 0, 0, 0.3);

        for (int i = 0; i < lines.size(); ++i)
        {
            drawLine(lines[i].first, lines[i].second);
        }


        glPointSize(5);
        glBegin(GL_POINTS);
        glColor3f(1, 1, 0);
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
