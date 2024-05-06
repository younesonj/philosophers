#include "philo.h"

t_philo *setting_philos(t_data *data)
{
    t_philo *philos;
    int     i;

    philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
    if (!philos)
        return (NULL);
    i = 0;
    while (i < data->nb_philo)
    {
        philos[i].philo_id = i + 1;
        philos[i].data = data;
        i++;
    }


    return (philos);
}

int main (int ac, char **av)
{
    t_data      data;
    t_philo     *philos;


    if (check_args(ac, av) || setting_up(&data, av, ac))
        return (write (2, "Error\n", 6), 1);
    
    
    philos = setting_philos(&data);
    // printf("%d\n", data.nb_philo);
    // printf("%d\n", data.time_to_die);
    // printf("%d\n", data.time_to_eat);
    // printf("%d\n", data.time_to_sleep);
    // printf("%d", data.eating_nb);
    int i = 0;
    while (i < data.nb_philo)
    {
        printf("%d\n", philos[i].philo_id);
        i++;
    }

}
