/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:43:04 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/06 16:03:25 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_whitespace(char c)
{
	if ((c == 32 || (c >= 9 && c <= 13)))
		return (1);
	else
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

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	len_base;

	result = 0;
	sign = 1;
	len_base = check_base(base);
	if (len_base == 0)
		return (0);
	while (is_whitespace(*str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (char_inbase(str, base) == 1)
	{
		result = result * len_base + char_value(str, base);
		str++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	*base;
	char	*source;

	base = "poneyvif";
	source = "---pfi";
	printf("Result: %d\n", ft_atoi_base(source, base));
}*/
