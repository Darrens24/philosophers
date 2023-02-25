/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:32 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:21:14 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate_data(t_data *data)
{
	data->philo = malloc(sizeof(int) * data->nb_of_philo);
	if (!data->philo)
		return (printf("Philo_num: Memory allocation failed\n"));
	data->index = malloc(sizeof(int) * data->nb_of_philo);
	if (!data->index)
		return (printf("Philo_index: Memory allocation failed\n"));
	data->last_meal = malloc(sizeof(struct timeval) * data->nb_of_philo);
	if (!data->last_meal)
		return (printf("Last_meal_time: Memory allocation failed\n"));
	data->philo_t = malloc(sizeof(*data->philo_t) * data->nb_of_philo);
	if (!data->philo_t)
		return (printf("Philo_thread: Memory allocation failed\n"));
	data->actual_meal = malloc(sizeof(int) * data->nb_of_philo);
	if (!data->actual_meal)
		return (printf("Actual_meal: Memory allocation failed\n"));
	data->victory = malloc(sizeof(long long) * data->nb_of_philo);
	if (!data->victory)
		return (printf("Victory: Memory allocation failed\n"));
	memset(data->victory, 0, sizeof(long long) * data->nb_of_philo);
	return (0);
}

int	get_data(t_data *data, char **av)
{
	int	i;

	data->nb_of_philo = ft_atoll(av[1]);
	data->die_time = ft_atoll(av[2]);
	data->eat_time = ft_atoll(av[3]);
	data->sleep_time = ft_atoll(av[4]);
	if (av[5])
		data->victory_meal = ft_atoll(av[5]);
	else
		data->victory_meal = -1;
	allocate_data(data);
	get_mutex(data);
	data->death = 0;
	i = -1;
	while (++i < data->nb_of_philo)
		data->victory[i] = 0;
	gettimeofday(&data->start, NULL);
	i = -1;
	while (++i < data->nb_of_philo)
		gettimeofday(&data->last_meal[i], NULL);
	return (0);
}

int	get_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->speaking_stick, NULL);
	data->forks_t = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->forks_t)
		return (printf("Forks: Memory allocation failed\n"));
	i = -1;
	while (++i < data->nb_of_philo)
		pthread_mutex_init(&(data->forks_t[i]), NULL);
	data->is_eating_t = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->is_eating_t)
		return (printf("Eatmutex: Memory allocation failed\n"));
	i = -1;
	while (++i < data->nb_of_philo)
		pthread_mutex_init(&(data->is_eating_t[i]), NULL);
	return (0);
}

int	odd_thread_creation(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		*(data->index) = i;
		if (pthread_create(&(data->philo_t[i]), NULL,
				&philo_manager, data) != 0)
			return (printf("Thread philo creation failed\n"));
		usleep(12);
	}
	return (0);
}

int	even_thread_creation(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		*(data->index) = i;
		if (pthread_create(&(data->philo_t[i]), NULL,
				&philo_manager, data) != 0)
			return (printf("Thread philo creation failed\n"));
		usleep(12);
	}
	return (0);
}
