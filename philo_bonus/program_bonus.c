/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:04 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:34:31 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		data->philo_pid[i] = fork();
		if (data->philo_pid[i] < 0)
			return (printf("Fork failed\n"));
		else if (data->philo_pid[i] == 0)
		{
			philo_manager(data, i);
			exit(EXIT_SUCCESS);
		}
		i++;
		usleep(100);
	}
	return (0);
}

void	philo_manager(t_data *data, int index)
{
	pthread_t	deathwatch_t;

	data->index = index;
	if (pthread_create(&deathwatch_t, NULL, &deathwatcher_job, data) != 0)
	{
		printf("Thread deathwatch creation failed\n");
		exit(EXIT_FAILURE);
	}
	pthread_detach(deathwatch_t);
	odd_philo_routine(data, index);
}

void	odd_philo_routine(t_data *data, int index)
{
	while (data->death == 0)
	{
		philo_eats(data, index);
		data->victory += 1;
		philo_sleeps(data, index);
		philo_thinks(data, index);
	}
}
