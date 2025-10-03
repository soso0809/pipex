/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:26:59 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:56:09 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  allocate memory for an array and initialize it to zero 
	(mimics the behavior of calloc).
* Function implemented: ft_calloc
***	- count: number of elements to allocate.
***	- size: size of each element.
***	- Check for overflow in multiplication.
***	- Allocate memory for count * size bytes.
***	- Initialize all allocated bytes to zero.
***	- Return a pointer to the allocated memory, or NULL on failure.
*/
/* ************************************************************************** */
void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	i = 0;
	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

/*int main()
{
	int *tab;
	size_t count = 5;
	size_t i = 0;
	// Allocate memory for an array of 5 ints, all initialized to zero
	tab = (int *)ft_calloc(count, sizeof(int));
	if (!tab)
	{
		printf("Memory allocation error\n");
		return 1;
	}
	printf("Contents of the array after calloc:\n");
	// Print each element of the array using a while loop
	while (i < count)
	{
		printf("tab[%zu] = %d\n", i, tab[i]);
		i++;
	}
	// Free the allocated memory
	free(tab);
	return 0;
}*/
