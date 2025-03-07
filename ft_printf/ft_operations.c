/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:45:59 by austunso          #+#    #+#             */
/*   Updated: 2025/03/08 00:32:42 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		result += ft_print_char((int)str[i]);
		i++;
	}
	return (result);
}

int	ft_print_address(unsigned long n, unsigned long base)
{
	int		result;
	char	*digit_set;

	result = 0;
	digit_set = "0123456789abcdef";
	if (n < base)
		result += ft_print_char(digit_set[n]);
	else
	{
		result += ft_print_address(n / base, base);
		result += ft_print_address(n % base, base);
	}
	return (result);
}

int	ft_print_digit(long n, int base, char form)
{
	char	*digit_set;
	int		result;

	result = 0;
	if (form == 'X')
		digit_set = "0123456789ABCDEF";
	else
		digit_set = "0123456789abcdef";
	if (n < 0)
	{
		result += write(1, "-", 1);
		result += ft_print_digit(-n, base, form);
	}
	else if (n < base)
	{
		result += ft_print_char(digit_set[n]);
	}
	else
	{
		result += ft_print_digit(n / base, base, form);
		result += ft_print_digit(n % base, base, form);
	}
	return (result);
}
