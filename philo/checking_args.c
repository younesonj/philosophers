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
