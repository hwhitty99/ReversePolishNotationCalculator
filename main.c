/*
   Course:      COMP-381 Systems Programming
   Program:     main.c
   Description: takes user mathematical input and outputs equivalent answer.
   Author:      Hudson Whittaker
   Date:        1/30/2020
*/

#include "calc.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);	/* reverse Polish calculator */

main()
{
	int type;
	double op2, op3;
	char s[MAXOP];
	double var[25];
	double ans, dup = 0;
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			push(pop() / op2);
			else
			printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op3 = pop();
			push(op3 - (int)(op3/op2) * op2);
			break;
		case 'A':
			push(ans);
			break;
		case 'D':
			push(dup = pop());
			push(dup);
			break;
		case 'S':
			op2 = pop();
			op3 = pop();
			push(op2);
			push(op3);
			break;
		case 'C':
			while(!((op2 = pop()) == 0.0));
			break;
		case '$':
			push(sin(pop()));
			break;
		case 'E':
			push(exp(pop()));
			break;
		case '^':
			op2 = pop();
			op3 = pop();
			push(pow(op3, op2));
			break;
		case 'a':
			break;
		case 'b':
			break;
		case '\n':
			printf("\t%.8g\n", ans = pop());
			break;
		default:
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
