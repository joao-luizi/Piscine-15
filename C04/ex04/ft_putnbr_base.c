/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:40:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:23 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
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

void	print_base_nb(int nbr, char *base, unsigned int size)
{
	char			a;
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= size)
		print_base_nb(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = check_base(base);
	if (size != 0)
	{
		print_base_nb(nbr, base, size);
	}
}
/*
int	main(void)
{
	char	*base;
	int		nb;

	base = "0123456789";
	nb = -234;
	ft_putnbr_base(nb, base);
}*/
