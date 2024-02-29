/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:59:20 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/04 18:42:57 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	number(int nb)
{
	if (nb >= 10)
	{
		number(nb / 10);
	}
	ft_putchar('0' + (nb % 10));
}

void	ft_putnbr(int nb)
{
	unsigned int safe_nb;

	safe_nb = 0;
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			safe_nb = -nb;
		}
		else
		{
			safe_nb = nb;
		}
		number(safe_nb);
	}
}
/*
int	main(void)
{
	ft_putnbr(-2147483);
	return (0);
}*/
