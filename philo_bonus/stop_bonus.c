/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:07 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:29:34 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*deathwatcher_job(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->death == 0)
	{
		usleep(100);
		if (check_is_dead(data, data->index))
		{
			print_failure_and_exit(data, data->index);
			exit(EXIT_FAILURE);
		}
		else if (check_is_victory(data) && data->victory_meal > 0)
		{
			print_success_and_exit(data);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}

int	check_is_dead(t_data *data, int index)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	if (((temp.tv_sec * 1000 + temp.tv_usec / 1000)
			- (data->last_meal[index].tv_sec * 1000
				+ data->last_meal[index].tv_usec / 1000)) > data->die_time)
		return (1);
	return (0);
}

int	check_is_victory(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (data->victory < data->victory_meal)
			return (0);
		i++;
	}
	return (1);
}

void	print_success_and_exit(t_data *data)
{
	sem_wait(data->sema_speaking);
	green();
	printf("%lld SUCCESS\n", timestamp(data));
	sem_post(data->sema_death);
	reset();
	exit(EXIT_SUCCESS);
}

void	print_failure_and_exit(t_data *data, int index)
{
	sem_wait(data->sema_speaking);
	red();
	printf("%lld %d died\n", timestamp(data), index + 1);
	sem_post(data->sema_death);
	reset();
	exit(EXIT_FAILURE);
}
