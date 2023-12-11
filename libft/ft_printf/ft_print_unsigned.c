/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:00:52 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/24 17:04:50 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_uint(long long n, const char *base)
{
	int		len;
	char	*str;

	str = ft_litoa_base(n, base);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free((void *)str);
	return (len);
}
