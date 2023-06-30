/**
 * print_pointer - Outputs the value of a pointer variable
 * @types: The Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total Number of chars printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int inx = BUFF_SIZE - 2;
	int length = 2, padd_start = 1; 
	char extra_c = 0, padd = ' ';	
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addresss == NULL)
	return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
	buffer[inx--] = map_to[num_addrs % 16];
	num_address /= 16;
	length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';
	if (flags & F_PLUS)
	extra_c = '+', length++;
	else if (flags & F_SPACE)
	extra_c = ' ', length++;

	inx++;

	return (write_pointer(buffer, inx, length, width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Outputs ascii codes in hexa of non printable chars
 * @types: The Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total Number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int s = 0;
	int ofset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	return (write(1, "(null)", 6));

	while (str[s] != '\0')
	{
		if (is_printable(str[s]))
		buffer[s + ofset] = str[s];
		else
	ofset += append_hexa_code(str[s], buffer, s + ofset);

	s++;
	}

	buffer[s + ofset] = '\0';

	return (write(1, buffer, s + ofset));
}

/**
 * print_reverse - Outputs a string in reverse.
 * @types: The Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total Number of chars printed
 */

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str;
	int count = 0;
	int s = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
	UNUSED(precision);

	str = ")Null(";
	}
	for (s = 0; str[s]; s++)
	;

	for (s = s - 1; s >= 0; s--)
	{
		char q = str[s];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Outputs a string in rot13
 * @types: The Arguments list
 * @buffer: Buffer array for printing
 * @flags:  Evaluates active flags
 * @width: derive width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Total Number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *str;
	int count = 0;
	unsigned int k, j;
	char in[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[30] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
				{
					x = out[j];
					write(1, &x, 1);
					count++;
					break;
				}
		}
	if (!in[j])
	{
		x = str[k];
		write(1, &x, 1);
		count++;
	}
	}
	return (count);
}
