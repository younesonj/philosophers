#include "philo.h"


int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * sign);
}

int setting_up(t_data *data, char **av, int ac)
{
    data->nb_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->eating_nb = ft_atoi(av[5]);
    if (data->nb_philo < 1 || data->time_to_die < 1 || data->time_to_eat < 1
        ||  data->time_to_sleep < 1 || data->eating_nb < 1)
        return (1);
    if (ac == 5)
        data->eating_nb = 0;
    return (0);
}