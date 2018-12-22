toPostfix: Element.o toPostfix.o Stack.o main.o
	g++ -o Element.o toPostfix.o Stack.o main.o

toPostfix.o: toPostfix.cpp toPostfix.h
	g++ -c toPostfix.cpp
Element.o: Element.cpp Element.h
	g++ -c Element.cpp
main.o: main.cpp toPostfix.h
	g++ -c main.cpp
Stack.o: Stack.cpp Stack.h Element.h
	g++ -c Stack.cpp

clean:
	del *.o
