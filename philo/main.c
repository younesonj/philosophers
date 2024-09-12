#include "philo.h"


size_t  ft_time(void)
{
	struct timeval	tv;
    gettimeofday(&tv, NULL);
    size_t time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}

t_tracker *init_tracker(void)
{
    t_tracker *tracker = (t_tracker *)malloc(sizeof(t_tracker));
    if (!tracker)
        return (NULL);
    tracker->flag = 0;
    tracker->time = ft_time();
    return (tracker);
}




// void    ft_simulation(t_tracker **tracker, t_philo **philos, int ac, char **av)
// {
//     pthread_t           *threads = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
//     pthread_mutex_t     *forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));

//     int i = 0;
//     while ()
//     {}
// }

int main (int ac, char **av)
{
    (void)av;
    if (ac < 5 || ac > 6 || check_digit(av) || check_overflow(ac, av))
        return (write(1, "Error\n", 6), 1);
    t_tracker *tracker = init_tracker();
    if (!tracker)
        return (1);
    t_philo *philo;
    // ft_simulation(&tracker, philo, ac, av);



    return (0);
}