FLAGS = -Werror -Wextra -Wall
CC = gcc


all: build style clean

style:
	clang-format -i *.c
	clang-format -n *.c
build:
	$(CC) $(FLAGS) pong.c -o pong
	./pong

clean:
	rm pong