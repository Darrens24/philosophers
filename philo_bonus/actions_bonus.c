/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:03:44 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 10:35:17 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eats(t_data *data, int index)
{
	sem_wait(data->sema_forks);
	sem_wait(data->sema_forks);
	sem_wait(data->sema_speaking);
	gettimeofday(&data->last_meal[index], NULL);
	printf("%lld %d has taken a fork\n", timestamp(data), index + 1);
	printf("%lld  %d has taken a fork\n", timestamp(data), index + 1);
	green();
	printf("%lld  %d is eating\n", timestamp(data), index + 1);
	reset();
	sem_post(data->sema_speaking);
	precise_usleep(data->eat_time, data);
	sem_post(data->sema_forks);
	sem_post(data->sema_forks);
}

void	philo_sleeps(t_data *data, int index)
{
	sem_wait(data->sema_speaking);
	cyan();
	printf("%lld  %d is sleeping\n", timestamp(data), index + 1);
	reset();
	sem_post(data->sema_speaking);
	precise_usleep(data->sleep_time, data);
}

void	philo_thinks(t_data *data, int index)
{
	sem_wait(data->sema_speaking);
	yellow();
	printf("%lld %d is thinking\n", timestamp(data), index + 1);
	reset();
	sem_post(data->sema_speaking);
}
