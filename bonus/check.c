/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:34:41 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:37 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_if_no_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 2147483647
			&& ft_strncmp(argv[i], "2147483647", 10))
			return (0);
		if (ft_atoi(argv[i]) == -2147483648
			&& ft_strncmp(argv[i], "-2147483648", 11))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_digit(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	return (check_if_digit(argc, argv) && check_if_int(argc, argv)
		&& check_if_no_duplicates(argc, argv));
}
