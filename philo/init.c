#include "philo.h"


t_data *init_data(char **av)
{
    t_data *data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    pthread_mutex_init(&data->philo_done, NULL);
    pthread_mutex_init(&data->check_died, NULL);
    data->flag = 0;
    data->time = ft_time();
    data->nb_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    return (data);
}

t_philo *ft_init_philo(t_data **data, pthread_mutex_t *forks, int i)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->id = i + 1;
    philo->first_eat = ft_time();
    philo->next = NULL;
    philo->data = *data;
    philo->first_fork = &forks[i];
    philo->second_fork = &forks[(i + 1) % (*data)->nb_philos];
    pthread_mutex_init(&philo->eat_mutex, NULL);
    return (philo);
}



pthread_mutex_t *ft_init_forks_and_philos(t_data **data, t_philo **philos, int limit)
{
    pthread_mutex_t     *forks;
    t_philo             *curr;
    int                 i;

    forks = malloc(sizeof(pthread_mutex_t) * (*data)->nb_philos);
    if (!forks)
        return (NULL);
    i = 0;
    while (i < (*data)->nb_philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        curr = ft_init_philo(data, forks, i);
        if (!curr)
            return (NULL);
        curr->limit_meals = limit;
        ft_insert_philo(philos, curr);
        i++;
    }
    return (forks);
}


