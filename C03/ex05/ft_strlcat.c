/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:51:35 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/04 17:52:46 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;
	unsigned int	destlen;
	int				j;

	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size == 0)
		return (srclen);
	if (size < destlen)
		return (size + srclen);
	j = 0;
	while (src[j] != '\0' && (destlen + j < size - 1))
	{
		dest[destlen + j] = src[j];
		j++;
	}
	dest[destlen + j] = '\0';
	return (destlen + srclen);
}
/*
int	main(void)
{
	int		result;
	char	dest[8] = "Test";
	char	src[] = "12345";

	result = 0;
	// char dest[10] = "Hello";
	// char src[] = " World";
	// result = ft_strlcat(dest, src, sizeof(dest));
	result = ft_strlcat(dest, src, sizeof(dest));
	printf("Result: %d\n", result);
	printf("Destination: %s\n", dest);
	printf("Source: %s\n", src);
	return (0);
}*/
