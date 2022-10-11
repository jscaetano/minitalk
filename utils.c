/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:21:26 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/04 19:01:14 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

int	ft_strleng(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (str)
	{
		while (str[idx])
		{
			write(1, &str[idx], 1);
			idx++;
		}
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			ft_putnbr(nbr);
		}
		else if (nbr < 10)
		{
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(nbr / 10);
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
	}
}

int	ft_atoi2(const char *nptr)
{
	int	i;
	int	n;
	int	res;

	res = 0;
	i = 0;
	n = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + nptr[i] - 48;
		i++;
	}
	return (res * n);
}

int	ft_iterative_power(int nb, int power)
{
	int	r;

	r = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		r = r * nb;
		power--;
	}
	return (r);
}
