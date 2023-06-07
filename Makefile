build:
	gcc -Wall -Wextra -pedantic -I./headers ./src/*.c -lm $(pkg-config --cflags sdl2) -lSDL2 $(pkg-config --cflags SDL2_image) -lSDL2_image -o maze

run:
	./maze

clean:
	rm -f maze
