#include "main.h"

/**
 * _flags - Evaluates active flags
 * @format: Formatted string used to print the arguments
 * @v: store a parameter.
 * Return: The flags
 */
int _flags(const char *format, int *v)
{
	int g; 
	int hold_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (hold_i = *v + 1; format[hold_i] != '\0'; hold_i++)
	{
	for (g = 0; FLAGS_CH[g] != '\0'; g++)
	if (format[hold_i] == FLAGS_CH[g])
	{
			flags |= FLAGS_ARR[g];
			break;
	}

	if (FLAGS_CH[g] == 0)
	break;
	}

	*v = hold_i - 1;

	return (flags);
}
