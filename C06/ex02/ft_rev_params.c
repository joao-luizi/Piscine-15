/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:19:53 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/06 14:20:24 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;
	int	arg_len;

	i = argc - 1;
	while (i > 0)
	{
		arg_len = 0;
		while (argv[i][arg_len])
			arg_len++;
		write(1, argv[i], arg_len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
