/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:00:54 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/24 17:13:02 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	parse_format(va_list args, const char *format)
{
	if (format[0] == 'c')
		return (ft_printf_char(va_arg(args, int)));
	else if (format[0] == 's')
		return (ft_print_string(va_arg(args, const char *)));
	else if (format[0] == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (format[0] == 'd')
		return (ft_printf_int(va_arg(args, int), "0123456789"));
	else if (format[0] == 'i')
		return (ft_printf_int(va_arg(args, int), "0123456789"));
	else if (format[0] == 'u')
		return (ft_printf_uint(va_arg(args, unsigned int), "0123456789"));
	else if (format[0] == 'x')
		return (ft_printf_uint(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format[0] == 'X')
		return (ft_printf_uint(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[0] == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_format(const char *str, va_list args)
{
	int		i;
	int		total_bytes;

	total_bytes = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			total_bytes += parse_format(args, &str[i + 1]);
			i++;
		}
		else
			total_bytes += write(1, &str[i], 1);
		i++;
	}
	return (total_bytes);
}
