/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:15:19 by joaomigu          #+#    #+#             */
/*   Updated: 2024/01/28 14:20:27 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tempdiv;
	int	tempremainder;

	tempdiv = *a / *b;
	tempremainder = *a % *b;
	*a = tempdiv;
	*b = tempremainder;
}
