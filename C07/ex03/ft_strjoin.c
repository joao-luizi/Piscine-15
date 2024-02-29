/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:28:06 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/13 17:08:14 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	copy_strs(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i++ < size)
	{
		j = 0;
		while (strs[i - 1][j++] != '\0')
		{
			result[index] = strs[i - 1][j - 1];
			index++;
		}
		j = 0;
		if ((i - 1) < size - 1)
		{
			while (sep[j++] != '\0')
			{
				result[index] = sep[j - 1];
				index++;
			}
		}
	}
	result[index] = '\0';
}

int	calc_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;
	int	j;

	total_len = 0;
	sep_len = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_len++;
			j++;
		}
		i++;
	}
	sep_len = 0;
	i = 0;
	while (sep[i++] != '\0')
		sep_len++;
	total_len += ((size - 1) * sep_len);
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result == 0)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	total_len = calc_len(size, strs, sep);
	result = malloc((total_len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	copy_strs(size, strs, sep, result);
	return (result);
}
/*
int	main(void)
{
	char	*strs[] = {"this", "is", "a", "test", "/", "nothing"};
	int		size;
	char	*sep;
	char	*result;

	size = 6;
	sep = "/separador/";
	result = ft_strjoin(size, strs, sep);
	if (result == NULL)
	{
		printf("Erro malloc\n");
		return (1);
	}
	printf("End string: %s\n", result);
	free(result);
	return (0);
}*/
