funix.out: main.o permissions.o directory.o funix.o 
	 g++ -o funix.out -g -w main.o permissions.o directory.o funix.o

funix.o:funix.cpp funix.h directory.h
	g++ -c funix.cpp -g -Wall
directory.o: directory.cpp directory.h permissions.h
	g++ -c directory.cpp -g -Wall
permission.o: permissions.cpp permissions.h
	g++ -c permissions.cpp -g -Wall

