/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:56:28 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:01:42 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//If dest == src -> return dest
//if dest < src append src to dst from index 0
//if dest > src append src to dst from last index till size

// dest:      |-------------|
// src:             |------------|

// dest:             |-------------|
// src:       |------------|

void	ft_move(char *d, char *s, size_t n)
{
	int		index;

	index = 0;
	if (s < d && (s + n) >= d)
	{
		index = (int)(n - 1);
		while (index >= 0)
		{
			d[index] = s[index];
			index--;
		}
	}
	else
	{
		index = 0;
		while (index < (int)n)
		{
			d[index] = s[index];
			index++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	s = (char *)src;
	d = dest;
	if (!d || !s)
		return (NULL);
	if (d == s)
		return (d);
	ft_move(d, s, n);
	return (d);
}
