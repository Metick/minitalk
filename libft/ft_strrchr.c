/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:50:12 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:57:54 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	s_length;

	index = 0;
	s_length = ft_strlen(s);
	while (index <= s_length)
	{
		if (s[s_length - index] == (unsigned char)c)
			return ((char *)&s[s_length - index]);
		index++;
	}
	return (NULL);
}
