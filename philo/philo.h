#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


typedef struct t_data{
    int     nb_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eating_nb;
} t_data;


typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	//size_t			should_die;
	//int				eat_max;
	t_data          *data;
	//pthread_mutex_t	fork;
	//pthread_mutex_t	*next_fork;
}	t_philo;



int     check_args(int ac, char **av);
int     setting_up(t_data *data, char **av, int ac);


#endif