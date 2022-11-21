FLAGS = -Werror -Wextra -Wall
CC = gcc

all: style pong clean

style:
	cp ../materials/.clang-format .
	clang-format -i *.c
	clang-format -n *.c
	rm .clang-format

pong: brains.o brains.a
	$(CC) $(FLAGS) pong.c -L ../ brains.a -o ../Pong.exe
	./../Pong.exe

brains.a:
	ar crv brains.a brains.o

brains.o:
	$(CC) $(FLAGS) -c brains.c -o brains.o

clean:
	rm pong *o *out *a