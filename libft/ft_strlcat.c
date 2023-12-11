/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:27:59 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:01:58 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_length;
	size_t	len;

	dst_length = ft_strlen(dst);
	if (size <= 0 || dst_length >= size)
		len = (ft_strlen(src) + size);
	else
		len = (ft_strlen(src) + dst_length);
	index = 0;
	while (src[index] != '\0' && (index + dst_length + 1) < size)
	{
		dst[dst_length + index] = src[index];
		index++;
	}
	if (size > 0 && size > dst_length)
		dst[index + dst_length] = '\0';
	return (len);
}
