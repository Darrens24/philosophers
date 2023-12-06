/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:30 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/12 13:38:26 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_and_join_threads(t_data *data)
{
	int	i;

	odd_thread_creation(data);
	i = -1;
	while (++i < data->nb_of_philo)
		if (pthread_detach(data->philo_t[i]) != 0)
			return (printf("Thread philo detach failed\n"));
	return (0);
}

void	*philo_manager(void *arg)
{
	t_data		*data;
	static int	i = -1;
	int			index;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->race);
	i++;
	index = i;
	pthread_mutex_unlock(&data->race);
	if (index == 0)
		first_philo_routine(data, index);
	else
	{
		if (index % 2 != 0)
			usleep(300);
		odd_philo_routine(data, index);
	}
	return (EXIT_SUCCESS);
}

void	first_philo_routine(t_data *data, int index)
{
	while (data->death == 0)
	{
		first_philo_eats(data, index);
		pthread_mutex_lock(&data->race);
		if (data->death == 1)
			return ;
		pthread_mutex_unlock(&data->race);
		pthread_mutex_lock(&data->vic);
		data->victory[index] += 1;
		pthread_mutex_unlock(&data->vic);
		philo_sleeps(data, index);
		pthread_mutex_lock(&data->race);
		if (data->death == 1)
			return ;
		pthread_mutex_unlock(&data->race);
		philo_thinks(data, index);
	}
}

void	odd_philo_routine(t_data *data, int index)
{
	while (data->death == 0)
	{
		philo_eats(data, index);
		pthread_mutex_lock(&data->race);
		if (data->death == 1)
			return ;
		pthread_mutex_unlock(&data->race);
		pthread_mutex_lock(&data->vic);
		data->victory[index] += 1;
		pthread_mutex_unlock(&data->vic);
		philo_sleeps(data, index);
		pthread_mutex_lock(&data->race);
		if (data->death == 1)
			return ;
		pthread_mutex_unlock(&data->race);
		philo_thinks(data, index);
	}
}
