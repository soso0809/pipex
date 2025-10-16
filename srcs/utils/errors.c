/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:55:59 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 10:21:50 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* ************************************************************************** */
/*
* Purpose: main functions for parsing
* Function implemented:
***	- exit_error: print error message and exit program.
***	- exit_error_cmd: print error message for a specific command and exit 
	program.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: print error message and exit program.
* Function implemented: exit_error
***	- Print the provided error message to stderr.
***	- Exit the program with status 1.
*/
/* ************************************************************************** */
void	exit_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

/* ************************************************************************** */
/*
* Purpose: print error message for a specific command and exit program.
* Function implemented: exit_error_cmd
***	- Print "Error: <cmd>: <msg>" to stderr.
***	- Exit the program with status 1.
*/
/* ************************************************************************** */
void	exit_error_cmd(char *cmd, char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
