#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "car.h"
#include "map_direction.h"
#include "vector.h"
#include "move_direction.h"

#define MAX_CAR_COUNT 10
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"


typedef struct RectangularMap
{
    Vector size;
    Car car[MAX_CAR_COUNT];
    int carCount;
} RectangularMap;

RectangularMap getMap()
{
    int x, y;
    char cars_c[100];
    int carCount;
    printf("Map width: ");
    scanf("%d", &x);
    printf("Map height: ");
    scanf("%d", &y);
    printf("Number of cars (or type 'random'): ");
    scanf("%s", cars_c);
    if (strcmp(cars_c, "random") == 0)
    {
    srand48(time(NULL));
    carCount = rand() % MAX_CAR_COUNT + 1;
    }
    else
    {
        carCount = ((atoi(cars_c) - 1) % MAX_CAR_COUNT) + 1;
    }
    printf("\n");
    RectangularMap map = {
        .size = {x, y},
        .carCount = carCount,
    };
    Vector positions[carCount];
    for (int i = 0; i < carCount; i++)
    {
        map.car[i].direction = (MapDirection)(rand() % 4);
        map.car[i].position = (Vector){rand() % x, rand() % y};
        positions[i] = map.car[i].position;
        for (int j = 0; j < i; j++)
        {
            if (Vector_equals(positions[j], map.car[i].position))
            {
                i--;
                break;
            }
        }
    }
    return map;
}

void CarMoveForward(RectangularMap *map, int i)
{
    Vector newPosition = Car_getNextPosition(map->car[i], FORWARD, map->size);
    bool collision = false;
    for (int j = 0; j < map->carCount; j++)
    {
        if (j != i && Car_isAt(map->car[j], newPosition))
        {
            collision = true;
            break;
        }
    }
    if (!collision)
    {
        Car_move(&map->car[i], FORWARD, map->size);
    }
}

void CarMoveBackward(RectangularMap *map, int i)
{
    Vector newPosition = Car_getNextPosition(map->car[i], BACKWARD, map->size);
    bool collision = false;
    for (int j = 0; j < map->carCount; j++)
    {
        if (j != i && Car_isAt(map->car[j], newPosition))
        {
            collision = true;
            break;
        }
    }
    if (!collision)
    {
        Car_move(&map->car[i], BACKWARD, map->size);
    }
}

void PrintArrow(MapDirection direction)
{
    switch (direction)
    {
    case NORTH:
        printf(YELLOW "↑" RESET);
        break;
    case EAST:
        printf(YELLOW "→" RESET);
        break;
    case SOUTH:
        printf(YELLOW "↓" RESET);
        break;
    case WEST:
        printf(YELLOW "←" RESET);
        break;
    }
}

int main(void)
{
    printf(RED);
    printf(" ________  ___  ___  _________  ___  __    ________     \n|\\   __  \\|\\  \\|\\  \\|\\___   ___\\\\  \\|\\  \\ |\\   __  \\    \n\\ \\  \\|\\  \\ \\  \\\\\\  \\|___ \\  \\_\\ \\  \\/  /|\\ \\  \\|\\  \\   \n \\ \\   __  \\ \\  \\\\\\  \\   \\ \\  \\ \\ \\   ___  \\ \\   __  \\  \n  \\ \\  \\ \\  \\ \\  \\\\\\  \\   \\ \\  \\ \\ \\  \\\\ \\  \\ \\  \\ \\  \\ \n   \\ \\__\\ \\__\\ \\_______\\   \\ \\__\\ \\ \\__\\\\ \\__\\ \\__\\ \\__\\ \n    \\|__|\\|__|\\|_______|    \\|__|  \\|__| \\|__|\\|__|\\|__|\n\n");
    printf("Welcome to the Autka!\n");
    printf(RESET);
    printf(GREEN "OPTIONS MENU\n" RESET);
    RectangularMap map = getMap();
    char input = 'e';
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getchar();
    
    for (int i = 0; input != 'q'; i = (i + 1) % map.carCount)
    {   
        for (int j = 0; j < map.size.x + 2; j++)
        {
            PrintArrow(map.car[i].direction);
        }
        printf(BLUE "\nCar in move: %d\n", i);
        Car_toString(map.car[i]);
        
        input = getchar();
        switch (input)
        {
        case 'w':
        case 'f':
        {
            CarMoveForward(&map, i);
            break;
        }
        case 'a':
        case 'l':
            map.car[i].direction = MapDirection_previous(map.car[i].direction);
            CarMoveForward(&map, i);
            break;
        case 'd':
        case 'r':
            map.car[i].direction = MapDirection_next(map.car[i].direction);
            CarMoveForward(&map, i);
            break;
        case 's':
        case 'b':
        {
            CarMoveBackward(&map, i);
            break;
        }
        }
        
        printf(RESET "\n\n");
        for (int j = 0; j < map.size.x + 2; j++)
        {
            printf("-");
        }
        printf("\n");

        for (int j = 0; j < map.size.y; j++)
        {
            printf("|");
            for (int k = 0; k < map.size.x; k++)
            {
                bool found = false;
                int foundCar;
                for (int l = 0; l < map.carCount; l++)
                {
                    if (Car_isAt(map.car[l], (Vector){k, j}))
                    {
                        found = true;
                        foundCar = l;
                        break;
                    }
                }
                if (found)
                {
                    if (foundCar == (i + 1) % map.carCount)
                    {
                        printf(RED "%d" RESET, foundCar);
                    }
                    else
                    {
                        printf(GREEN "%d" RESET, foundCar);
                    }
                }
                else
                {
                    printf(".");
                }
            }
            printf("|");
            printf("\n");
        }
        for (int j = 0; j < map.size.x + 2; j++)
        {
        printf("-");
        }
        printf("\n");
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}