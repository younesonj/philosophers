/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:42:55 by younajja          #+#    #+#             */
/*   Updated: 2024/09/19 12:01:36 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct t_data
{
	size_t			time;
	int				flag;
	int				nb_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	check_died;

}					t_data;

typedef struct t_philo
{
	int				id;
	int				limit_meals;
	size_t			first_eat;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	eat_mutex;
	t_data			*data;
	struct t_philo	*next;
}					t_philo;

// PARSE
int					check_digit(char **strs);
int					check_overflow(int ac, char **av);
int					ft_atoi(char *str);

// UTILS
size_t				ft_time(void);
void				ft_usleep(size_t time, t_data *data);
int					ft_limit_meals(int ac, char **av);
int					ft_handle_cases(t_data *data);
void				ft_insert_philo(t_philo **philos, t_philo *curr);
int					ft_check_flag_mtx(t_data *data);
void				check_and_print(t_philo *philo, char *str);

// INIT
pthread_mutex_t		*ft_init_forks_and_philos(t_data **data, t_philo **philos,
						int limit);
t_data				*init_data(char **av);

// ROUTINE
void				*ft_routine_philo(void *arg);

#endif