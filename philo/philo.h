#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>



typedef struct t_data{
	size_t				time;
	int					flag;
	int					nb_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	pthread_mutex_t		philo_done;
	pthread_mutex_t		check_died;

} t_data;



typedef struct t_philo{
	int					id;
	int					limit_meals;
	size_t				first_eat;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;
	pthread_mutex_t		eat_mutex;
	t_data				*data;
	struct t_philo		*next;
} t_philo;

// PARSE
int					check_digit(char **strs);
int					check_overflow(int ac, char **av);
int 				ft_atoi(char *str);

// UTILS
size_t  			ft_time(void);
void				ft_usleep(size_t time);
int 				ft_limit_meals(int ac, char **av);
int 				ft_handle_cases(t_data *data);
void    			ft_insert_philo(t_philo **philos, t_philo *curr);


// INIT
pthread_mutex_t 	*ft_init_forks_and_philos(t_data **data, t_philo **philos, int limit);
t_data 				*init_data(char **av);







#endif