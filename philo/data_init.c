#include "philo.h"


int data_init(t_data *data)
{
    data->philosophers = malloc(data->nb_philo * sizeof(t_philo));
    if (!data->philosophers)
        return (1);
    data->forks = malloc(data->nb_philo * sizeof(t_fork));
    if (!data->forks)
        return (1);
    
    pthread_mutex_init(&data->data_mutex ,NULL);
    pthread_mutex_init(&data->write_mutex ,NULL);


    data->all_phl_crt = 1;
    data->end = 1;

    int i = 0;
    while (i < data->nb_philo)
    {
        pthread_mutex_init(&data->forks[i].fork, NULL);
        data->forks[i].fork_id = i + 1;
        i++;
    }
    return (0);
}


int setting_philos(t_data *data)
{
    int     i;
    //data->time = get_time();

    i = 0;
    while (i < data->nb_philo)
    {
        data->philosophers[i].philo_id = i + 1;
        data->philosophers[i].data = data;
        data->philosophers[i].full = 1;
        data->philosophers[i].count_meals = 0;

        if (i % 2 == 0)
        {
            data->philosophers[i].first_fork = &data->forks[i];
            data->philosophers[i].second_fork = &data->forks[(i + 1) % data->nb_philo];
        }
        else
        {
            data->philosophers[i].first_fork = &data->forks[(i + 1) % data->nb_philo];
            data->philosophers[i].second_fork = &data->forks[i];
        }

        i++;
    }


    return (0);
}
