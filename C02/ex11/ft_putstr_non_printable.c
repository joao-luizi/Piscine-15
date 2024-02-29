/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:10:44 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/04 14:15:40 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c / 16 > 0)
	{
		ft_putchar(hex[c / 16]);
		ft_putchar(hex[c % 16]);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(hex[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_convert_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
/*
int	main(void)
{
	char	test2[] = {65, 66, 62, 200, 60, 65, 66, '\0'};

	// char	test[] = "Coucou\ntu vas bien ?";
	// ft_putstr_non_printable(test);
	ft_putchar('\n');
	ft_putstr_non_printable(test2);
	return (0);
}*/
