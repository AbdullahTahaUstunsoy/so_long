/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:04:51 by austunso          #+#    #+#             */
/*   Updated: 2024/11/27 17:44:38 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *last, ...);
int	ft_check_format2(char form, va_list ap);
int	ft_check_format(char form, va_list ap);
int	ft_print_digit(long n, int base, char form);
int	ft_print_address(unsigned long n, unsigned long base);
int	ft_print_string(char *str);
int	ft_print_char(int c);

#endif
