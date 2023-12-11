/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:04:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 01:04:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_string_size(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
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

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = get_string_size(n);
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--size] = (my_abs(n % 10) + '0');
		n /= 10;
	}
	return (str);
}

// #include <limits.h>
// int main()
// {
//     char * s = ft_itoa(-INT_MAX);
//     printf("%s -> %i\n", s, !strcmp(s, "-2147483647"));
//     void * p2 = malloc(strlen("-2147483647") + 1); 
//     printf("%i -> %i", malloc_usable_size(s), malloc_usable_size(p2));
//     return (0);
// }