#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>



typedef struct t_tracker{
	size_t	time;
	int		flag;
} t_tracker;



typedef struct t_philo{
	int		id;
	int		nb_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_sleep;

} t_philo;

// PARSE
int			check_digit(char **strs);
int			check_overflow(int ac, char **av);
int 		ft_atoi(char *str);








#endif