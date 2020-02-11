/*
   Course:      COMP-381 Systems Programming
   Program:     getop.c
   Description: gets the next operator. taken from "The C Programming Language"
   Author:      Hudson Whittaker
   Date:        1/30/2020
*/

#include "calc.h"
#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);
double vars[26];

int getop(char s[])	/* getop: get next character or numeric operand */
{
	int i, c;
	double temp;
	char alpha;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (c >= 97 && c <= 122) /* a-z variable-based value retrieval */
	{
		push(vars[c - 97]);
		return 'b';
	}
	if (!isdigit(c) && c != '.' && c != '-' && c != '=')
		return c; /* not a number or variable assignment */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()));
	if (c == '-') /* collect negative integer */
	{
		if ((s[++i] = c = getch()) == ' ' || c == '\t' || c == '\n')
		{
			ungetch(c);
			return '-';
		}
		else
			while(isdigit(s[++i] = c = getch()));
	}
	if (c == '=') /* assigns top stack element to a variable of a-z */
	{
		if ((s[++i] = c = getch()) >= 97 && c <= 122) 
		{
			push(temp = pop());
			vars[c - 97] = temp;
			return 'a';
		}
		else
		{
			ungetch(c);
			return '=';
		}
	}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}