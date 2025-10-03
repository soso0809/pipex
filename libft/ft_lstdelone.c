/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:18:06 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:56:41 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  delete and free the given node of a linked list.
* Function implemented: ft_lstdelone
***	- lst: the node to delete.
***	- del: pointer to a function used to delete the content of the node.
***	- Free the memory of the node and its content using the provided function.
*/
/* ************************************************************************** */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* ************************************************************************** */
/*
* Purpose:  test the ft_lstdelone function with a simple string.
* Function implemented: main
***   - None (test function).
*/
/* ************************************************************************** */
void	free_content(void *content)
{
	free(content);
}

/*int	main(void)
{
	char *str = malloc(20);

	if (!str)
		return (1);
	strcpy(str, "Bonjour");
	t_list *node = ft_lstnew(str);
	ft_lstdelone(node, free_content);
	return (0);
}
*/
