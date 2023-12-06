/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:33 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/12 16:10:49 by eleleux          ###   ########.fr       */
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
	int	race_nb_philo;
	int	*race_victory;
	int	race_meal;

	i = -1;
	pthread_mutex_lock(&data->vic);
	race_nb_philo = data->nb_of_philo;
	race_victory = malloc(sizeof(int) * race_nb_philo);
	while (++i < race_nb_philo)
		race_victory[i] = data->victory[i];
	race_meal = data->victory_meal;
	pthread_mutex_unlock(&data->vic);
	i = 0;
	while (i < race_nb_philo)
	{
		if (race_victory[i] < race_meal)
		{
			free(race_victory);
			return (0);
		}
		i++;
	}
	free(race_victory);
	return (1);
}

void	print_success_and_join(t_data *data)
{
	pthread_mutex_lock(&data->speaking_stick);
	pthread_mutex_lock(&data->race);
	data->death = 1;
	pthread_mutex_unlock(&data->race);
	usleep(300);
	green();
	printf(GRN "%lld  SUCCESS\n" WHT, timestamp(data));
	reset();
	pthread_mutex_unlock(&data->speaking_stick);
}

void	print_failure_and_join(t_data *data, int index)
{
	pthread_mutex_lock(&data->speaking_stick);
	pthread_mutex_lock(&data->race);
	data->death = 1;
	pthread_mutex_unlock(&data->race);
	usleep(300);
	printf(RED "%lld %d died\n" WHT, timestamp(data), index + 1);
	pthread_mutex_unlock(&data->speaking_stick);
}
