#ifndef PHILO_H
# define PHILO_H

typedef struct t_data{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int eating_nb;
} t_data;

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int     check_args(int ac, char **av);
int     setting_up(t_data *data, char **av, int ac);


#endif