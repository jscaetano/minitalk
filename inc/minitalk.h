/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:39:38 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/04 20:00:52 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <zconf.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_mt
{
	int	pid_server;
	int	pid_client;
}	t_mt;

t_mt	*c_init(void);
void	c_send(t_mt *mt, char *str);
// void	c_receive(int b, siginfo_t *info, void *context);
void	c_receive(int b);
t_mt	*sv_init(void);
void	sv_receive(int b, siginfo_t *info, void *context);
int		ft_strleng(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi2(const char *nptr);
int		ft_iterative_power(int nb, int power);

#endif
