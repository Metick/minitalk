/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:59:22 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/24 17:13:49 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = ft_format(str, args);
	va_end(args);
	return (len);
}

// int main()
// {
// 	//int test = 0;
// 	ft_printf("char: %c\n", '9');
// 	//ft_printf("pointer: %p -> %p\n", (void*)NULL, &test);
// 	ft_printf("NULL %s NULL\n", (char*)NULL);
// 	ft_printf("decimal: %d\n", 17361863);
// 	ft_printf("integer: %i\n", 912723317);
// 	ft_printf("unsigned integer: %u\n", 3147483648);
// 	ft_printf("lower_case hex: %x\n", 3147483648);
// 	ft_printf("upper_case hex: %X\n", 3147483648);
// 	ft_printf("upper_case hex: %X\n", 3147483648);
// 	ft_printf("percentage: %%%%%%%%\n");
// 	// const char * null;
// 	return (0);
// }