#include "main.h"

void print_output(char output[], int *outin);
/**
 * _printf - entry point to print format specifiers
 * @format: list of specifiers
 * Return: an integer
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, chars = 0, outin = 0, spec = 0;
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
			{
				chars += outin;
				print_output(output, &outin);
			}
			chars++;
		}
		else
		{
			print_output(output, &outin);
			i++;
			spec = fhandle(format, &i, list, output);
			if (spec == -1)
			{
				va_end(list);
				return (-1);
			}
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
	if (*outin > 0)
	{
		write(1, &output[0], *outin);
	}
	*outin = 0;
}
