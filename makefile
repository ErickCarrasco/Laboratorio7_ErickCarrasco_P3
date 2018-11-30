execute:	Main.o Matriz.o
	g++ Main.o Matriz.o -o execute

Matriz.o:	Matriz.h Matriz.cpp
	g++ -c Matriz.cpp

Main.o:	Main.cpp
	g++ -c Main.cpp