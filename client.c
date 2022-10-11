/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:59:11 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/04 20:18:47 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

t_mt	*c_init(void)
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

void	c_send(t_mt *mt, char *str)
{
	int		i;
	int		bit;
	int		signal;

	i = 0;
	while (i <= ft_strleng(str))
	{
		bit = 0;
		signal = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit++) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(mt->pid_server, signal);
			usleep(100);
		}
		i++;
	}
	return ;
}

void	error_handle(int e)
{
	if (e == 0)
		ft_putstr("ERROR! Use ./client with 3 args.\n");
	if (e == 1)
		ft_putstr("ERROR! PID must be > 0.\n");
	exit(EXIT_FAILURE);
}

void	c_receive(int b)
{
	(void)b;
}

int	main(int argc, char **argv)
{
	t_mt				*mt;

	signal(SIGUSR1, c_receive);
	signal(SIGUSR2, c_receive);
	mt = NULL;
	if (argc != 3)
		error_handle(0);
	else
	{
		mt = c_init();
		mt->pid_server = ft_atoi2(argv[1]);
		if (mt->pid_server <= 0)
		{
			free(mt);
			mt = NULL;
			error_handle(1);
		}
		c_send(mt, argv[2]);
	}
	free(mt);
	mt = NULL;
	return (0);
}
