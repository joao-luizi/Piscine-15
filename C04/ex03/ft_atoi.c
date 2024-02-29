/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:58:39 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/06 16:33:24 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_whitespace(char *str)
{
	if ((*str == 32 || (*str >= 9 && *str <= 13)))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (is_whitespace(str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char	*number;

	number = "	---+--+1234ab567";
	printf("%d\n", ft_atoi(number));
}*/
