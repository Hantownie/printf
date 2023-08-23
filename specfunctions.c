#include "main.h"

/**
 * p_char - Prints a char
 * @list: List  of arguments
 * @output: array to handle print
 * Return: Number of chars printed
 */
int p_char(va_list list, char output[])
{
	char c = va_arg(list, int);

	return (write(1, &c, 1));
}
/**
 * p_string - Prints a string
 * @list: List  of arguments
 * @output: array to handle print
 * Return: Number of chars printed
 */
int p_string(va_list list, char output[])
{
	int len = 0;
	char *str = va_arg(list, char *);

	UNUSED(output);
	if (str == NULL)
		str = "(null)";
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
/**
 * p_mod - Prints percent sign
 * @list: List  of arguments
 * @output: array to handle print
 * Return: Number of chars printed
 */
int p_mod(va_list list, char output[])
{
	UNUSED(list);
	UNUSED(output);
	return (write(1, "%%", 1));
}
