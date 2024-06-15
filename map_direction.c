#include <stdio.h>
#include "map_direction.h"


void MapDirection_toString(MapDirection direction)
{
    switch (direction)
    {
    case NORTH:
        printf("NORTH\n");
        break;
    case EAST:
        printf("EAST\n");
        break;
    case SOUTH:
        printf("SOUTH\n");
        break;
    case WEST:
        printf("WEST\n");
        break;
    default:
        printf("UNKNOWN\n");
        break;
    }
}
MapDirection MapDirection_next(MapDirection direction)
{
    switch (direction)
    {
    case EAST:
        return SOUTH;
        break;
    case SOUTH:
        return WEST;
        break;
    case WEST:
        return NORTH;
        break;
    case NORTH:
        return EAST;
        break;
    }
}
MapDirection MapDirection_previous(MapDirection direction)
{
    switch (direction)
    {
    case EAST:
        return NORTH;
        break;
    case SOUTH:
        return EAST;
        break;
    case WEST:
        return SOUTH;
        break;
    case NORTH:
        return WEST;
        break;
    }
}