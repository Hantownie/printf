#include "main.h"

/**
 * width_check - checking the width for format string
 * @format: pointer to format
 * @i: pointer to index of format string
 * @list: list of specifiers
 * Return: an integer
 */

int width_check(const char *format, int *i, va_list list)
