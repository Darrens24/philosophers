/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:38:01 by eleleux           #+#    #+#             */
/*   Updated: 2023/05/12 16:21:38 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

/***\	Struct	\***/

typedef struct s_data
{
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long long		victory_meal;
	int				nb_of_philo;
	int				*philo;
	int				index;
	pid_t			*philo_pid;
	pthread_t		*deathwatcher_t;
	sem_t			*sema_speaking;
	sem_t			*sema_forks;
	sem_t			*sema_death;
	sem_t			*sema_victory;
	struct timeval	start;
	struct timeval	current;
	struct timeval	*last_meal;
	int				death;
	long long		victory;
}				t_data;

/***\	Program		\***/

int			start_processes(t_data *data);
void		philo_manager(t_data *data, int index);
void		odd_philo_routine(t_data *data, int index);

/***\	Control		\***/

void		*deathwatcher_job(void *arg);
int			check_is_dead(t_data *data, int index);
int			check_is_victory(t_data *data);
void		print_success_and_exit(t_data *data);
void		print_failure_and_exit(t_data *data, int index);

/***\	Errors		\***/

int			check_errors(int ac, char **av);
int			check_number_of_philos(char **av);
int			check_positive_and_digits(int ac, char **av);

/***\	Data		\***/

int			get_data(t_data *data, char **av);
int			allocate_data(t_data *data);
int			get_semaphores(t_data *data);
void		kill_processes_free_data(t_data *data);

/***\	Actions		\***/

void		philo_eats(t_data *data, int index);
void		philo_sleeps(t_data *data, int index);
void		philo_thinks(t_data *data, int index);

/***\	Utils		\***/

void		precise_usleep(long long time, t_data *data);
int			ft_strlen(char *str);
long long	ft_atoll(const char *str);
long long	timestamp(t_data *data);

/***\	Colors		\***/

void		green(void);
void		cyan(void);
void		red(void);
void		yellow(void);
void		reset(void);

/***\	End			\***/

#endif
