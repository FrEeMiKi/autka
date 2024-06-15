#ifndef MAP_DIRECTION_H
#define MAP_DIRECTION_H

enum MapDirection
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};
typedef enum MapDirection MapDirection;

void MapDirection_toString(MapDirection direction);
MapDirection MapDirection_next(MapDirection direction);
MapDirection MapDirection_previous(MapDirection direction);

#endif 