#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * print_int - prints decimal numbers
 * @arg_list: arguments list
 * Return: number of characters printed
 */

int print_int(va_list *arg_list)
{
unsigned int divisor = 1, i, resp, charPrinted = 0;
int n = va_arg(*arg_list, int);

if (n < 0)
{
	_putchar('-');
	charPrinted++;
	n *= -1;
}

for (i = 0; n / divisor > 9; i++, divisor *= 10)
;
for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
{
	resp = n / divisor;
	_putchar('0' + resp);
}
return (charPrinted);
}

/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */
int print_unsigned(va_list *arg)
{
int divisor = 1, i, resp;
unsigned int n = va_arg(*arg, unsigned int);

for (i = 0; n / divisor > 9; i++, divisor *= 10)
;
for (; divisor >= 1; n %= divisor, divisor /= 10)
{
	resp = n / divisor;
	_putchar('0' + resp);
}
return (i + 1);
}

/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_oct(va_list *arg)
{
	unsigned int num = va_arg(*arg, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}

