all: neco
	./neco

neco: main.o neco.o
	g++ -std=c++17 -o neco main.o neco.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

neco.o : neco.cpp neco.hpp
	g++ -std=c++17 -c neco.cpp

main.o : main.cpp
	g++ -std=c++17 -c main.cpp

clean:
	rm -rf *.o neco