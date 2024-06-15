#include <stdio.h>
#include "vector.h"


void Vector_toString(Vector vector)
{
    printf("(%d, %d)\n", vector.x, vector.y);
}

bool Vector_precedes(Vector vector1, Vector vector2)
{
    return (vector1.x < vector2.x && vector1.y < vector2.y);
}

bool Vector_follows(Vector vector1, Vector vector2)
{
    return (vector1.x >= vector2.x && vector1.y >= vector2.y);
}

Vector Vector_add(Vector vector1, Vector vector2)
{
    Vector result;
    result.x = vector1.x + vector2.x;
    result.y = vector1.y + vector2.y;
    return result;
}

Vector Vector_subtract(Vector vector1, Vector vector2)
{
    Vector result;
    result.x = vector1.x - vector2.x;
    result.y = vector1.y - vector2.y;
    return result;
}

Vector Vector_upperRight(Vector vector1, Vector vector2)
{
    Vector result;
    result.x = vector1.x > vector2.x ? vector1.x : vector2.x;
    result.y = vector1.y > vector2.y ? vector1.y : vector2.y;
    return result;
}

Vector Vector_lowerLeft(Vector vector1, Vector vector2)
{
    Vector result;
    result.x = vector1.x < vector2.x ? vector1.x : vector2.x;
    result.y = vector1.y < vector2.y ? vector1.y : vector2.y;
    return result;
}

Vector Vector_opposite(Vector vector)
{
    Vector result;
    result.x = -vector.x;
    result.y = -vector.y;
    return result;
}

bool Vector_equals(Vector vector1, Vector vector2)
{
    return (vector1.x == vector2.x && vector1.y == vector2.y);
}
