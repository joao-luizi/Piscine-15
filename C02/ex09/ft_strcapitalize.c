/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:58:51 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/03 15:11:42 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_numeric(char c)
{
	int	i;

	i = 0;
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int	is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
	{
		return (0);
	}
	return (1);
}

int	is_alpha(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (1);
}

int	checkflag(int flag, int i, char *str)
{
	if (flag == 0)
	{
		if (is_alpha(str[i]) || is_numeric(str[i]))
		{
			flag = 1;
			if (is_lowercase(str[i]))
				str[i] -= 32;
		}
	}
	else
	{
		if (is_alpha(str[i]) == 0 && is_numeric(str[i]) == 0)
			flag = 0;
		if (is_alpha(str[i]) == 1 && is_lowercase(str[i]) == 0)
			str[i] += 32;
	}
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		flag = checkflag(flag, i, str);
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	src[] = "*b_p-7#<vtr(>vt#6|9czrrlk-2jf9/;it-r`s$";

	printf("%s", ft_strcapitalize(src));
}*/
