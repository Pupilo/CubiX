LIBS_OBJS = Engine.o Menu.o Rotations.o
MAIN_OBJ = main.o main.c

FLAGS = -w -g -o 
CFLAGS = -c -g

CC = gcc

all:
    $(CC) $(CFLAGS) Engine.c
    $(CC) $(CFLAGS) Menu.c
	$(CC) $(CFLAGS) Rotations.c
	$(CC) $(FLAGS) $(MAIN_OBJ) $(LIBS_OBJS) -o CubiX -lm
clean:
	rm -f $(LIBS_OBJS)
