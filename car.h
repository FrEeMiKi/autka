#ifndef CAR_H
#define CAR_H

#include "vector.h"
#include "map_direction.h"
#include "move_direction.h"

typedef struct Car
{
    MapDirection direction;
    Vector position;
} Car;

void Car_toString(Car car);
bool Car_isAt(Car car, Vector position);
void Car_move(Car *car, MoveDirection direction, Vector size);
Vector Car_getNextPosition(Car car, MoveDirection direction, Vector size);

#endif // CAR_H
