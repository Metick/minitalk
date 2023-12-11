/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:53:18 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:01:30 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if ((src < dest && (src + n) > dest) || (dest < src && dest + n > src)
		|| dest == src)
		return (ft_memmove(dest, src, n));
	else
	{
		while (index < n)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dest);
}

// void main(void)
// {
// 	char str[] = "This is abig str that were gonna test";
// 	char *dst = ft_strchr(str, 'a');

// 	printf("%s -> %s [0x%p -> 0x%p]\n", str, dst, str, dst);
// 	printf("%s\n", (char*)ft_memcpy(dst, str, 10));

// 	return (0);
// }