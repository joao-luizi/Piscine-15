/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:09:19 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/13 14:13:09 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*pointer_str_dup;
	int		src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	pointer_str_dup = malloc((src_len + 1) * sizeof(char));
	if (pointer_str_dup != NULL)
		ft_strlcpy(pointer_str_dup, src, src_len + 1);
	return (pointer_str_dup);
}
/*
int	main(void)
{
	char	source[] = "This is a test";
	char	*pointer_source = &source[0];
	char	*pointer_dest = ft_strdup(pointer_source);

	printf("Source: %s\n", source);
	printf("Mem Addresse: %p\n", pointer_source);
	printf("Target: %s\n", (char *)pointer_dest);
	printf("Mem Addresse: %p\n", pointer_dest);
	free(pointer_dest);
}*/
