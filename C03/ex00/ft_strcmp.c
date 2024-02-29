/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:18:44 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/04 16:19:22 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "hello";
	int		result;

	result = ft_strcmp(str1, str2);
	if (result == 0)
	{
		printf("Iguais.\n");
	}
	else if (result < 0)
	{
		printf("str1 menor que str2.\n");
	}
	else
	{
		printf("str1 maior que str2.\n");
	}
	return (0);
}
*/
