/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:30 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:26:30 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_and_join_threads(t_data *data)
{
	int	i;

	data->deathwatcher_t = malloc(sizeof(*data->deathwatcher_t));
	if (!data->deathwatcher_t)
		return (printf("Malloc deathwatch failed\n"));
	if (pthread_create((data->deathwatcher_t), NULL,
			&deathwatcher_job, data) != 0)
		return (printf("Thread deathwatch creation failed\n"));
	if (data->nb_of_philo % 2 != 0)
		odd_thread_creation(data);
	else if (data->nb_of_philo % 2 == 0)
		even_thread_creation(data);
	i = -1;
	while (++i < data->nb_of_philo)
		if (pthread_join(data->philo_t[i], NULL) != 0)
			return (printf("Thread philo join failed\n"));
	if (pthread_join(*(data->deathwatcher_t), NULL) != 0)
		return (printf("Thread deathwatch join failed\n"));
	return (0);
}

void	*philo_manager(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	data->philo[*(data->index)] = *(data->index);
	if (*(data->index) == 0)
		first_philo_routine(data, (data->philo[*(data->index)]));
	else
		odd_philo_routine(data, (data->philo[*(data->index)]));
	return (EXIT_SUCCESS);
}

void	first_philo_routine(t_data *data, int index)
{
	while (data->death == 0)
	{
		if (data->nb_of_philo == 1)
			return ;
		first_philo_eats(data, index);
		if (data->death == 1)
			return ;
		data->victory[index] += 1;
		philo_sleeps(data, index);
		if (data->death == 1)
			return ;
		philo_thinks(data, index);
	}
}

void	odd_philo_routine(t_data *data, int index)
{
	while (data->death == 0)
	{
		philo_eats(data, index);
		if (data->death == 1)
			return ;
		data->victory[index] += 1;
		philo_sleeps(data, index);
		if (data->death == 1)
			return ;
		philo_thinks(data, index);
	}
}
