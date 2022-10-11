/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:57:52 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 17:57:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*r;

	if (size > 0)
	{
		r = malloc(nmemb * size);
		if (!r)
			return (0);
		ft_memset(r, 0, nmemb * size);
	}
	else
	{
		r = malloc(0);
		if (!r)
			return (0);
	}
	return ((void *)r);
}
