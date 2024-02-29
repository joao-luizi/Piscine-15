/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:14:55 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/14 21:33:05 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = (max - min);
	arr = malloc(size * sizeof(int));
	if (arr == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
int	main(void)
{
	int	*array;

	array = ft_range(1, 5);

	free(array);
}*/
