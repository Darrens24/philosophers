/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:18 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/12 16:07:22 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	norm_mutex(t_data *data, char mode)
{
	if (mode == 'l')
	{
		pthread_mutex_lock(&(data->speaking_stick));
		pthread_mutex_lock(&data->race);
	}
	else if (mode == 'u')
	{
		pthread_mutex_unlock(&data->race);
		pthread_mutex_unlock(&(data->speaking_stick));
	}
}

void	philo_eats(t_data *data, int index)
{
	pthread_mutex_lock(&(data->forks_t[index]));
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(WHT "%lld %d has taken a fork\n",
			timestamp(data), index + 1);
	norm_mutex(data, 'u');
	pthread_mutex_lock(&(data->forks_t[index - 1]));
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(WHT "%lld %d has taken a fork\n",
			timestamp(data), index + 1);
	norm_mutex(data, 'u');
	pthread_mutex_lock(&data->race);
	if (data->death == 1)
		return ;
	pthread_mutex_unlock(&data->race);
	gettimeofday(&data->last_meal[index], NULL);
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(MAG "%lld %d is eating\n" WHT, timestamp(data), index + 1);
	norm_mutex(data, 'u');
	precise_usleep(data->eat_time, data);
	pthread_mutex_unlock(&data->forks_t[index]);
	pthread_mutex_unlock(&data->forks_t[index - 1]);
}

void	first_philo_eats(t_data *data, int index)
{
	pthread_mutex_lock(&(data->forks_t[index]));
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(WHT "%lld %d has taken a fork\n",
			timestamp(data), index + 1);
	norm_mutex(data, 'u');
	pthread_mutex_lock(&(data->forks_t[data->nb_of_philo - 1]));
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(WHT "%lld %d has taken a fork\n",
			timestamp(data), index + 1);
	norm_mutex(data, 'u');
	pthread_mutex_lock(&data->race);
	if (data->death == 1)
		return ;
	pthread_mutex_unlock(&data->race);
	gettimeofday(&data->last_meal[index], NULL);
	norm_mutex(data, 'l');
	if (data->death == 0)
		printf(MAG "%lld %d is eating\n" WHT, timestamp(data), index + 1);
	norm_mutex(data, 'u');
	precise_usleep(data->eat_time, data);
	pthread_mutex_unlock(&data->forks_t[index]);
	pthread_mutex_unlock(&data->forks_t[data->nb_of_philo - 1]);
}

void	philo_sleeps(t_data *data, int index)
{
	pthread_mutex_lock(&data->race);
	if (data->death == 1)
		return ;
	pthread_mutex_unlock(&data->race);
	pthread_mutex_lock(&(data->speaking_stick));
	pthread_mutex_lock(&data->race);
	if (data->death == 0)
		printf(BLU "%lld %d is sleeping\n" WHT, timestamp(data), index + 1);
	pthread_mutex_unlock(&data->race);
	pthread_mutex_unlock(&(data->speaking_stick));
	precise_usleep(data->sleep_time, data);
}

void	philo_thinks(t_data *data, int index)
{
	pthread_mutex_lock(&data->race);
	if (data->death == 1)
		return ;
	pthread_mutex_unlock(&data->race);
	pthread_mutex_lock(&(data->speaking_stick));
	pthread_mutex_lock(&data->race);
	if (data->death == 0)
		printf(YEL "%lld %d is thinking\n" WHT, timestamp(data), index + 1);
	pthread_mutex_unlock(&data->race);
	pthread_mutex_unlock(&(data->speaking_stick));
}
