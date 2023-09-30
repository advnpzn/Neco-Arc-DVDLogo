all: neco
	./src/neco

neco: src/main.o src/neco.o
	g++ -std=c++17 -o src/neco src/main.o src/neco.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

neco.o : src/neco.cpp src/neco.hpp
	g++ -std=c++17 -c src/neco.cpp

main.o : src/main.cpp
	g++ -std=c++17 -c src/main.cpp

clean:
	rm -rf src/*.o src/neco