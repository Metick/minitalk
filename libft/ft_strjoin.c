/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:52:53 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:56:50 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	str = (char *)ft_calloc(((s1_length + s2_length) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, s1_length + 1);
	ft_strlcat(str, s2, s2_length + s1_length + 1);
	return (str);
}
