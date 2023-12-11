/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:35:26 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 14:43:02 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Isspace
static	int	is_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static const char	*trim_spaces(const char *nptr)
{
	while (is_isspace(*nptr))
		nptr++;
	return (nptr);
}

static int	is_negative(const char *nptr)
{
	if (nptr[0] == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			index;
	long long	total_size;
	int			negative;

	negative = 0;
	index = 0;
	total_size = 0;
	nptr = trim_spaces(nptr);
	negative = is_negative(nptr);
	if (nptr[0] == '-' || nptr[0] == '+')
		index++;
	while (nptr[index] != '\0')
	{
		if (ft_isdigit(nptr[index]))
			total_size = ((total_size * 10) + (nptr[index] - '0'));
		else
			break ;
		index++;
	}
	if (total_size > 2417483647)
		return (0);
	if (negative)
		total_size = -total_size;
	return (total_size);
}
