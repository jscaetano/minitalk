/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:08:48 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/04 20:20:17 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

t_mt	*sv_init(void)
{
	t_mt	*mt;

	mt = malloc(sizeof(t_mt));
	if (!mt)
	{
		ft_putstr("ERROR! malloc failed.\n");
		exit(EXIT_FAILURE);
	}
	mt->pid_client = 0;
	mt->pid_server = 0;
	return (mt);
}

void	reply(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	sv_receive(int b, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	cpid = 0;
	static int	letter = 0;

	(void)context;
	if ((info)->si_pid)
		cpid = info->si_pid;
	cpid++;
	cpid--;
	if (b == SIGUSR2)
		letter += ft_iterative_power(2, bit);
	bit++;
	if (bit == 8)
	{
		if (!letter)
		{
			write(1, "\n", 1);
			reply(cpid, SIGUSR1);
		}
		else
			write(1, &letter, 1);
		bit = 0;
		letter = 0;
	}
	return ;
}

void	sv_loop(t_mt *mt)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sv_receive;
	while (1)
	{
		if ((sigaction(SIGUSR1, &sa, NULL) == -1)
			|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		{
			ft_putstr("ERROR! Signal error.\n");
			free(mt);
			mt = NULL;
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_mt	*mt;

	(void)argv;
	mt = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR! Use ./server with only one arg.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		mt = sv_init();
		mt->pid_server = getpid();
		ft_putstr("SUCCESS! Server Ready. PID: ");
		ft_putnbr(mt->pid_server);
		write(1, "\n", 1);
		sv_loop(mt);
	}
	free(mt);
	mt = NULL;
	return (0);
}
