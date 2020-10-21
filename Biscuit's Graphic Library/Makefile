all:	compile link run

FILENAME = main

compile:
		g++ $(FILENAME).cpp -c -o $(FILENAME).o
link:
		g++ $(FILENAME).o -o $(FILENAME) -std=c++11 \
		-lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr \
		-lpthread -lXi -ldl -lXinerama -lXcursor 
run:
		./$(FILENAME)