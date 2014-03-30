#ifndef AXISVIEW_H
#define AXISVIEW_H

#include "QtOpenGL"

#include "view.h"

class AxisView : public View
{
public:
    AxisView();
    virtual ~AxisView();
    virtual void render();
};

#endif // AXISVIEW_H
