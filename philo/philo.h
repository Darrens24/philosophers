/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:31:27 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/26 13:06:14 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>

//	Structures	//

typedef struct s_data
{
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long long		victory_meal;
	int				nb_of_philo;
	int				*philo;
	int				*index;
	pthread_t		*philo_t;
	pthread_t		*deathwatcher_t;
	pthread_mutex_t	*forks_t;
	pthread_mutex_t	*is_eating_t;
	pthread_mutex_t	speaking_stick;
	int				*actual_meal;
	struct timeval	start;
	struct timeval	current;
	struct timeval	*last_meal;
	int				death;
	long long		*victory;
}				t_data;

/***\	Program		\***/

int			start_and_join_threads(t_data *data);
void		*philo_manager(void *arg);
void		first_philo_routine(t_data *data, int index);
void		odd_philo_routine(t_data *data, int index);

/***\	Control		\***/

void		*deathwatcher_job(void *arg);
int			check_is_dead(t_data *data, int index);
int			check_is_victory(t_data *data);
void		print_success_and_join(t_data *data);
void		print_failure_and_join(t_data *data, int index);

/***\	Errors		\***/

int			check_errors(int ac, char **av);
int			check_number_of_philos(char **av);
int			check_positive_and_digits(int ac, char **av);

/***\	Data		\***/

int			get_data(t_data *data, char **av);
int			allocate_data(t_data *data);
int			get_mutex(t_data *data);
int			odd_thread_creation(t_data *data);
int			even_thread_creation(t_data *data);

/***\	Actions		\***/

void		philo_eats(t_data *data, int index);
void		first_philo_eats(t_data *data, int index);
void		philo_sleeps(t_data *data, int index);
void		philo_thinks(t_data *data, int index);

/***\	Utils		\***/

int			ft_strlen(char *str);
long long	ft_atoll(const char *str);
long long	timestamp(t_data *data);
void		precise_usleep(long long time, t_data *data);
void		free_data(t_data *data);

/***\	Colors		\***/

void		green(void);
void		yellow(void);
void		cyan(void);
void		red(void);
void		reset(void);

/***\	End			\***/

#endif
