/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:17:46 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/14 13:58:02 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	size = (max - min);
	arr = (int *)malloc((size + 1) * sizeof(int));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}
/*
int	main(void)
{
	int	*array;
	int	size;

	size = ft_ultimate_range(&array, 1, 5);
	int i = 0;
	while (array[i] != '\0')
	{
		printf("%d\n", array[i]);
		i++;
	}
	free(array);
}*/
