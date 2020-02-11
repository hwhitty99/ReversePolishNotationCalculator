/*
   Course:      COMP-381 Systems Programming
   Program:     stack.c
   Description: pushes and pops doubles onto and off of an array.
			 taken from "The C Programming Language"
   Author:      Hudson Whittaker
   Date:        1/30/2020
*/

#include "calc.h"
#include <stdio.h>
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

void push(double f)	/* push: push f onto value stack */
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void) /* pop: pop and return top value from stack */
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}