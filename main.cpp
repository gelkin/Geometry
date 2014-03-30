#include "visualization.h"

#include <QApplication>

#include "vector2d.h"
#include "console.h"

/*template<class T>
int cross(const Vector2D<T>& a, const Vector2D<T>& b, const Vector2D<T>& c)
{
    T res = b.x * c.y + c.x * a.y + a.x * b.y - (a.x * c.y + a.y * b.x + c.x * b.y);
    if (res > 0)
    {
        return -1;
    }
    if (res < 0)
    {
        return 1;
    }
    return 0;
}*/

int main(int argc, char *argv[])
{
    /*gmp_randclass r(gmp_randinit_default);
    mpf_class d = r.get_f();
    Console::print(d.get_d());*/

    QApplication app(argc, argv);

    Visualization p;
    p.show();

    return app.exec();
}
