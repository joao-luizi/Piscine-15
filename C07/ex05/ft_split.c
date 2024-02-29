/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:37:11 by joaomigu          #+#    #+#             */
/*   Updated: 2024/02/15 16:34:46 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_sep(char *str, char *charset)
{
	int	str_len;

	str_len = 0;
	while (str[str_len] != '\0' && is_charset(str[str_len], charset) == 0)
		str_len++;
	return (str_len);
}

int	count_substrings(char *str, char *charset)
{
	int	substring_count;
	int	i;
	int	flag;

	flag = 0;
	substring_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset) == 1)
		{
			if (flag == 0)
			{
				flag = 1;
				substring_count++;
			}
		}
		else
			flag = 0;
		i++;
	}
	return (substring_count);
}

char	*copy_str(char *str, char *charset)
{
	int		i;
	char	*result;
	int		str_len;

	i = 0;
	str_len = ft_strlen_sep(str, charset);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	while (str[i] && (is_charset(str[i], charset) == 0))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		num_substrings;
	int		j;

	j = 0;
	num_substrings = 0;
	result = (char **)malloc(sizeof(char *) * (num_substrings + 1));
	if (result == NULL)
		return (NULL);
	while (*str && j < num_substrings)
	{
		while (*str && (is_charset(*str, charset) == 1))
			str++;
		if (*str != '\0')
		{
			result[j] = copy_str(str, charset);
			j++;
		}
		while (*str && (is_charset(*str, charset) == 0))
			str++;
	}
	result[j] = 0;
	return (result);
}
/*
int	main(void)
{
	//char	str[] = ",Hello,World!!This:,:Is,A:Test,";
	char	str[] = "est,";
	char	charset[] = ",";
	char	**result;
	int		i;

	result = ft_split(str, charset);
	i = 0;
	if (result != NULL)
	{
		while (result[i] != NULL)
		{
			printf("Substring %d: %s\n", i + 1, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	else
	{
		printf("Error: Memory allocation failed or no substrings found.\n");
	}
	return (0);
}*/
