#include "axisview.h"

AxisView::AxisView()
{

}

AxisView::~AxisView()
{

}

void AxisView::render()
{
    glPushMatrix();

    glBegin(GL_LINES);

    glColor3f(1, 0 ,0);
    glVertex3d(0, 0, 0);
    glVertex3d(50, 0, 0);

    glColor3f(0, 1 ,0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 50, 0);

    glColor3f(0, 0 , 1);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 50);

    glEnd();

    glPopMatrix();
}
