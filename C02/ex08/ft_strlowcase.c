/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:55:55 by joaomigu          #+#    #+#             */
/*   Updated: 2024/01/28 17:03:09 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	char_is_alpha_upper(char c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (c < 'A' || c > 'Z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (char_is_alpha_upper(*str) == 1)
		{
			*str = *str + 32;
		}
		str++;
	}
	return (start);
}

/*int	main(void)
{
	char	src[] = "H3llo World";

	printf("%s", ft_strlowcase(src));
	return (0);
}*/
