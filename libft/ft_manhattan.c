/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manhattan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:16:47 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:10:41 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  Calculate the Manhattan distance between two points.
* Function implemented: ft_manhattan
***	- ax, ay: coordinates of the first point.
***	- bx, by: coordinates of the second point.
***	- Return the Manhattan distance (|ax - bx| + |ay - by|).
*/
/* ************************************************************************** */
int	ft_manhattan(int ax, int ay, int bx, int by)
{
	return (abs(ax - bx) + abs(ay - by));
}
