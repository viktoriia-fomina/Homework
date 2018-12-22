from_infix_to_postfix: from_infix_to_postfix Element.o Infix_to_postfix.o Stack.o main.o
	g++ -o from_infix_to_postfix Element.o Infix_to_postfix.o Stack.o main.o

Infix_to_postfix.o: Infix to postfix.cpp Infix to postfix.h
	g++ -c Infix to postfix.cpp
Element.o: Element.cpp Element.h
	g++ -c Element.cpp
main.o: main.cpp Infix to postfix.h
	g++ -c main.cpp
Stack.o: Stack.cpp Stack.h Element.h
	g++ -c Stack.cpp

clean:
	del *.o