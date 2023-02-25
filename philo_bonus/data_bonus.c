/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:03:53 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 15:47:33 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_processes_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
		kill(data->philo_pid[i], SIGKILL);
	free(data->philo);
	free(data->philo_pid);
	free(data->last_meal);
	sem_unlink("Sem");
	sem_unlink("Speak");
	sem_unlink("Death");
	sem_close(data->sema_forks);
	sem_close(data->sema_speaking);
	sem_close(data->sema_death);
	free(data);
}

int	allocate_data(t_data *data)
{
	data->philo = malloc(sizeof(int) * data->nb_of_philo);
	if (!data->philo)
		return (printf("Philo_num: Memory allocation failed\n"));
	data->last_meal = malloc(sizeof(struct timeval) * data->nb_of_philo);
	if (!data->last_meal)
		return (printf("Last_meal_time: Memory allocation failed\n"));
	data->philo_pid = malloc(sizeof(int) * data->nb_of_philo);
	if (!data->philo_pid)
		return (printf("Pids: Memory allocation failed\n"));
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
		data->victory_meal = -5;
	allocate_data(data);
	gettimeofday(&data->start, NULL);
	i = -1;
	while (++i < data->nb_of_philo)
		gettimeofday(&data->last_meal[i], NULL);
	get_semaphores(data);
	data->death = 0;
	data->victory = 0;
	return (0);
}

int	get_semaphores(t_data *data)
{
	sem_unlink("Sem");
	sem_unlink("Speak");
	sem_unlink("Death");
	data->sema_forks = sem_open("Sem", O_CREAT, 0644, data->nb_of_philo);
	data->sema_speaking = sem_open("Speak", O_CREAT, 0644, 1);
	data->sema_death = sem_open("Death", O_CREAT, 0644, 1);
	return (0);
}
