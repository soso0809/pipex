/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:51:20 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:51:50 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  display a message to stderr and exit the program with a given
	status.
* Function implemented: ft_error
***	- msg: the message to display. If NULL, a default message is shown.
***	- status: the exit status code.
***	- print "Error: " followed by the provided message or "Unknown error."
*   - Exit the program with the given status.
*/
/* ************************************************************************** */
void	ft_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd("Unknown error.", 2);
	exit(1);
}
