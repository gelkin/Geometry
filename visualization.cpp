#include "visualization.h"

#include <math.h>

Visualization::Visualization(QWidget *parent) : QGLWidget(parent)
{
    setWindowTitle("Sphere geometry visualization");
    setMouseTracking(true);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    rotating = 0;
    view_angle_a = 0;
    view_angle_b = M_PI / 4;
    distance = 250;
    timer->start(100);

    space = new GeometryView(100);

    // Test
    space->addLine(Vector2D(0, 0), Vector2D(M_PI / 2, 0));
    space->addLine(Vector2D(M_PI / 2, 0), Vector2D(M_PI / 2, M_PI / 2));
    space->addLine(Vector2D(0.0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2));

    for (int i = 0; i < 30; ++i)
    {
        Vector2D v;
        v.x = Random::nextDouble(0, M_PI);
        v.y = Random::nextDouble(0, M_PI);
        space->addPoint(v);
    }
}

Visualization::~Visualization()
{
    delete space;
    delete timer;
}

void Visualization::perspective(float fovx, float aspect, float zNear, float zFar)
{
    double xmax = zNear * tan(fovx * M_PI / 360.0);
    double xmin = -xmax;

    double ymin = xmin / aspect;
    double ymax = xmax / aspect;


    double m[] = {(2.0 * zNear) / (xmax - xmin),     0,                              (xmax + xmin) / (xmax - xmin),      0,
                  0,                                 (2.0 * zNear) / (ymax - ymin),  (ymax + ymin) / (ymax - ymin),      0,
                  0,                                 0,                              -(zFar + zNear) / (zFar - zNear),   -(2.0 * zFar * zNear) / (zFar - zNear),
                  0,                                 0,                              -1.0,                               0};

    glMultMatrixd(m);
}

void Visualization::lookAt(const Vector3D &camera, const Vector3D &lookAt, const Vector3D &temp)
{
    Vector3D f = lookAt;
    f -= camera;
    f.normalize();
    Vector3D up = temp;
    up.normalize();

    Vector3D s = Vector3D::cross(f, up);
    Vector3D u = Vector3D::cross(s, f);

    double M[] =
    {
        s.x, u.x, -f.x, 0,
        s.y, u.y, -f.y, 0,
        s.z, u.z, -f.z, 0,
        0, 0, 0, 1
    };

    glMultMatrixd(M);
    glTranslated(-camera.x, -camera.y, -camera.z);
}

void Visualization::initializeGL()
{
    setAutoBufferSwap(true);
    qglClearColor(Qt::black);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
}

void Visualization::resizeGL(int screen_w, int screen_h)
{
    glViewport(0, 0, screen_w, screen_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    perspective(25.0, (float)screen_w / (float)screen_h, 1.0, 150.0);
    updateGL();
}

void Visualization::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_R:
        {
            view_angle_a = 0;
            view_angle_b = M_PI / 4;
        } break;
        case Qt::Key_Left:
        {
            view_angle_a -= 0.1f;
        } break;
        case Qt::Key_Right:
        {
            view_angle_a += 0.1f;
        } break;
        case Qt::Key_Up:
        {
            view_angle_b -= 0.1f;
        } break;
        case Qt::Key_Down:
        {
            view_angle_b += 0.1f;
        } break;
        case Qt::Key_Equal:
        case Qt::Key_Plus:
        {
            distance /= 2;
        } break;
        case Qt::Key_Minus:
        {
            distance *= 2;
        } break;
        case Qt::Key_Space:
        {
            rotating = !rotating;
        } break;
        default:
        {
            Console::print(e->key());
        }
    }

    e->accept();
    //updateGL();
}

void Visualization::mouseMoveEvent(QMouseEvent *e)
{
    e->accept();
    //updateGL();
}

void Visualization::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0)
    {
        distance -= 20;
    }
    else
    {
        distance += 20;
    }
    e->accept();
    //updateGL();
}

void Visualization::paintGL()
{
    if (rotating)
    {
        view_angle_a -= 0.1f;
        if (view_angle_a >= M_PI * 2)
        {
            view_angle_a = 0;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //lookAt(Vector3D(200, 200, 200), Vector3D(0,0,0), Vector3D(0,0,1));

    lookAt(Vector3D(distance * sin(view_angle_b) * cos(view_angle_a), distance * sin(view_angle_b) * sin(view_angle_a), distance * cos(view_angle_b)), Vector3D(0,0,0), Vector3D(0,0,1));

    AxisView axis;
    axis.render();
    space->render();
}
