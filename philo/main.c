#include "philo.h"

int ft_check_flag_mtx(t_philo *philo)
{
    int res;

    pthread_mutex_lock(&philo->data->check_died);
    res = philo->data->flag;
    pthread_mutex_unlock(&philo->data->check_died);
    return (res);
}

void    check_and_print(t_philo *philo, char *str)
{
    if (ft_check_flag_mtx(philo))
        return ;
    printf("%zu %d %s\n", ft_time() - philo->data->time, philo->id, str);
}




void    ft_takes_forks(t_philo *philo)
{
    if (philo->id % 2)
    {
        pthread_mutex_lock(philo->first_fork);
        check_and_print(philo, "has taken a fork");
        pthread_mutex_lock(philo->second_fork);
        check_and_print(philo, "has taken a fork");
        return ;
    }
    pthread_mutex_lock(philo->second_fork);
    check_and_print(philo, "has taken a fork");
    pthread_mutex_lock(philo->first_fork);
    check_and_print(philo, "has taken a fork");
}

void    ft_eat(t_philo **philo)
{
    check_and_print(*philo, "is eating");
    pthread_mutex_lock(&(*philo)->eat_mutex);
    (*philo)->first_eat = ft_time();
    pthread_mutex_unlock(&(*philo)->eat_mutex);
    ft_usleep((*philo)->data->time_to_eat);
}

void    ft_sleeping(t_philo *philo)
{
    check_and_print(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
    check_and_print(philo, "is thinking");
}

void    *ft_routine_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (philo->limit_meals != 0 && !ft_check_flag_mtx(philo))
    {
        ft_takes_forks(philo);
        ft_eat(&philo);
        pthread_mutex_unlock(philo->first_fork);
        pthread_mutex_unlock(philo->second_fork);
        ft_sleeping(philo);
        usleep(200);
        philo->limit_meals--;
    }
    pthread_mutex_lock(&philo->data->check_died);
    philo->data->flag = 1;
    pthread_mutex_unlock(&philo->data->check_died);
    return (NULL);
}

void    *ft_routine_monitor(void *arg)
{
    t_philo *philo;
    t_philo *curr;
    int     time;

    time = 0;
    philo = (t_philo *)arg;
    curr = philo;
    while (!ft_check_flag_mtx(philo))
    {
        pthread_mutex_lock(&philo->eat_mutex);
        if (ft_time() - curr->first_eat > curr->data->time_to_die)
        {
            pthread_mutex_lock(&curr->data->check_died);
            philo->data->flag = 1;
            time = ft_time() - philo->data->time;
            pthread_mutex_unlock(&curr->data->check_died);
            usleep(1000);
            printf("%d %d is died\n", time, philo->id);
        }
        pthread_mutex_unlock(&philo->eat_mutex);
        curr = curr->next;
        if (!curr)
            curr = philo;
    }
    return (NULL);
}

void    ft_simulation(t_data **data, t_philo **philos, int limit)
{
    pthread_mutex_t *forks;
    t_philo         *philo;
    pthread_t       *threads;
    pthread_t       tracker;
    int             i;

    if (ft_handle_cases(*data))
        return ;
    forks = ft_init_forks_and_philos(data, philos, limit);
    if (!forks)
        return ;
    philo = *philos;
    threads = malloc(sizeof(pthread_t) * (*data)->nb_philos);
    i = 0;
    while (philo)
    {
        pthread_create(&threads[i++], NULL, ft_routine_philo, (void *)philo);
        philo = philo->next;
    }
	pthread_create(&tracker, NULL, ft_routine_monitor, (void *)*philos);
    i = 0;
    while (i < (*data)->nb_philos)
        pthread_join(threads[i++], NULL);
    pthread_join(tracker, NULL);
    
}

int main (int ac, char **av)
{
    t_data *data;
    t_philo *philo;
    int     limit_meals;

    if (ac < 5 || ac > 6 || check_digit(av) || check_overflow(ac, av))
        return (write(1, "Error\n", 6), 1);
    data = init_data(av);
    limit_meals = ft_limit_meals(ac, av);
    if (!data)
        return (1);
    philo = NULL;
    ft_simulation(&data, &philo, limit_meals);

    // while (philo)
    // {
    //     printf("philo_id = %d , time to eat = %zu , limit meals = %d\n", philo->id , philo->data->time_to_eat, philo->data->limit_meals);
    //     philo = philo->next;
    // }
    return (0);
}