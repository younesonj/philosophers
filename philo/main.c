#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}


int data_init(t_data *data)
{
    data->philosophers = malloc(data->nb_philo * sizeof(t_philo));
    if (!data->philosophers)
        return (1);
    data->forks = malloc(data->nb_philo * sizeof(t_fork));
    if (!data->forks)
        return (1);

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
        data->philosophers[i].full = 0;
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

int main (int ac, char **av)
{
    t_data      data;

    if (check_args(ac, av) || setting_up(&data, av, ac)
        || data_init(&data))
        return (write (2, "Error\n", 6), 1);
    

}