/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:32:43 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/06 11:46:42 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		length;

	length = ft_strlen(s);
	ptr = (char *)ft_calloc(length + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, length);
	return (ptr);
}
