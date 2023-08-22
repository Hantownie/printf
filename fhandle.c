#include "main.h"

/**
 * fhandle - entry function to handle the format specifiers
 * @output: array to handle print
 * @list: name of argument list
 * @format_p: formatted string
 * @num: index
 * Return: 1 || 2
 */

int fhandle(const char *format_p, int *num, va_list list, char output[])
{
	int i, length = 0;
	int chars = -1;
	form_t cspecs[] = {
		 {'c', p_char}, {'s', p_string}, {'%', p_mod},
		 {'\0', NULL}
	};

	i = 0;
	while (cspecs[i].form != '\0')
	{
		if (format_p[*num] == cspecs[i].form)
			return (cspecs[i].fn(list, output));
		i++;
	}
	if (cspecs[i].form == '\0')
	{
		if (format_p[*num] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		length += write(1, &format_p[*num], 1);
		return (length);
	}
	return (chars);
}
