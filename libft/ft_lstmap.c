/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:59 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:07:37 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  create a new list by applying a function to each element of an 
	existing list.
* Function implemented: ft_lstmap
***	- lst: pointer to the first node of the list to map.
***	- f: function pointer to apply to each node's content.
***	- del: function pointer to delete the content of a node if needed.
***	- Return a new list resulting from the successive applications of f.
*/
/* ************************************************************************** */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*new_content;
	t_list	*new_node;

	result = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		lst = lst -> next;
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
	}
	return (result);
}
