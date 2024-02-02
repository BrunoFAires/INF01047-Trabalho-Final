./bin/Linux/main: src/main.cpp src/glad.c src/textrendering.cpp src/collision.cpp src/Player.cpp include/stb_image.h include/tiny_obj_loader.h include/matrices.h include/utils.h include/dejavufont.h include/collision.h include/Camera.h include/Player.h
	mkdir -p bin/Linux
	g++ -std=c++11 -Wall -Wno-unused-function -g -I ./include/ -o ./bin/Linux/main src/Player.cpp src/collision.cpp src/Camera.cpp src/tiny_obj_loader.cpp src/stb_image.cpp src/glad.c src/main.cpp src/textrendering.cpp ./lib-linux/libglfw3.a -lrt -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXxf86vm -lXcursor

.PHONY: clean run ./bin/Linux/main
clean:
	rm -f bin/Linux/main

run: ./bin/Linux/main
	cd bin/Linux && ./main
