calc: getch.o getop.o main.o stack.o
	cc -o calc getch.o getop.o main.o stack.o -lm

run: calc
	calc

main.o: main.c calc.h
	cc -c main.c
stack.o: stack.c calc.h
	cc -c stack.c
getop.o: getop.c calc.h
	cc -c getop.c
getch.o: getch.c calc.h
	cc -c getch.c

clean:
	rm*.o