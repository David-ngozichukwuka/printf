/* Function for printing an unsigned number in octal */
/**
 * print_octal - Outputs an unsigned number in octal notation
 * @types: The Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{

	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	int x = BUFF_SIZE - 2;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	for (; num > 0; num /= 8, x--)
	{
		buffer[x] = (num % 8) + '0';
	}

	if (flags & F_HASH && init_num != 0)
	buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/* Function to print an hexadecimal */

/**
 * print_hexadecimal - Outputs an unsigned number in hexadecimal 
 * @buffer: Buffer array for printing
 * @types: the arguments list
 * @flags: Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/* Function to print a hexadecimal in uppercase */

/**
 * print_hexa_upper - Outputs an unsigned number in uppercase hexadecimal
 * @types: the arguments list
 * @buffer: Buffer array for printing
 * @flags: Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/* Function to ouput an unsigned number */
/**
 * print_unsigned - Outputs an unsigned number
 * @buffer: Buffer array for printing
 * @types: the arguments list
 * @flags: Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total number of chars printed
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned long int num = va_arg(types, unsigned long int);
	int x = BUFF_SIZE - 2;

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	for (;, num > 0; num /= 10)
	{
		buffer[x--] = (num % 10) + '0';
		x++;
	}

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}


