#include "main.h"

/* Function to print a character */

/**
 * print_char - Prints a character
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specificer
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],int flags, int width, int precision, int size)
{
	char x = (char)va_arg(types, int);
	int res = handle_write_char(x, buffer, flags, width, precision, size);
	return (res);
}

/* Function to print a string */

/**
 * print_string - Prints a string
 * @types: Arguments list
 * @buffer:Buffer array for print
 * @flags: Calculates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],int flags, int width, int precision, int size)
{
	int a;
	int length = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	
	if (str == NULL)
{
	str = "(null)";
	if (precision - 6 >= 0)
	str = "      ";
}

	while (str[length] != '\0')
	length++;

	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
{
	if (flags & F_MINUS)
{
	write(1, &str[0], length);
												
	for (a = width - length; a > 0; a--)
	write(1, " ", 1);
	return (width);
}

	else
{
	for (a = width - length; a > 0; a--)
	write(1, " ", 1);
	write(1, &str[0], length);
	return (width);
}

}

	return (write(1, str, length));
}

/* Function for printing a percentage sign */

/**
 * print_percent - Prints a percent sign
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: derives the width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/* Function for printing integer */
/**
 * print_int - Print integer
 * @types: Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Calculates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int s;
	int negative = 0;
	long int n;
	unsigned long int num;
						
	i = BUFF_SIZE - 2;
	n = va_arg(types, long int);

	n = convert_size_number(n, size);
	if (n == 0)
	buffer[s--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
{
	num = (unsigned long int)((-1) * n);
	negative = 1;
}

	while (num > 0)
{
	buffer[s--] = (num % 10) + '0';
	num /= 10;
}

	s++;

	return (write_number(negative, s, buffer, flags, width, precision, size));
}

/* Functions that Prints a binary */

/**
 * print_binary - Prints an unsigned number
 * @types: Argument List
 * @buffer: Buffer  array to handle print
 * @flags:  Calculates active flags
 * @width: derive width
 * @precision: Precision specificiers
 * @size: Size specifier
 * Return: Numbers of characters printed.
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int p, m;
	unsigned int q, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	p = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = p / q;

	for (q = 1; q < 32; q++)
	{
	m = m >> 1;
	a[q] = (p / q) % 2;
	}

	for (int q = 0, sum = 0, count = 0; q < 32; q++)
	{
	sum += a[q];
	if (sum || q == 31)
	{
	char z = '0' + a[q];
	write(1, &z, 1);
	count = count + 1;
	}
	}

	return (count);
}

