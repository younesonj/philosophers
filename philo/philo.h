#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef	struct s_fork t_fork;
typedef struct s_philo t_philo;

typedef struct t_data{
	//args form inputs
    int     nb_philo; //av[1] ✅
    int     time_to_die; //av[2] ✅
    int     time_to_eat; //av[3] ✅
    int     time_to_sleep; //av[4] ✅
    int     limit_meals; //  opt av[5] ✅

	// data
	//int eat;
	//size_t time;
	t_fork *forks; // ✅
	t_philo *philosophers; //✅

} t_data;


struct s_fork{
	int fork_id; //✅
	pthread_mutex_t fork; //✅
};


struct s_philo
{
	int				philo_id; //✅
	pthread_t		thread_id;
	size_t			time_last_meal;
	int				count_meals; //✅
	int				full; //✅
	t_data          *data; //✅
	t_fork			*first_fork; //✅
	t_fork			*second_fork; //✅
};



int     check_args(int ac, char **av);
int     setting_up(t_data *data, char **av, int ac);


#endif