/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:00:17 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:00:47 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  add a new element at the end of a linked list.
* Function implemented: ft_lstadd_back
***	- lst: address of a pointer to the first element of the list.
***	- new: pointer to the new element to be added.
***	- If the list is empty, the new element becomes the first element.
***	- Otherwise, the new element is added at the end of the list.
*/
/* ************************************************************************** */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}
