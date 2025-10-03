/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:32:52 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:58:31 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: concatenate src to dest, ensuring the total length does not exceed 
	dstsize.
* Function implemented: ft_strlcat
***	- dest: destination string buffer.
***	- src: source string to append.
***	- dstsize: total size of destination buffer.
***	- Return the total length of the string it tried to create (initial length 
	of dest + length of src).
* Notes:
***	- Ensure null-termination if dstsize > 0.
***	- If dstsize <= initial length of dest, returns dstsize + length of src.
*/
/* ************************************************************************** */
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dest_len + i) < dstsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main(void)
{
	char dest[20] = "Hello";
	const char *src;
	size_t result;

	src = " the world";
	result = ft_strlcat(dest, src, sizeof(dest));
	printf("The result is: %s\n", dest);
	printf("Return value: %zu\n", result);
	return (0);
}*/
