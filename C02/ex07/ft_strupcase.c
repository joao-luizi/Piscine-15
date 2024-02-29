/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:54:14 by joaomigu          #+#    #+#             */
/*   Updated: 2024/01/28 17:02:51 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	char_is_alpha_lower(char c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (c < 'a' || c > 'z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str != '\0')
	{
		if (char_is_alpha_lower(*str) == 1)
		{
			*str = *str - 32;
		}
		str++;
	}
	return (start);
}

/*int	main(void)
{
	char	src[] = "H3llo World";

	printf("%s", ft_strupcase(src));
	return (0);
}*/
