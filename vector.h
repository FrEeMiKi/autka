#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef enum { false, true } bool;

typedef struct Vector
{
    int x;
    int y;
} Vector;

void Vector_toString(Vector vector);
bool Vector_precedes(Vector vector1, Vector vector2);
bool Vector_follows(Vector vector1, Vector vector2);
Vector Vector_add(Vector vector1, Vector vector2);
Vector Vector_subtract(Vector vector1, Vector vector2);
Vector Vector_upperRight(Vector vector1, Vector vector2);
Vector Vector_lowerLeft(Vector vector1, Vector vector2);
Vector Vector_opposite(Vector vector);
bool Vector_equals(Vector vector1, Vector vector2);

#endif // VECTOR_H