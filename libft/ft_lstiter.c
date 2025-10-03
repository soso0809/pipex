/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:50:47 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:04:16 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  apply a function to each element of a linked list.
* Function implemented: ft_lstiter
***	- lst: pointer to the first node of the list.
***	- f: function pointer to apply to the content of each node.
***	- Applie f to each node's content in the list.
*/
/* ************************************************************************** */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
