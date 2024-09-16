#include "philo.h"

size_t  ft_time(void)
{
	struct timeval	tv;
    gettimeofday(&tv, NULL);
    size_t time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}

void	ft_usleep(size_t time)
{
	size_t	diff;

	diff = ft_time();
	while (1)
	{
		if (ft_time() - diff >= time)
			break ;
		usleep(50);
	}
}

int ft_limit_meals(int ac, char **av)
{
    return (ac == 6 ? ft_atoi(av[5]) : -1);
}

int ft_handle_cases(t_data *data)
{
    if (data->nb_philos > 1)
        return (0);
    else if (data->nb_philos == 0)
        return (1);
	printf("0 1 has taken a fork\n");
	ft_usleep(data->time_to_die);
	printf("%zu 1 dead\n", data->time_to_die);
    return (1);
}

void    ft_insert_philo(t_philo **philos, t_philo *curr)
{
    t_philo *tmp;

    if (!(*philos))
    {
        *philos = curr;
        return;
    }
    tmp = *philos;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = curr;
}
