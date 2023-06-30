#include "main.h"

/**
 * precision - Evaluates the precision for printing
 * @format: Formatted string used to print the arguments
 * @v: Arguments list to be printed
 * @list: arguments list
 *
 * Return: Precision
 */
int precision(const char *format, int *v, va_list list)
{
	int hold_i = *v + 1;
	int precision = -1;

	if (format[hold_i] != '.')
	return (precision);

	precision = 0;

	for (hold_i += 1; format[hold_i] != '\0'; hold_i = hold_i + 1)
	{
	if (is_digit(format[hold_i]))
	{
	precision *= 10;
	precision += format[hold_i] - '0';
	}
	else if (format[hold_i] == '*')
	{
		hold_i++;
		precision = va_arg(list, int);
	break;
	}
	else
		break;
	}

	*v = hold_i - 1;
	return (precision);
}
