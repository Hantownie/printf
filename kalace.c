#include "main.h"

void print_output(char output[], int *outin);
/**
 * _printf - entry point to print format specifiers
 * @format: list of specifiers
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	int i, chars = 0, outin = 0, spec = 0;
	va_list list;
	char output[O_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			output[outin++] = format[i];
			if (outin == O_SIZE)
				print_output(output, &outin);
			chars++;
		}
		else
		{
			print_output(output, &outin);
			++i;
			spec = fhandle(format, &i, list, output);
			if (spec == -1)
				return (-1);
			chars += spec;
		}
		i++;
	}
	print_output(output, &outin);
	va_end(list);
	return (chars);
}
/**
 * print_output - prints chars saved
 * @output: char array
 * @outin: length
 */
void print_output(char output[], int *outin)
{
	char *r = 0;

	if (*outin > 0)
	{
		*r = write(1, &output[0], *outin);
		if (r == NULL)
		{
		}
	}
	*outin = 0;
}
