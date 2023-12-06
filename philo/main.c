/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:45 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/12 16:11:14 by eleleux          ###   ########.fr       */
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
	if (data->victory_meal == 0)
		return (printf(GRN "SUCCESS\n" WHT));
	if (start_and_join_threads(data))
		return (EXIT_FAILURE);
	deathwatcher_job(data);
	free_data(data);
	return (0);
}
