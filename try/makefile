all:	hello
 
hello: main.o hello.o
	g++ -o hello main.o hello.o
 
main.o: main.cpp hello.h
	g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic
 
hello.o: hello.cpp hello.h
	g++ -o hello.o hello.cpp -c -W -Wall -ansi -pedantic
 
clean:
	rm -rf *.o *~ hello