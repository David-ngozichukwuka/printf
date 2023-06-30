#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function for printing non-printable chars */
int print_non_printable(va_list types, char buffer[],int flags, int width, int precision, int size);

/* Functions for flag, precision, width, size */
int flags(const char *format, int *v);
int precision(const char *format, int *v, va_list list);
int derive_width(const char *format, int *v, va_list list);
int derive_size(const char *format, int *v);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],int flags, int width, int precision, int size);

/* Function for printing memory address */
int print_pointer(va_list types, char buffer[],int flags, int width, int precision, int size);

/* Function that prints a pointer */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function that outputs a string in Rot13 format */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);


/* SIZES */
#define S_SHORT 1
#define S_SHORT_2

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
