#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x)(void)(x)

#define O_SIZE 1024

struct form
{
	char form;
	int (*fn)(va_list, char[]);
};

typedef struct form form_t;
int char_h(char c, char output[]);

int _printf(const char *format, ...);
int fhandle(const char *format_p, int *num, va_list list, char output[]);
void print_output(char output[], int *outin);
int p_char(va_list list, char output[]);
int p_string(va_list list, char output[]);
int p_mod(va_list list, char output[]);
#endif
