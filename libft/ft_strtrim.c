/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:57:09 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 15:09:25 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_trim(char const *s1, char const *set, size_t i)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (s1[i] == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	str_length;

	str_length = ft_strlen(s1);
	begin = 0;
	while (find_trim(s1, set, begin) && begin < str_length)
		begin++;
	end = str_length;
	while (find_trim(s1, set, end - 1) && end > begin)
		end--;
	return (ft_substr(s1, begin, end - begin));
}

//  #include <stdio.h>
//  int main(void) 
//  {

//  	printf("|%s|\n", ft_strtrim("   xxxtripouille   xxx", " x"));
// 	printf("|%s|\n", ft_strtrim("   xxx   xxx", " x"));
// 	printf("|%s|\n", ft_strtrim("tripouille   xxx", " x"));
// 	printf("|%s|\n", ft_strtrim("   xxxtripouille", " x"));
//  	return (0);
//  }
