/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:09:42 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/13 17:17:13 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		is_whitespace(char c);
int		char_inbase(char *str, char *base);
int		char_value(char *str, char *base);
int		check_base(char *base);
char	*print_base_nb(int nbr, char *base, 
			unsigned int size, char *bf);

int	is_whitespace(char c)
{
	if ((c == 32 || (c >= 9 && c <= 13)))
		return (1);
	else
		return (0);
}

int	char_inbase(char *str, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (*str == base[i])
			return (1);
	}
	return (0);
}

int	char_value(char *str, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (*str == base[i])
			return (i);
	}
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-' || is_whitespace(base[i]) == 1)
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value_from;
	char	*result;
	int		len_base_from;
	int		len_base_to;

	len_base_from = check_base(base_from);
	len_base_to = check_base(base_to);
	if (len_base_from == 0 || len_base_to == 0)
		return (NULL);
	result = malloc(sizeof(char) * 1);
	result[0] = '\0';
	value_from = ft_atoi_base(nbr, base_from);
	result = print_base_nb(value_from, base_to, len_base_to, result);
	return (result);
}
