/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:25:24 by sgrootve          #+#    #+#             */
/*   Updated: 2023/11/29 13:18:01 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static char	signal_char = 0;
	static int	signal_bit = 0;

	signal_char |= (signal == SIGUSR2);
	signal_bit++;
	if (signal_bit == 8)
	{
		if (signal_char == '\0')
			kill(info->si_pid, SIGUSR2);
		else
			ft_printf("%c", signal_char);
		signal_char = 0;
		signal_bit = 0;
	}
	else
		signal_char <<= 1;
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server pid: %i\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Failed to create action\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Failed to create action\n"), 1);
	while (1)
		pause();
	return (0);
}
