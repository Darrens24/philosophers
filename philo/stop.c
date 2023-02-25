/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:33 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:19:12 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*deathwatcher_job(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	while (data->death == 0)
	{
		usleep(120);
		i = 0;
		while (i < data->nb_of_philo && data->death == 0)
		{
			if (check_is_dead(data, i))
				print_failure_and_join(data, i);
			else if (data->victory_meal >= 0 && check_is_victory(data))
				print_success_and_join(data);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int	check_is_dead(t_data *data, int index)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	if (((temp.tv_sec * 1000 + temp.tv_usec / 1000)
			- (data->last_meal[index].tv_sec * 1000
				+ data->last_meal[index].tv_usec / 1000)) > (data->die_time)
		|| data->death == 1)
		return (1);
	return (0);
}

int	check_is_victory(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (data->victory[i] < data->victory_meal)
			return (0);
		i++;
	}
	return (1);
}

void	print_success_and_join(t_data *data)
{
	pthread_mutex_lock(&data->speaking_stick);
	data->death = 1;
	usleep(120);
	green();
	printf("%lld  SUCCESS\n", timestamp(data));
	reset();
	pthread_join(*(data->deathwatcher_t), NULL);
	pthread_mutex_unlock(&data->speaking_stick);
}

void	print_failure_and_join(t_data *data, int index)
{
	pthread_mutex_lock(&data->speaking_stick);
	data->death = 1;
	usleep(120);
	red();
	printf("%lld %d died\n", timestamp(data), data->philo[index] + 1);
	reset();
	pthread_join(*(data->deathwatcher_t), NULL);
	pthread_mutex_unlock(&data->speaking_stick);
}
