/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:41:55 by marvin            #+#    #+#             */
/*   Updated: 2022/02/14 18:41:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

		// char    *sone;
		// char    *stwo;

		// sone = (char *)s1;
		// stwo = (char *)s2;
		// if (n == 0)
		// 	return (0);
		// while ((*sone != '\0') && (*stwo != '\0') && (n > 0))
		// {	
		// 	if (*sone != *stwo)
		// 		break ;
		// 	sone++;
		// 	stwo++;
		// 	n--;
		// }
		// return (*(unsigned char *)sone - *(unsigned char *)stwo);
