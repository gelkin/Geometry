#include "exampleclass.h"

ExampleClass::ExampleClass()
{
    // 1 spherical right triangle
    space->addLine(Vector2D(0, 0), Vector2D(M_PI / 2, 0));
    space->addLine(Vector2D(M_PI / 2, 0), Vector2D(M_PI / 2, M_PI / 2));
    space->addLine(Vector2D(0.0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2));

    // Add point and remove equal point
    space->addPoint(Vector2D(5,5));
    space->addPoint(Vector2D(5,5));

    // 30 random points
    for (int i = 0; i < 30; ++i)
    {
        Vector2D v;
        v.x = Random::nextDouble(0, M_PI);
        v.y = Random::nextDouble(0, M_PI);
        space->addPoint(v);
    }
}
