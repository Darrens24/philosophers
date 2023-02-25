/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:00 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 15:49:43 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(ac, av))
		return (EXIT_FAILURE);
	data = malloc(sizeof(*data));
	if (!data)
		return (EXIT_FAILURE);
	get_data(data, av);
	sem_wait(data->sema_death);
	if (start_processes(data))
		return (EXIT_FAILURE);
	sem_wait(data->sema_death);
	kill_processes_free_data(data);
	return (EXIT_SUCCESS);
}
