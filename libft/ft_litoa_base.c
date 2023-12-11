/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:06:06 by marvin            #+#    #+#             */
/*   Updated: 2023/10/29 22:06:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_string_size(long long int n, int base_size)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= base_size;
		length++;
	}
	return (length);
}

static	int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_litoa_base(long long int n, const char *base)
{
	char		*str;
	long long	size;
	int			base_size;

	base_size = ft_strlen(base);
	size = get_string_size(n, base_size);
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--size] = base[my_abs(n % base_size)];
		n /= base_size;
	}
	return (str);
}
