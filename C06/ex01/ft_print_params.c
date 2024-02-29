/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:18:18 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/06 14:19:19 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;
	int	arg_len;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			arg_len = 0;
			while (argv[i][arg_len])
				arg_len++;
			write(1, argv[i], arg_len);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
