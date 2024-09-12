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

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int prev = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        prev = res;
        res = res * 10 + str[i] - 48;
        if (prev != res / 10)
            return (-1);
        i++;
    }
    return (res);
}

int check_overflow(int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        if (ft_atoi(av[i]) == -1)
            return (1);
        i++;
    }
    return (0);
}
