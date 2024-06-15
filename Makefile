
CC = gcc


CFLAGS = -Wall -Werror -std=c11


OBJ = main.o car.o map_direction.o vector.o

all: car_program

car_program: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c car.h map_direction.h vector.h move_direction.h
	$(CC) $(CFLAGS) -c main.c

car.o: car.c car.h map_direction.h vector.h move_direction.h
	$(CC) $(CFLAGS) -c car.c

map_direction.o: map_direction.c map_direction.h
	$(CC) $(CFLAGS) -c map_direction.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	rm -f *.o car_program
