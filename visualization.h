#ifndef PROGRAM_H
#define PROGRAM_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QTimer>

#include "axisview.h"
#include "geometryview.h"
#include "console.h"
#include "vector2d.h"
#include "vector3d.h"
#include "random.h"

class Visualization : public QGLWidget
{
    Q_OBJECT
    
public:
    Visualization(QWidget *parent = 0);
    ~Visualization();

    void initializeGL();
    void resizeGL(int, int);
    void paintGL();
    void keyPressEvent(QKeyEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);
    void perspective(float, float, float, float);
    void lookAt(const Vector3D& eye, const Vector3D& lookAt, const Vector3D& up);

private:
    float distance;
    float view_angle_a;
    float view_angle_b;
    bool rotating;
    GeometryView* space;
    QTimer* timer;
};

#endif // PROGRAM_H
