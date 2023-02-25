/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:45 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:28:32 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(ac, av))
		return (EXIT_FAILURE);
	data = malloc(sizeof(*data));
	if (!data)
		return (EXIT_FAILURE);
	get_data(data, av);
	if (start_and_join_threads(data))
		return (EXIT_FAILURE);
	free_data(data);
	return (0);
}
