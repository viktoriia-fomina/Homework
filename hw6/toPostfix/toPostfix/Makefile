all: toPostfix

toPostfix: Element.o toPostfix.o Stack.o main.o
	g++ Element.o toPostfix.o Stack.o main.o -o toPostfix

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
