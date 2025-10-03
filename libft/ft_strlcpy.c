/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:07:26 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:58:39 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: copy a string into a destination buffer with size limitation.
* Function implemented: ft_strlcpy
***	- dest: destination buffer.
***	- src: source string.
***	- dstsize: size of the destination buffer.
***	- Copie up to dstsize - 1 characters from src to dest, null-terminating the 
	result.
***	- Return the total length of src.
*/
/* ************************************************************************** */
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	int		length_src;

	length_src = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (length_src);
}

/*int	main(void)
{
	char dest[10];
	const char *src = "Hello World";
	size_t len;

	// Test 1: Normal copy
	len = ft_strlcpy(dest, src, 10);
	printf("Test 1 - Normal copy:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Length returned: %zu\n\n", len);

	// Test 2: Buffer too small
	char dest2[5];
	len = ft_strlcpy(dest2, src, 5);
	printf("Test 2 - Buffer too small:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest2);
	printf("Length returned: %zu\n\n", len);

	// Test 3: Empty string
	char dest3[10];
	len = ft_strlcpy(dest3, "", 10);
	printf("Test 3 - Empty string:\n");
	printf("Source: (empty)\n");
	printf("Destination: %s\n", dest3);
	printf("Length returned: %zu\n\n", len);

	// Test 4: dstsize = 0
	char dest4[10];
	len = ft_strlcpy(dest4, src, 0);
	printf("Test 4 - dstsize = 0:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest4);
	printf("Length returned: %zu\n", len);

	return (0);
}*/
