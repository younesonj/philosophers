#include "philo.h"


void    *ft_routine_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (philo->data->limit_meals != 0)
    {
        // printf("philo id = %d\n", philo->id);
        // philo->data->limit_meals 
        printf("%d\n", philo->id);
        sleep(1);
    }
    
    return (NULL);
}

void    ft_simulation(t_data **data, t_philo **philos)
{
    pthread_mutex_t *forks;
    t_philo         *philo;
    pthread_t       *threads;
    int             i;

    if (ft_handle_cases(*data))
        return ;
    forks = ft_init_forks_and_philos(data, philos);
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
    i = 0;
    while (i < (*data)->nb_philos)
        pthread_join(threads[i++], NULL);
    
    

}

int main (int ac, char **av)
{
    t_data *data;
    t_philo *philo;

    if (ac < 5 || ac > 6 || check_digit(av) || check_overflow(ac, av))
        return (write(1, "Error\n", 6), 1);
    data = init_data(ac, av);
    if (!data)
        return (1);
    philo = NULL;
    ft_simulation(&data, &philo);

    // while (philo)
    // {
    //     printf("philo_id = %d , time to eat = %zu , limit meals = %d\n", philo->id , philo->data->time_to_eat, philo->data->limit_meals);
    //     philo = philo->next;
    // }
    
    return (0);
}