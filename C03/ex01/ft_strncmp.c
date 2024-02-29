/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:47 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/05 13:27:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (((unsigned char)(*s1) - (unsigned char)(*s2)));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	int		test;
	int		result;

	str1 = "Hello";
	str2 = "Hella";
	test = 4;
	result = ft_strncmp(str1, str2, test);
	if (result == 0)
	{
		printf("The first %d characters of the strings are equal.\n", test);
	}
	else if (result < 0)
	{
		printf("The first\
				%d characters of str1 are lexicographically less than str2.\n ",
				test);
	}
	else
	{
		printf("The first\
				%d characters of str1 are lexicographically greater than str2.\n ",
				test);
	}
	return (0);
}*/
