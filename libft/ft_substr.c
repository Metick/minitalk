/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:44:35 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:57:51 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	length_s;

	length_s = ft_strlen(s);
	if (length_s < (size_t)start)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > length_s)
		len = length_s - start;
	substr = (char *)ft_calloc(len + 1, (sizeof(char)));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
