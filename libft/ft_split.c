/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:10:03 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 15:19:04 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	index;
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
			flag++;
		if (s[index] != c && flag == 1)
			count++;
		if (s[index] == c)
			flag = 0;
		index++;
	}
	return (count);
}

static	int	c_delim(char const *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != c && s[index] != '\0')
		index++;
	return (index);
}

static int	check_free_array(char **arr, char *ptr)
{
	int	index;

	if (!ptr)
	{
		index = 0;
		while (arr[index] != NULL)
		{
			free(arr[index]);
			index++;
		}
		free(arr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	int		index;
	int		word_count;

	pointer = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!pointer)
		return (NULL);
	index = 0;
	word_count = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			pointer[word_count] = ft_substr(s, index, c_delim(&s[index], c));
			if (!check_free_array(pointer, pointer[word_count]))
				return (NULL);
			index += c_delim(&s[index], c);
			word_count++;
		}
		else
			index++;
	}
	return (pointer);
}
