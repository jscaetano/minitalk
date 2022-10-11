/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:23:16 by joacaeta          #+#    #+#             */
/*   Updated: 2022/09/17 21:38:02 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*dest;
// 	int		srcsize;
// 	char	*str;

// 	str = (char *)s1;
// 	srcsize = 0;
// 	while (s1[srcsize] != '\0')
// 		srcsize++;
// 	dest = malloc((srcsize + 1));
// 	ft_strcpy(dest, str);
// 	return (dest);
// }

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	str1 = malloc(i + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

// int	main(void)
// {
// 	char *str = "Hello dude";
// 	char *strc;

// 	strc = ft_strdup(str);
// 	printf("%s", strc);
// }
