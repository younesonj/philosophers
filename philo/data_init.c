#include "philo.h"





int     initialization(t_data *data)
{
    data->philosophers = malloc(data->nb_philo * sizeof(t_philo));
    if (!data->philosophers)
        return (1);
    data->forks = malloc(data->nb_philo * sizeof(t_fork));
    if (!data->forks)
        return (1);
    data->end = NO;
    int i = 0;
    while (i < data->nb_philo)
    {
        pthread_mutex_init(&data->forks[i].fork, NULL);
        data->forks[i].fork_id = i;
        i++;
    }
    i = 0;
    while (i < data->nb_philo)
    {
        data->philosophers[i].philo_id = i + 1;
        data->philosophers[i].full = NO;
        data->philosophers[i].count_meals = 0;
        data->philosophers[i].data = data;
        if (data->philosophers[i].philo_id % 2 == 0)
        {
            data->philosophers[i].first_fork = &data->forks[i];
            data->philosophers[i].second_fork = &data->forks[(i + 1) % data->nb_philo];
        }
        else
        {
            data->philosophers[i].first_fork = &data->forks[(i + 1) % data->nb_philo];
            data->philosophers[i].second_fork = &data->forks[i];
        }
        // to avoid deadlock if philo id is odd the first fork is the second one
        // else if philo id is even the first fork is its own
        i++;
    }
    return (0);
}
