/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:42 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 12:04:08 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_errors(int ac, char **av)
{
	if (ac < 5)
	{
		printf("Program requires 4 arguments\n");
		return (EXIT_FAILURE);
	}
	if (ac > 6)
	{
		printf("Maximum 5 arguments allowed\n");
		return (EXIT_FAILURE);
	}
	if (check_number_of_philos(av) || check_positive_and_digits(ac, av))
		return (EXIT_FAILURE);
	return (0);
}

int	check_number_of_philos(char **av)
{
	int	i;

	i = 0;
	if (((av[1][0] == '0')) && ft_strlen(av[1]) == 1)
	{
		printf("At least 1 philosophers required\n");
		return (EXIT_FAILURE);
	}
	return (0);
}

int	check_positive_and_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '-')
			{
				printf("Only positive numbers allowed\n");
				return (EXIT_FAILURE);
			}
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Only digits allowed\n");
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (0);
}
