#include "philo.h"

int check_digit(char **strs)
{
    int i = 1;
    while (strs[i])
    {
        int j = 0;
        while (strs[i][j])
        {
            if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if ((ac != 5 && ac != 6) || check_digit(av) == 1)
        return (1);
    return (0);
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;
    int prev = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        prev = res;
        res = res * 10 + str[i] - 48;
        if (prev != res / 10)
            return (0);
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
        data->limit_meals = ft_atoi(av[5]);

    if (data->nb_philo < 1 || data->time_to_die < 1 || data->time_to_eat < 1
        ||  data->time_to_sleep < 1 || data->limit_meals < 1)
        return (1);

    if (ac == 5)
        data->limit_meals = -1;
    return (0);
}