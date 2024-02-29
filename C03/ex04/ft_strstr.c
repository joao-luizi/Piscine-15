/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:27:57 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/05 13:28:52 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Hello, World";
	char	to_find[] = "Worl";
	char	*result;

	result = ft_strstr(str, to_find);
	if (result != NULL)
	{
		printf("Substring found at index: %ld\n", result - str);
	}
	else
	{
		printf("Substring not found\n");
	}
	return (0);
}*/
