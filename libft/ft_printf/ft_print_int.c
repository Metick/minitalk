/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:59:21 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/24 17:06:12 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_int(int n, const char *base)
{
	int		len;
	char	*str;

	str = ft_itoa_base(n, base);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free((void *)str);
	return (len);
}
