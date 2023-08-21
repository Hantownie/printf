#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
void fhandle(int des, va_list list, const char **format_p, int *num);
#endif
