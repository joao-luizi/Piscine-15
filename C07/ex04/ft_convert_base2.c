/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:17:38 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/14 23:03:35 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*inccap(char *oldarray, int newcap, char newel);
int		is_whitespace(char c);
int		char_inbase(char *str, char *base);
int		check_base(char *base);
int		char_value(char *str, char *base);
char	*ft_strcpy(char *dest, char *src, char new_element);
char	*print_base_nb(int nbr, char *base, unsigned int size, char *bf);

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
		result = (result * len_base) + char_value(str, base);
		str++;
	}
	return (result * sign);
}

char	*inccap(char *oldarray, int newcap, char newel)
{
	char	*newarray;

	newarray = malloc(newcap * sizeof(char *));
	if (newarray == NULL)
	{
		return (NULL);
	}
	ft_strcpy(newarray, oldarray, newel);
	free(oldarray);
	return (newarray);
}

char	*ft_strcpy(char *dest, char *src, char new_element)
{
	int	i;

	i = 0;
	dest[0] = new_element;
	while (src[i] != '\0')
	{
		dest[i + 1] = src[i];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);
}

unsigned int	safe_number(int *sign, int nbr)
{
	if (nbr < 0)
	{
		*sign = -1;
		return (nbr * (-1));
	}
	else
		return ((unsigned int)nbr);
}

char	*print_base_nb(int nbr, char *base, unsigned int size, char *bf)
{
	unsigned int	n;
	int				sign;
	int				bf_len;

	bf_len = 1;
	sign = 1;
	n = safe_number(&sign, nbr);
	if (n == 0)
		bf = inccap(bf, bf_len++, base[n % size]);
	else
	{
		while (n > 0)
		{
			bf = inccap(bf, bf_len++, base[n % size]);
			n = n / size;
		}
	}
	if (sign < 0)
		bf = inccap(bf, bf_len++, '-');
	return (bf);
}
