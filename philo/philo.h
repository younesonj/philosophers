#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef	struct s_fork t_fork;
typedef struct s_philo t_philo;

# define YES 1
# define NO 0

typedef struct t_data{
	//args form inputs
    int     nb_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     limit_meals;


	size_t	time_start;
	int		end;


	t_fork *forks;
	t_philo *philosophers;

} t_data;



struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	size_t			time_last_meal;
	int				count_meals;
	int				full;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_data          *data;
};


struct s_fork{
	int 			fork_id;
	pthread_mutex_t fork;
};



int     check_args(int ac, char **av);
int     setting_up(t_data *data, char **av, int ac);
int     initialization(t_data *data);


#endif