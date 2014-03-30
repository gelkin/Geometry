Geometry
========

Следует учесть, что инструкция написана исходя из того, что перед установкой была уже выполнена инструкция Ковалева и все зависимости сохранились. Также я надеюсь, что будет использоваться QtCreator >= 5.0 && (Ubuntu >=12.0 || Windows >= 7). Иначе, если хотя один из пунктов не выполнен, то за работоспособность кода я не отвечаю :) 

В общем случае, нужно:
```sudo apt-get install qtcreator git cmake-curses-gui libgmp-dev libqt4-dev libboost1.54-all-dev subversion```

## Controls

**W, UP** - decrease colatitude

**S, DOWN** - increase colatitude


**A, LEFT** - decrease azimuth

**D, RIGHT** - increase azimuth


**-, +, Mouse wheel** - zoom in/out

**V**- put 1 point at current coordinateses

**X** - delete 1 point from current coordinateses

**R** - reset

## Getting Started
1. Скачиваем проект целиком ```git clone git://github.com/khovanskiy/geometry.git```
2. Создаем класс и наследуем его от класса Visualization c public видимостью.
3. Для добавления точки пишем: ```space->addPoint(Vector2D(x1, y1));```
4. Для добавления полилинии пишем: ```space->addLine(Vector2D(x1, y1), Vector2D(x2, y2));```

**Важно:** Vector2D - обычный 2-d вектор, и очевидно, что долгота и широта != x и y. Поэтому условно считается, что координаты задаются в формате Vector2D my_vector(colatitude, azimuth).

## Examples
Изменение радиуса сферы на 200rem
```
space->setRadius(200);
```

Добавляем на сферу сферический прямоугольный треугольник
```
space->addLine(Vector2D(0, 0), Vector2D(M_PI / 2, 0));
space->addLine(Vector2D(M_PI / 2, 0), Vector2D(M_PI / 2, M_PI / 2));
space->addLine(Vector2D(0.0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2));
```

**Важно:** Легко понять, что ```space->addLine(Vector2D(0, 0), Vector2D(M_PI, 0));``` не стоит писать, т.к. в этом случае существует бесконечное множество полилиний. Аналогично, и для всех линий, у которых координата одного конца совпадает с соответствующей координатой другого конца, а другая пара координат отличается на угол в M_PI.

Добавляем на сферу точку с *полярным* углом в 30 градусов и *азимутальным* в 180 градусов
```
space->addPoint(Vector2D(M_PI / 6, M_PI));
```

Удалим со сферы точку с *полярным* углом в 15 градусов и *азимутальным* в 97 градусов
```
space->removePoint(Vector2D(M_PI / 8, 97 * M_PI / 180));
```

**Важно:** Т.к. у нас сферическое неограниченное пространство, то на сфере могут быть точки и полилинии с периодическими координатами. Например, точки: ```Vector2D(1, M_PI) == Vector2D(1, 3 * M_PI) == Vector2D(1, 5 * M_PI)```, а отрисовка будет только одной точки.

