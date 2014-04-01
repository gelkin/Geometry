#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextStream>

#include "vector2d.h"
#include "vector3d.h"

class Console
{
public:
    template<class T>

    static void print(T string)
    {
        QTextStream cout(stdout);
        cout << string << '\n';
    }

    //template<class T>
    static void print(Vector2D v)
    {
        print(QString("[")+QVariant(v.x).toString() + ", " + QVariant(v.y).toString()+"]");
    }

    static void print(Vector3D v)
    {
        print(QString("[")+QVariant(v.x).toString() + ", " + QVariant(v.y).toString()+ ", " + QVariant(v.z).toString()+"]");
    }
};

#endif // CONSOLE_H
