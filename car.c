#include <stdio.h>
#include "car.h"
#include "map_direction.h"
#include "vector.h"
#include "move_direction.h"


void Car_toString(Car car)
{
    printf("Position: ");
    Vector_toString(car.position);
    printf("Direction: ");
    MapDirection_toString(car.direction);
}

bool Car_isAt(Car car, Vector position)
{
    if (car.position.x == position.x && car.position.y == position.y)
    {
        return true;
    }
    return false;
}



void Car_move(Car *car, MoveDirection direction, Vector size)
{
    switch (direction)
    {
    case BACKWARD:
        switch (car->direction)
        {
        case SOUTH:
            if (car->position.y > 0)
            {
                car->position.y--;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case WEST:
            if (car->position.x < size.x - 1)
            {
                car->position.x++;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case NORTH:
            if (car->position.y < size.y -1)
            {
                car->position.y++;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case EAST:
            if (car->position.x > 0)
            {
                car->position.x--;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        }
        break;
    case FORWARD:
        switch (car->direction)
        {
        case SOUTH:
            if (car->position.y < size.y - 1)
            {
                car->position.y++;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case WEST:
            if (car->position.x > 0)
            {
                car->position.x--;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case NORTH:
            if (car->position.y > 0)
            {
                car->position.y--;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        case EAST:
            if (car->position.x < size.x - 1)
            {
                car->position.x++;
            }
            else
            {
                car->direction = MapDirection_next(car->direction);
                car->direction = MapDirection_next(car->direction);
            }
            break;
        }
        break;
    case LEFT:
        car->direction = MapDirection_previous(car->direction);
        break;
    case RIGHT:
        car->direction = MapDirection_next(car->direction);
        break;
    }
}

Vector Car_getNextPosition(Car car, MoveDirection direction, Vector size)
{
    Vector newPosition = car.position;
    switch (direction)
    {
    case BACKWARD:
        switch (car.direction)
        {
        case SOUTH:
            if (car.position.y > 0)
            {
                newPosition.y--;
            }
            break;
        case WEST:
            if (car.position.x < size.x - 1)
            {
                newPosition.x++;
            }
            break;
        case NORTH:
            if (car.position.y < size.y - 1)
            {
                newPosition.y++;
            }
            break;
        case EAST:
            if (car.position.x > 0)
            {
                newPosition.x--;
            }
            break;
        }
        break;
    case FORWARD:
        switch (car.direction)
        {
        case NORTH:
            if (car.position.y > 0)
            {
                newPosition.y--;
            }
            break;
        case EAST:
            if (car.position.x < size.x - 1)
            {
                newPosition.x++;
            }
            break;
        case SOUTH:
            if (car.position.y < size.y - 1)
            {
                newPosition.y++;
            }
            break;
        case WEST:
            if (car.position.x > 0)
            {
                newPosition.x--;
            }
            break;
        }
        break;
    case LEFT:
        break;
    case RIGHT:
        break;
    }
    return newPosition;
}

