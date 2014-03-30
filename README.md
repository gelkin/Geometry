Geometry
========
## Controls

**W, UP** - decrease colatitude

**S, DOWN** - increase colatitude


**A, LEFT** - decrease azimuth

**D, RIGHT** - increase azimuth


**-, +, Mouse wheel** - zoom in/out

**V**- put 1 point at current coordinateses

**X** - delete 1 point from current coordinateses

**R** - reset

## How to setup

1. Создаем класс и наследуем его от класса Visualization c public видимостью.
2. Для добавления точки пишем:
  ```
  space->addPoint(Vector2D(x1, y1));
  ```
3. Для добавления полилинии пишем:
  ```
  space->addLine(Vector2D(x1, y1), Vector2D(x2, y2));
  ```

**Важно:** Vector2D - обычный 2-d вектор, и очевидно, что долгота и широта != x и y. Поэтому условно считается, что координаты задаются в формате Vector2D my_vector(colatitude, azimuth).
