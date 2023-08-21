#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * fhandle - entry function to handle the format specifiers
 * @des: file description
 * @list: name of argument list
 * @format_p: pointer to format
 * @num: pointer to print count of elements
 */

void fhandle(int des, va_list list, const char **format_p, int *num)
{
	char form = *(*format_p);
	char *str, c, mod;

	switch (form)
	{
		case 'c':
			{
				c = va_arg(list, int);
				write(des, &c, 1);
				(*num)++;
				break;
			}
		case 's':
			{
				str = va_arg(list, char *);
				while (*str)
				{
				write(des, str, 1);
				str++;
				(*num)++;
				}
				break;
			}
		case '%':{
				 mod = '%';
				 write(des, &mod, 1);
				 (*num)++;
				break;
			}
		default:
			{
				 mod = '%';
				 write(des, &mod, 1);
				 write(des, &form, 1);
				 (*num) += 2;
				break;
			}
	}
	(*format_p)++;
}
