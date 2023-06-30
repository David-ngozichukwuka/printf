#include "main.h"

/**
 * derive_size - Evaluates the size to cast the argument
 * @format: Formatted string for printing the arguments
 * @v: Arguments list to be printed
 *
 * Return: Precision.
 */
int derive_size(const char *format, int *v)
{
	int hold_i = *v + 1;
	int size = 0;

	if (format[hold_i] == 'l')
	size = S_LONG;
	else if (format[hold_i] == 'h')
	size = S_SHORT;

	if (size == 0)
	*v = hold_i - 1;
	else
	*v = hold_i;

	return (size);
}
