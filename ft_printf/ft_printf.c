/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:46:08 by austunso          #+#    #+#             */
/*   Updated: 2024/11/27 18:01:41 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char form, va_list ap)
{
	int	result;

	result = 0;
	if (form == 'd' || form == 'i')
		result += ft_print_digit(va_arg(ap, int), 10, form);
	else if (form == 'u')
		result += ft_print_digit(va_arg(ap, unsigned int), 10, form);
	else if (form == 'x' || form == 'X')
		result += ft_print_digit(va_arg(ap, unsigned int), 16, form);
	else
		result += ft_check_format2(form, ap);
	return (result);
}

int	ft_check_format2(char form, va_list ap)
{
	int		result;
	void	*ptr;

	result = 0;
	if (form == 'c')
		result += ft_print_char(va_arg(ap, int));
	else if (form == 's')
		result += ft_print_string(va_arg(ap, char *));
	else if (form == 'p')
	{
		ptr = va_arg(ap, void *);
		if (ptr == NULL)
			return (write(1, "(nil)", 5));
		result += ft_print_string("0x");
		result += ft_print_address((unsigned long)ptr, 16);
	}
	else if (form == '%')
		result += write(1, "%", 1);
	else
	{
		result += write(1, "%", 1);
		result += write(1, &form, 1);
	}
	return (result);
}

int	ft_printf(const char *last, ...)
{
	va_list	ap;
	int		i;
	int		result;

	va_start(ap, last);
	i = 0;
	result = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '%')
		{
			result += write(1, &last[i], 1);
			i++;
		}
		else
		{
			result += ft_check_format(last[i + 1], ap);
			i = i + 2;
		}
	}
	va_end(ap);
	return (result);
}
