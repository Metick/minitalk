/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:25:59 by sgrootve          #+#    #+#             */
/*   Updated: 2023/11/29 13:17:07 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

volatile int	g_received_request = 0;

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received_request = 1;
	if (signal == SIGUSR2)
		ft_printf("Finished sending message.\n");
}

int	check_main(int argc, char *pid)
{
	int	index;

	if (argc != 3)
		return (0);
	index = 0;
	while (pid[index])
	{
		if (!ft_strchr("0123456789", pid[index]))
			return (0);
		index++;
	}
	return (1);
}

int	signal_send(char c, int pid)
{
	int	bit;
	int	index;

	index = 8;
	while (index > 0)
	{
		bit = (c >> (index - 1)) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) != 0)
				return (0);
		}
		else if (bit == 1)
		{
			if (kill(pid, SIGUSR2) != 0)
				return (0);
		}
		while (g_received_request == 0)
			usleep(1);
		g_received_request = 0;
		index--;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		index;

	if (!check_main(argc, argv[1]))
		return (ft_printf("Invalid Arguments: %s <pid> <message>\n",
				argv[0]), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID"), 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	index = 0;
	message = argv[2];
	while (message[index] != '\0')
	{
		if (!signal_send(message[index], pid))
			return (ft_printf("Failed to send signal\n"), 1);
		index++;
	}
	if (!signal_send('\0', pid))
		return (ft_printf("Failed to send signal\n"), 1);
	return (0);
}
