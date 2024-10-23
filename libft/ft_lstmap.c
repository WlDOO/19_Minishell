/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:13:50 by najeuneh          #+#    #+#             */
/*   Updated: 2024/05/28 17:25:14 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst)
		return (NULL);
	node = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new, *del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
/*
void	tab_free(void * c)
{
	free(c);
}

void	*ft_lol(void *c)
{
	c = "heeeaeansds";
	return (c);
}


int	main()
{
	t_list	*node;
	t_list	*node1;
	
	node = ft_lstnew("hello!");
	node1 = ft_lstnew(NULL);
	ft_lstadd_back(&node, node1);
	ft_lstmap(node, ft_lol, tab_free);
}
*/