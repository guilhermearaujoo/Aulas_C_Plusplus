all:retangulo
 
retangulo: main.o retangulo.o
	g++ -o retangulo main.o retangulo.o
 
main.o: main.cpp retangulo.h
	g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic -std=c++17
 
retangulo.o: retangulo.cpp retangulo.h
	g++ -o retangulo.o retangulo.cpp -c -W -Wall -ansi -pedantic -std=c++17
 
clean:
	rm -rf *.o *~ retangulo