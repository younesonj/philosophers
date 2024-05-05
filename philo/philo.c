#include "philo.h"

int main (int ac, char **av)
{
    t_data data;
    if (check_args(ac, av) || setting_up(&data, av, ac))
    {
        write (2, "Error\n", 6);
        return (1);
    }
    printf("%d\n", data.nb_philo);
    printf("%d\n", data.time_to_die);
    printf("%d\n", data.time_to_eat);
    printf("%d\n", data.time_to_sleep);
    printf("%d", data.eating_nb);



}