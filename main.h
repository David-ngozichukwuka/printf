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

