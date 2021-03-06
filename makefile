all:
	g++ -c mashinki.cpp
	g++ mashinki.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app