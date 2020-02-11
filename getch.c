/*
   Course:      COMP-381 Systems Programming
   Program:     getch.c
   Description: handles getting user input one character at a time
			 taken from "The C Programming Language"
   Author:      Hudson Whittaker
   Date:        1/30/2020
*/

#include "calc.h"
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
