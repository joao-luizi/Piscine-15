/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:20:46 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/07 16:39:51 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	int	arg_len;

	arg_len = 0;
	while (str[arg_len])
		arg_len++;
	write(1, str, arg_len);
	write(1, "\n", 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*arg;
	int		j;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = i;
			while (ft_strcmp(argv[j], argv[j - 1]) < 0 && j > 1)
			{
				arg = argv[j - 1];
				argv[j - 1] = argv[j];
				argv[j] = arg;
				j--;
			}
			i++;
		}
		i = 1;
		while (i++ < argc)
			print(argv[i - 1]);
	}
	return (0);
}
