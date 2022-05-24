#include "main.h"
/**
 * _printf - produces format output
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
	return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);or (p = (char *)format; *p; p++)
{
	init_params(&params, ap);
	if (*p != '%')
{
	sum += _putchar(*p);
	continue;
}
	start = p;
	p++;
	while (get_flag(p, &params))
{
	p++;
}
	p = get_width(p, &params, ap);
	p = get_precision(p, &params, ap);
	if (get_modifier(p, &params))
	p++;
	if (!get_specifier(p))
	sum += print_from_to(start, p,
	params.l_modifier || params.h_modifier ? p - 1 : 0);

	else
	sum += get_print_func(p, ap, &params);
}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
