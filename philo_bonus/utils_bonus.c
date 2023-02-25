/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:11 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 10:41:21 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
