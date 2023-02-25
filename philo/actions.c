/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:18 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:26:01 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_data *data, int index)
{
	pthread_mutex_lock(&(data->is_eating_t[index - 1]));
	pthread_mutex_lock(&(data->forks_t[index]));
	pthread_mutex_lock(&(data->forks_t[index - 1]));
	usleep(120);
	if (data->death == 1)
		return ;
	pthread_mutex_lock(&(data->speaking_stick));
	gettimeofday(&data->last_meal[index], NULL);
	printf("%lld %d has taken a fork\n",
		timestamp(data), data->philo[index] + 1);
	printf("%lld %d has taken a fork\n",
		timestamp(data), data->philo[index] + 1);
	green();
	printf("%lld %d is eating\n", timestamp(data), data->philo[index] + 1);
	reset();
	pthread_mutex_unlock(&(data->speaking_stick));
	precise_usleep(data->eat_time, data);
	pthread_mutex_unlock(&data->forks_t[index]);
	pthread_mutex_unlock(&data->forks_t[index - 1]);
	pthread_mutex_unlock(&(data->is_eating_t[index - 1]));
}

void	first_philo_eats(t_data *data, int index)
{
	pthread_mutex_lock(&(data->is_eating_t[index]));
	pthread_mutex_lock(&(data->forks_t[index]));
	pthread_mutex_lock(&(data->forks_t[data->nb_of_philo - 1]));
	usleep(120);
	if (data->death == 1)
		return ;
	pthread_mutex_lock(&(data->speaking_stick));
	gettimeofday(&data->last_meal[index], NULL);
	printf("%lld %d has taken a fork\n",
		timestamp(data), data->philo[index] + 1);
	printf("%lld %d has taken a fork\n",
		timestamp(data), data->philo[index] + 1);
	green();
	printf("%lld %d is eating\n", timestamp(data), data->philo[index] + 1);
	reset();
	pthread_mutex_unlock(&(data->speaking_stick));
	precise_usleep(data->eat_time, data);
	pthread_mutex_unlock(&data->forks_t[index]);
	pthread_mutex_unlock(&data->forks_t[data->nb_of_philo - 1]);
	pthread_mutex_unlock(&(data->is_eating_t[index]));
}

void	philo_sleeps(t_data *data, int index)
{
	usleep(120);
	if (data->death == 1)
		return ;
	pthread_mutex_lock(&(data->speaking_stick));
	cyan();
	printf("%lld %d is sleeping\n", timestamp(data), data->philo[index] + 1);
	reset();
	pthread_mutex_unlock(&(data->speaking_stick));
	precise_usleep(data->sleep_time, data);
}

void	philo_thinks(t_data *data, int index)
{
	usleep(120);
	if (data->death == 1)
		return ;
	pthread_mutex_lock(&(data->speaking_stick));
	yellow();
	printf("%lld %d is thinking\n", timestamp(data), data->philo[index] + 1);
	reset();
	pthread_mutex_unlock(&(data->speaking_stick));
}
