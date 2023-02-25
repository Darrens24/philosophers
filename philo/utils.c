/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:40:44 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:20:39 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_usleep(long long time, t_data *data)
{
	long long	start;
	long long	end;

	start = timestamp(data);
	end = start + time;
	usleep(time * 1000 * 70 / 100);
	while (end - start > 0)
	{
		usleep(100);
		start = timestamp(data);
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		pthread_mutex_destroy(&data->forks_t[i]);
		pthread_mutex_destroy(&data->is_eating_t[i]);
	}
	pthread_mutex_destroy(&data->speaking_stick);
	free(data->philo);
	free(data->index);
	free(data->last_meal);
	free(data->actual_meal);
	free(data->philo_t);
	free(data->is_eating_t);
	free(data->victory);
	free(data->forks_t);
	free(data->deathwatcher_t);
	free(data);
}

long long	timestamp(t_data *data)
{
	long long		res;
	struct timeval	temp;

	res = 0;
	gettimeofday(&temp, NULL);
	res = ((temp.tv_sec * 1000 + temp.tv_usec / 1000)
			- (data->start.tv_sec * 1000 + data->start.tv_usec / 1000));
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoll(const char *str)
{
	long long	i;
	long long	minus;
	long long	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * minus);
}
