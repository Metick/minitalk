/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:29:04 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:35:08 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index2;

	if (*little == '\0')
		return ((char *)big);
	index = 0;
	while (index < len && big[index] != '\0')
	{
		index2 = 0;
		while (index + index2 < len && big[index + index2] == little[index2])
		{
			if (little[index2 + 1] == '\0')
				return ((char *)&big[index]);
			index2++;
		}
		index++;
	}
	return (NULL);
}
