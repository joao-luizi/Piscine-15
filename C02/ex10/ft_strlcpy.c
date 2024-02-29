/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:58 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/04 14:14:46 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_length;

	i = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size < 1)
		return (src_length);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}
/*
int	main(void)
{
	char	src[] = "abcdef";
	char	dest[10];
	int		result;

	result = ft_strlcpy(dest, src, 20);
	printf("%d\n", result);
	printf("%d\n", dest[result]);
	printf("%d\n", dest[result] == 'f');
	// dest[result] tem de ser \0 e dest[result
	//- 1] tem de ser a ultima letra de src
	return (0);
}*/
