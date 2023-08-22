#include "main.h"

/**
 * char_h - Prints a string
 * @c: char
 * @output: array to handle print
 * Return: Number of chars printed.
 */
int char_h(char c, char output[])
{
	int i = 0;

	output[i++] = c;
	output[i] = '\0';
	return (write(1, &output[0], 1));
}
