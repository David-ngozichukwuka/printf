#include "main.h"

/**
 * derive_width - Evaluates the width for printing
 * @format: Formatted string for printing the arguments
 * @v: Arguments list to be printed
 * @list: Arguments list
 *
 * Return: width
 */
int derive_width(const char *format, int *v, va_list list)
{
	int width = 0;
	int hold_i;

	for (hold_i = *v + 1; format[hold_i] != '\0'; hold_i++)
	{
		if (is_digit(format[hold_i]))
		{
			width *= 10;
			width += format[hold_i] - '0';
		}
		else if (format[hold_i] == '*')
		{
			hold_i = hold_i + 1;
			width = va_arg(list, int);
			break;
		}
		else
		break;
	}

		*v = hold_i - 1;

		return (width);
}
