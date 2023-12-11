/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:46:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/29 21:46:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_pointer(void *ptr)
{
	char	*str;
	int		len;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	str = ft_ulitoa_base((unsigned long)ptr, "0123456789abcdef");
	if (!str)
		return (0);
	len += write(1, str, ft_strlen(str));
	free((void *)str);
	return (len);
}
