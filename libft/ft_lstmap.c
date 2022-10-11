/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:51:31 by marvin            #+#    #+#             */
/*   Updated: 2022/03/02 16:51:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*l;

	l = NULL;
	while (lst)
	{
		nl = ft_lstnew(f(lst -> content));
		if (!nl)
		{
			ft_lstclear(&l, (void (*)(void *))del);
			return (0);
		}
		ft_lstadd_back(&l, nl);
		lst = lst -> next;
	}
	return (l);
}
