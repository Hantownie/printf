#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - entry point to print format specifiers
 * @format: list of specifiers
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list list;

	int num = 0;

	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			fhandle(STDOUT_FILENO, list, &format, &num);
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			num++;
		}
		format++;
	}
	va_end(list);
	return (num);
}
