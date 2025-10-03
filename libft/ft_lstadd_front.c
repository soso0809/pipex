/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:11:51 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:01:16 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  add a new element at the beginning of a linked list.
* Function implemented: ft_lstadd_front
***	- lst: address of a pointer to the first element of the list.
***	- new: pointer to the element to add to the front of the list.
***	- If new is NULL, the function does nothing.
*/
/* ************************************************************************** */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}
