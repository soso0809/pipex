/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:08:42 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:53:43 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  convert a string to an integer (mimics the behavior of atoi).
* Function implemented: ft_atoi
***	- str: the string to convert.
***	- Skip leading whitespace.
***	- Handle optional '+' or '-' sign.
***	- Convert consecutive digits to an integer.
***	- Return the resulting integer value.
*/
/* ************************************************************************** */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*int	main()
{
	char *test1 = "123";
	char *test2 = "-42";
	char *test3 = " +123";
	char *test4 = "abc";
	char *test5 = "abc";
	char *test6 = "abc";
	char *test7 = "abc";


	printf("Test1 atoi : %d\n", atoi(test1));
	printf("Test1 ft_atoi : %d\n", ft_atoi(test1));
	printf("\n");
	printf("Test2 atoi : %d\n", atoi(test2));
	printf("Test2 ft_atoi : %d\n", ft_atoi(test2));
	printf("\n");
	printf("Test3 atoi : %d\n", atoi(test3));
	printf("Test3 ft_atoi : %d\n", ft_atoi(test3));
	printf("\n");
	printf("Test4 atoi : %d\n", atoi(test4));
	printf("Test4 ft_atoi : %d\n", ft_atoi(test4));
	printf("\n");
	printf("Test5 atoi : %d\n", atoi(test5));
	printf("Test5 ft_atoi : %d\n", ft_atoi(test5));
	printf("\n");
	printf("Test6 atoi : %d\n", atoi(test6));
	printf("Test6 ft_atoi : %d\n", ft_atoi(test6));
	printf("\n");
	printf("Test7 atoi : %d\n", atoi(test7));
	printf("Test7 ft_atoi : %d\n", ft_atoi(test7));
return(0);
}*/
